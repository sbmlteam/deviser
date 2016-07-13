/**
 * @file SedErrorTable.h
 * @brief Definition of the SedErrorTable class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
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
    "An SEDML XML file must use UTF-8 as the character encoding. More "
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
    "An SEDML XML document must not contain undefined elements or attributes "
    "in the SEDML namespace. Documents containing unknown elements or "
    "attributes placed in the SEDML namespace do not conform to the SEDML "
    "specification.",  
    {""
    }
  },

  //10003
  {
    NotSchemaConformant,
    "Document does not conform to the SEDML XML schema",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "An SEDML XML document must conform to the XML Schema for the corresponding "
    "SEDML Level, Version and Release. The XML Schema for SEDML defines the "
    "basic SEDML object structure, the data types used by those objects, and the "
    "order in which the objects may appear in an SEDML document.",
    {""
    }
  },

  //10201
  {
    InvalidMathElement,
    "Invalid MathML",
    LIBSEDML_CAT_MATHML_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "All MathML content in SEDML must appear within a <math> element, and the "
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
    "The SEDML XML namespace cannot be used in an Annotation object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any SEDML "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    MultipleAnnotations,
    "Only one Annotation object is permitted under a given SEDML object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given SEDML object may contain at most one <annotation> element.",
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

  //10804
  {
    InvalidNotesContent,
    "Invalid notes content",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    OnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given SEDML object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given SEDML object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  SEDML specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { SedmlNSUndeclared,
    "The Sedml namespace is not correctly declared.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
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

  // 10303
  { InvalidMetaidSyntax,
    "Invalid SId syntax",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:metaid' must conform to the syntax of the XML Type "
    "ID",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20101
  { InvalidNamespaceOnSed,
    "Invalid namespace",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Invalid namespace declared.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20102
  { AllowedAttributes,
    "Allowed attributes",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Allowed attributes",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20103
  { EmptyListElement,
    "No empty listOf",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "No empty lists",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20201
  { SedmlSedDocumentAllowedCoreAttributes,
    "Core attributes allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
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
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
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
    "<listOfModels> element. No other elements from the SBML Level 3 SEDML "
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
  { SedmlSedDocumentLOModelsAllowedCoreElements,
    "Core elements allowed on <listOfModels>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfModels> container object may only contain <model> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20209
  { SedmlSedDocumentLOModelsAllowedCoreAttributes,
    "Core attributes allowed on <listOfModels>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfModels> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfModels> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20301
  { SedmlSedModelAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <model>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20302
  { SedmlSedModelAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <model>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20303
  { SedmlSedModelAllowedAttributes,
    "Attributes allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object must have the required attributes 'sedml:id' and "
    "'sedml:source', and may have the optional attributes 'sedml:name' and "
    "'sedml:language'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <model> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20304
  { SedmlSedModelAllowedElements,
    "Elements allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object may contain one and only one instance of the "
    "<listOfChanges> element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <model> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20305
  { SedmlSedModelSourceMustBeString,
    "Source attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20306
  { SedmlSedModelNameMustBeString,
    "Name attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20307
  { SedmlSedModelLanguageMustBeString,
    "Language attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:language' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20308
  { SedmlSedModelEmptyLOElements,
    "No Empty ListOf elements allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfChanges> subobject on a <model> object is optional, but if "
    "present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20309
  { SedmlSedModelLOChangesAllowedCoreElements,
    "Core elements allowed on <listOfChanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfChanges> container object may only contain <change> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20310
  { SedmlSedModelLOChangesAllowedCoreAttributes,
    "Core attributes allowed on <listOfChanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfChanges> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfChanges> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20401
  { SedmlSedChangeAllowedCoreAttributes,
    "Core attributes allowed on <change>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <change> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <change>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20402
  { SedmlSedChangeAllowedCoreElements,
    "Core elements allowed on <change>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <change> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <change>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20501
  { SedmlSedAddXMLAllowedCoreAttributes,
    "Core attributes allowed on <addXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <addXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <addXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20502
  { SedmlSedAddXMLAllowedCoreElements,
    "Core elements allowed on <addXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <addXML> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <addXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20503
  { SedmlSedAddXMLAllowedElements,
    "Elements allowed on <addXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <addXML> object must contain one and only one instance of the XMLNode "
    "element. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on an <addXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20601
  { SedmlSedSetValueAllowedCoreAttributes,
    "Core attributes allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <setValue>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20602
  { SedmlSedSetValueAllowedCoreElements,
    "Core elements allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <setValue>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20603
  { SedmlSedSetValueAllowedAttributes,
    "Attributes allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object must have the required attribute "
    "'sedml:modelReference', and may have the optional attributes "
    "'sedml:symbol', 'sedml:target' and 'sedml:range'. No other attributes from "
    "the SBML Level 3 SEDML namespaces are permitted on a <setValue> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20604
  { SedmlSedSetValueAllowedElements,
    "Elements allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object may contain one and only one instance of the ASTNode "
    "element. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on a <setValue> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20605
  { SedmlSedSetValueModelReferenceMustBeModel,
    "ModelReference attribute must be Model.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <setValue> object "
    "must be the identifier of an existing <model> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20606
  { SedmlSedSetValueSymbolMustBeString,
    "Symbol attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbol' on a <setValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20607
  { SedmlSedSetValueTargetMustBeString,
    "Target attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <setValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20608
  { SedmlSedSetValueRangeMustBeRange,
    "Range attribute must be Range.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <setValue> object must be "
    "the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20701
  { SedmlSedDataGeneratorAllowedCoreAttributes,
    "Core attributes allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <dataGenerator>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20702
  { SedmlSedDataGeneratorAllowedCoreElements,
    "Core elements allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <dataGenerator>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20703
  { SedmlSedDataGeneratorAllowedAttributes,
    "Attributes allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object must have the required attribute 'sedml:id', and "
    "may have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on a <dataGenerator> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20704
  { SedmlSedDataGeneratorAllowedElements,
    "Elements allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object may contain one and only one instance of each of "
    "the <listOfVariables,> <listOfParameters> and ASTNode elements. No other "
    "elements from the SBML Level 3 SEDML namespaces are permitted on a "
    "<dataGenerator> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20705
  { SedmlSedDataGeneratorNameMustBeString,
    "Name attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataGenerator> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20706
  { SedmlSedDataGeneratorEmptyLOElements,
    "No Empty ListOf elements allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfVariables> and <sedListOfParameters> subobjects on a "
    "<dataGenerator> object are optional, but if present, these container "
    "objects must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20707
  { SedmlSedDataGeneratorLOVariablesAllowedCoreElements,
    "Core elements allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfVariables> container object may only contain "
    "<variable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20708
  { SedmlSedDataGeneratorLOParametersAllowedCoreElements,
    "Core elements allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfParameters> container object may only contain "
    "<parameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20709
  { SedmlSedDataGeneratorLOVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20710
  { SedmlSedDataGeneratorLOParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20801
  { SedmlSedRepeatedTaskAllowedCoreAttributes,
    "Core attributes allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <repeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20802
  { SedmlSedRepeatedTaskAllowedCoreElements,
    "Core elements allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <repeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20803
  { SedmlSedRepeatedTaskAllowedAttributes,
    "Attributes allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may have the optional attributes 'sedml:rangeId' "
    "and 'sedml:resetModel'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <repeatedTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20804
  { SedmlSedRepeatedTaskRangeIdMustBeRange,
    "RangeId attribute must be Range.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:rangeId' of a <repeatedTask> object must "
    "be the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20805
  { SedmlSedRepeatedTaskResetModelMustBeBoolean,
    "ResetModel attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:resetModel' on a <repeatedTask> must have a value of "
    "data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20901
  { SedmlSedSimulationAllowedCoreAttributes,
    "Core attributes allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <simulation>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20902
  { SedmlSedSimulationAllowedCoreElements,
    "Core elements allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <simulation>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20903
  { SedmlSedSimulationAllowedAttributes,
    "Attributes allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object must have the required attribute 'sedml:id', and may "
    "have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on a <simulation> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20904
  { SedmlSedSimulationAllowedElements,
    "Elements allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object may contain one and only one instance of the "
    "SedAlgorithm element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <simulation> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20905
  { SedmlSedSimulationNameMustBeString,
    "Name attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <simulation> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21001
  { SedmlSedVectorRangeAllowedCoreAttributes,
    "Core attributes allowed on <vectorRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <vectorRange> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <vectorRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21002
  { SedmlSedVectorRangeAllowedCoreElements,
    "Core elements allowed on <vectorRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <vectorRange> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <vectorRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21003
  { SedmlSedVectorRangeAllowedAttributes,
    "Attributes allowed on <vectorRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <vectorRange> object may have the optional attribute 'sedml:value'. No "
    "other attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<vectorRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21004
  { SedmlSedVectorRangeValueMustBeString,
    "Value attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
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
    LIBSEDML_CAT_INTERNAL,
    LIBSEDML_SEV_ERROR,
    "An unknown attribute has been found.", 
    {""
    }
   },

  //99999
  {
    SedCodesUpperBound,
    "Upper boundary of libSEDML-specific diagnostic codes",
    LIBSEDML_CAT_INTERNAL,
    LIBSEDML_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {""
    }
   }
};

LIBSEDML_CPP_NAMESPACE_END
/** @endcond */



#endif /* !SedErrorTable_H__ */

