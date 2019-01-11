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

 * Copyright (c) 2013-2019, Frank T. Bergmann
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
  { SedUnknown,
    "Encountered unknown internal libSEDML error",
    LIBSEDML_CAT_INTERNAL, 
    LIBSEDML_SEV_FATAL,
    "Unrecognized error encountered by libSEDML",
    {"",
    }
  },

  //10001
  {
    SedNotUTF8,
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
    SedUnrecognizedElement,
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
    SedNotSchemaConformant,
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
    SedInvalidMathElement,
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
    SedMissingAnnotationNamespace,
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
    SedDuplicateAnnotationNamespaces,
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
    SedMultipleAnnotations,
    "Only one Annotation object is permitted under a given SEDML object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given SEDML object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    SedNotesNotInXHTMLNamespace,
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
    SedNotesContainsXMLDecl,
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
    SedNotesContainsDOCTYPE,
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
    SedInvalidNotesContent,
    "Invalid notes content",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    SedOnlyOneNotesElementAllowed,
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
  { SedInvalidMetaidSyntax,
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
  { SedEmptyListElement,
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
    "A <sedDocument> object may contain one and only one instance of each of "
    "the <listOfSimulations,> <listOfModels,> <listOfAbstractTasks,> "
    "<listOfDataGenerators,> <listOfOutputs> and <listOfDataDescriptions> "
    "elements. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on a <sedDocument> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20205
  { SedmlSedDocumentLevelMustBeInteger,
    "The 'level' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:level' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20206
  { SedmlSedDocumentVersionMustBeInteger,
    "The 'version' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:version' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20207
  { SedmlSedDocumentLOSimulationsAllowedCoreElements,
    "Core elements allowed on <listOfSimulations>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSimulations> container object may only contain "
    "<simulation> objects.",
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
  { SedmlSedDocumentLOAbstractTasksAllowedCoreElements,
    "Core elements allowed on <listOfAbstractTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAbstractTasks> container object may only contain "
    "<abstractTask> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20210
  { SedmlSedDocumentLODataGeneratorsAllowedCoreElements,
    "Core elements allowed on <listOfDataGenerators>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataGenerators> container object may only contain "
    "<dataGenerator> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20211
  { SedmlSedDocumentLOOutputsAllowedCoreElements,
    "Core elements allowed on <listOfOutputs>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfOutputs> container object may only contain <output> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20212
  { SedmlSedDocumentLODataDescriptionsAllowedCoreElements,
    "Core elements allowed on <listOfDataDescriptions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataDescriptions> container object may only contain "
    "<dataDescription> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20213
  { SedmlSedDocumentLOSimulationsAllowedCoreAttributes,
    "Core attributes allowed on <listOfSimulations>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSimulations> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSimulations> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20214
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

  // 20215
  { SedmlSedDocumentLOAbstractTasksAllowedCoreAttributes,
    "Core attributes allowed on <listOfAbstractTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAbstractTasks> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfAbstractTasks> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20216
  { SedmlSedDocumentLODataGeneratorsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataGenerators>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataGenerators> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataGenerators> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20217
  { SedmlSedDocumentLOOutputsAllowedCoreAttributes,
    "Core attributes allowed on <listOfOutputs>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfOutputs> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfOutputs> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20218
  { SedmlSedDocumentLODataDescriptionsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataDescriptions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataDescriptions> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataDescriptions> object.",
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
    "The 'source' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20306
  { SedmlSedModelNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20307
  { SedmlSedModelLanguageMustBeString,
    "The 'language' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:language' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20308
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

  // 20309
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

  // 20403
  { SedmlSedChangeAllowedAttributes,
    "Attributes allowed on <change>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <change> object must have the required attribute 'sedml:target'. No "
    "other attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<change> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20404
  { SedmlSedChangeTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <change> must have a value of data type "
    "'string'.",
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
  { SedmlSedChangeAttributeAllowedCoreAttributes,
    "Core attributes allowed on <changeAttribute>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeAttribute> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <changeAttribute>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20602
  { SedmlSedChangeAttributeAllowedCoreElements,
    "Core elements allowed on <changeAttribute>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeAttribute> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <changeAttribute>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20603
  { SedmlSedChangeAttributeAllowedAttributes,
    "Attributes allowed on <changeAttribute>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeAttribute> object must have the required attribute "
    "'sedml:newValue'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <changeAttribute> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20604
  { SedmlSedChangeAttributeNewValueMustBeString,
    "The 'newValue' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:newValue' on a <changeAttribute> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20701
  { SedmlSedVariableAllowedCoreAttributes,
    "Core attributes allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <variable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20702
  { SedmlSedVariableAllowedCoreElements,
    "Core elements allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <variable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20703
  { SedmlSedVariableAllowedAttributes,
    "Attributes allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object must have the required attribute 'sedml:id', and may "
    "have the optional attributes 'sedml:name', 'sedml:symbol', 'sedml:target', "
    "'sedml:taskReference' and 'sedml:modelReference'. No other attributes from "
    "the SBML Level 3 SEDML namespaces are permitted on a <variable> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20704
  { SedmlSedVariableAllowedElements,
    "Elements allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object may contain one and only one instance of the "
    "<listOfRemainingDimensions> element. No other elements from the SBML Level "
    "3 SEDML namespaces are permitted on a <variable> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20705
  { SedmlSedVariableNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <variable> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20706
  { SedmlSedVariableSymbolMustBeString,
    "The 'symbol' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbol' on a <variable> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20707
  { SedmlSedVariableTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <variable> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20708
  { SedmlSedVariableTaskReferenceMustBeTask,
    "The attribute 'taskReference' must point to Task object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:taskReference' of a <variable> object "
    "must be the identifier of an existing <task> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20709
  { SedmlSedVariableModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <variable> object "
    "must be the identifier of an existing <model> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20710
  { SedmlSedVariableLORemainingDimensionsAllowedCoreElements,
    "Core elements allowed on <listOfRemainingDimensions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfRemainingDimensions> container object may only "
    "contain <remainingDimension> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20711
  { SedmlSedVariableLORemainingDimensionsAllowedCoreAttributes,
    "Core attributes allowed on <listOfRemainingDimensions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfRemainingDimensions> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfRemainingDimensions> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20801
  { SedmlSedParameterAllowedCoreAttributes,
    "Core attributes allowed on <parameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameter> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <parameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20802
  { SedmlSedParameterAllowedCoreElements,
    "Core elements allowed on <parameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameter> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <parameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20803
  { SedmlSedParameterAllowedAttributes,
    "Attributes allowed on <parameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameter> object must have the required attributes 'sedml:id' and "
    "'sedml:value', and may have the optional attribute 'sedml:name'. No other "
    "attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<parameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20804
  { SedmlSedParameterValueMustBeDouble,
    "The 'value' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:value' on a <parameter> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20805
  { SedmlSedParameterNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <parameter> must have a value of data type "
    "'string'.",
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
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <simulation> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21001
  { SedmlSedUniformTimeCourseAllowedCoreAttributes,
    "Core attributes allowed on <uniformTimeCourse>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformTimeCourse> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <uniformTimeCourse>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21002
  { SedmlSedUniformTimeCourseAllowedCoreElements,
    "Core elements allowed on <uniformTimeCourse>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformTimeCourse> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <uniformTimeCourse>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21003
  { SedmlSedUniformTimeCourseAllowedAttributes,
    "Attributes allowed on <uniformTimeCourse>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformTimeCourse> object must have the required attributes "
    "'sedml:initialTime', 'sedml:outputStartTime' and 'sedml:outputEndTime', "
    "and may have the optional attributes 'sedml:numberOfPoints' and "
    "'sedml:numberOfSteps'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on an <uniformTimeCourse> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21004
  { SedmlSedUniformTimeCourseInitialTimeMustBeDouble,
    "The 'initialTime' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:initialTime' on an <uniformTimeCourse> must have a "
    "value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21005
  { SedmlSedUniformTimeCourseOutputStartTimeMustBeDouble,
    "The 'outputStartTime' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:outputStartTime' on an <uniformTimeCourse> must have "
    "a value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21006
  { SedmlSedUniformTimeCourseOutputEndTimeMustBeDouble,
    "The 'outputEndTime' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:outputEndTime' on an <uniformTimeCourse> must have a "
    "value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21007
  { SedmlSedUniformTimeCourseNumberOfPointsMustBeInteger,
    "The 'numberOfPoints' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numberOfPoints' on an <uniformTimeCourse> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21008
  { SedmlSedUniformTimeCourseNumberOfStepsMustBeInteger,
    "The 'numberOfSteps' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numberOfSteps' on an <uniformTimeCourse> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21101
  { SedmlSedAlgorithmAllowedCoreAttributes,
    "Core attributes allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <algorithm>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21102
  { SedmlSedAlgorithmAllowedCoreElements,
    "Core elements allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <algorithm>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21103
  { SedmlSedAlgorithmAllowedAttributes,
    "Attributes allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object must have the required attribute 'sedml:kisaoID'. No "
    "other attributes from the SBML Level 3 SEDML namespaces are permitted on "
    "an <algorithm> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21104
  { SedmlSedAlgorithmAllowedElements,
    "Elements allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object may contain one and only one instance of the "
    "<listOfAlgorithmParameters> element. No other elements from the SBML Level "
    "3 SEDML namespaces are permitted on an <algorithm> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21105
  { SedmlSedAlgorithmKisaoIDMustBeString,
    "The 'kisaoID' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:kisaoID' on an <algorithm> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21106
  { SedmlSedAlgorithmLOAlgorithmParametersAllowedCoreElements,
    "Core elements allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAlgorithmParameters> container object may only "
    "contain <algorithmParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21107
  { SedmlSedAlgorithmLOAlgorithmParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAlgorithmParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfAlgorithmParameters> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21201
  { SedmlSedAbstractTaskAllowedCoreAttributes,
    "Core attributes allowed on <abstractTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractTask> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <abstractTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21202
  { SedmlSedAbstractTaskAllowedCoreElements,
    "Core elements allowed on <abstractTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractTask> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <abstractTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21203
  { SedmlSedAbstractTaskAllowedAttributes,
    "Attributes allowed on <abstractTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractTask> object must have the required attribute 'sedml:id', and "
    "may have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on an <abstractTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21204
  { SedmlSedAbstractTaskNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on an <abstractTask> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21301
  { SedmlSedTaskAllowedCoreAttributes,
    "Core attributes allowed on <task>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <task> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <task>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21302
  { SedmlSedTaskAllowedCoreElements,
    "Core elements allowed on <task>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <task> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <task>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21303
  { SedmlSedTaskAllowedAttributes,
    "Attributes allowed on <task>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <task> object may have the optional attributes 'sedml:modelReference' "
    "and 'sedml:simulationReference'. No other attributes from the SBML Level 3 "
    "SEDML namespaces are permitted on a <task> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21304
  { SedmlSedTaskModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <task> object must "
    "be the identifier of an existing <model> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21305
  { SedmlSedTaskSimulationReferenceMustBeSimulation,
    "The attribute 'simulationReference' must point to Simulation object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:simulationReference' of a <task> object "
    "must be the identifier of an existing <simulation> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21401
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

  // 21402
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

  // 21403
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

  // 21404
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

  // 21405
  { SedmlSedDataGeneratorNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataGenerator> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21406
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

  // 21407
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

  // 21408
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

  // 21409
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

  // 21501
  { SedmlSedOutputAllowedCoreAttributes,
    "Core attributes allowed on <output>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <output> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <output>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21502
  { SedmlSedOutputAllowedCoreElements,
    "Core elements allowed on <output>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <output> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <output>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21503
  { SedmlSedOutputAllowedAttributes,
    "Attributes allowed on <output>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <output> object must have the required attribute 'sedml:id', and may "
    "have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on an <output> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21504
  { SedmlSedOutputNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on an <output> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21601
  { SedmlSedPlotAllowedCoreAttributes,
    "Core attributes allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21602
  { SedmlSedPlotAllowedCoreElements,
    "Core elements allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21603
  { SedmlSedPlotAllowedAttributes,
    "Attributes allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may have the optional attributes 'sedml:legend', "
    "'sedml:height' and 'sedml:width'. No other attributes from the SBML Level "
    "3 SEDML namespaces are permitted on a <plot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21604
  { SedmlSedPlotAllowedElements,
    "Elements allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may contain one and only one instance of each of the "
    "SedAxis and SedAxis elements. No other elements from the SBML Level 3 "
    "SEDML namespaces are permitted on a <plot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21605
  { SedmlSedPlotLegendMustBeBoolean,
    "The 'legend' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:legend' on a <plot> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21606
  { SedmlSedPlotHeightMustBeDouble,
    "The 'height' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:height' on a <plot> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21607
  { SedmlSedPlotWidthMustBeDouble,
    "The 'width' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:width' on a <plot> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21701
  { SedmlSedPlot2DAllowedCoreAttributes,
    "Core attributes allowed on <plot2D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot2D> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plot2D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21702
  { SedmlSedPlot2DAllowedCoreElements,
    "Core elements allowed on <plot2D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot2D> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plot2D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21703
  { SedmlSedPlot2DAllowedElements,
    "Elements allowed on <plot2D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot2D> object may contain one and only one instance of each of the "
    "<listOfAbstractCurves> and SedAxis elements. No other elements from the "
    "SBML Level 3 SEDML namespaces are permitted on a <plot2D> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21704
  { SedmlSedPlot2DLOAbstractCurvesAllowedCoreElements,
    "Core elements allowed on <listOfAbstractCurves>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAbstractCurves> container object may only contain "
    "<abstractCurve> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21705
  { SedmlSedPlot2DLOAbstractCurvesAllowedCoreAttributes,
    "Core attributes allowed on <listOfAbstractCurves>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAbstractCurves> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfAbstractCurves> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21801
  { SedmlSedPlot3DAllowedCoreAttributes,
    "Core attributes allowed on <plot3D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot3D> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plot3D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21802
  { SedmlSedPlot3DAllowedCoreElements,
    "Core elements allowed on <plot3D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot3D> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plot3D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21803
  { SedmlSedPlot3DAllowedElements,
    "Elements allowed on <plot3D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot3D> object may contain one and only one instance of each of the "
    "<listOfSurfaces> and SedAxis elements. No other elements from the SBML "
    "Level 3 SEDML namespaces are permitted on a <plot3D> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21804
  { SedmlSedPlot3DLOSurfacesAllowedCoreElements,
    "Core elements allowed on <listOfSurfaces>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSurfaces> container object may only contain "
    "<surface> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21805
  { SedmlSedPlot3DLOSurfacesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSurfaces>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSurfaces> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSurfaces> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21901
  { SedmlSedAbstractCurveAllowedCoreAttributes,
    "Core attributes allowed on <abstractCurve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractCurve> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <abstractCurve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21902
  { SedmlSedAbstractCurveAllowedCoreElements,
    "Core elements allowed on <abstractCurve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractCurve> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <abstractCurve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21903
  { SedmlSedAbstractCurveAllowedAttributes,
    "Attributes allowed on <abstractCurve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractCurve> object may have the optional attributes 'sedml:id', "
    "'sedml:name', 'sedml:logX', 'sedml:order', 'sedml:style', 'sedml:yAxis' "
    "and 'sedml:xDataReference'. No other attributes from the SBML Level 3 "
    "SEDML namespaces are permitted on an <abstractCurve> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21904
  { SedmlSedAbstractCurveNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on an <abstractCurve> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21905
  { SedmlSedAbstractCurveLogXMustBeBoolean,
    "The 'logX' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logX' on an <abstractCurve> must have a value of data "
    "type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21906
  { SedmlSedAbstractCurveOrderMustBeInteger,
    "The 'order' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:order' on an <abstractCurve> must have a value of "
    "data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21907
  { SedmlSedAbstractCurveStyleMustBeStyle,
    "The attribute 'style' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of an <abstractCurve> object must "
    "be the identifier of an existing <style> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21908
  { SedmlSedAbstractCurveYAxisMustBeString,
    "The 'yAxis' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:yAxis' on an <abstractCurve> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21909
  { SedmlSedAbstractCurveXDataReferenceMustBeDataReference,
    "The attribute 'xDataReference' must point to DataReference object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xDataReference' of an <abstractCurve> "
    "object must be the identifier of an existing <dataReference> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22001
  { SedmlSedCurveAllowedCoreAttributes,
    "Core attributes allowed on <curve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <curve> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <curve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22002
  { SedmlSedCurveAllowedCoreElements,
    "Core elements allowed on <curve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <curve> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <curve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22003
  { SedmlSedCurveAllowedAttributes,
    "Attributes allowed on <curve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <curve> object must have the required attributes 'sedml:logY', "
    "'sedml:yDataReference' and 'sedml:type', and may have the optional "
    "attributes 'sedml:xErrorUpper', 'sedml:xErrorLower', 'sedml:yErrorUpper' "
    "and 'sedml:yErrorLower'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <curve> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22004
  { SedmlSedCurveLogYMustBeBoolean,
    "The 'logY' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logY' on a <curve> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22005
  { SedmlSedCurveYDataReferenceMustBeDataGenerator,
    "The attribute 'yDataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReference' of a <curve> object must "
    "be the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22006
  { SedmlSedCurveTypeMustBeCurveKindEnum,
    "The 'type' attribute must be CurveKindEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <curve> object must conform "
    "to the syntax of SBML data type 'CurveKind' and may only take on the "
    "allowed values of 'CurveKind' defined in SBML; that is, the value must be "
    "one of the following: 'points', 'bar' or 'barStacked'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22007
  { SedmlSedCurveXErrorUpperMustBeDataGenerator,
    "The attribute 'xErrorUpper' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xErrorUpper' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22008
  { SedmlSedCurveXErrorLowerMustBeDataGenerator,
    "The attribute 'xErrorLower' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xErrorLower' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22009
  { SedmlSedCurveYErrorUpperMustBeDataGenerator,
    "The attribute 'yErrorUpper' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yErrorUpper' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22010
  { SedmlSedCurveYErrorLowerMustBeDataGenerator,
    "The attribute 'yErrorLower' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yErrorLower' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22101
  { SedmlSedSurfaceAllowedCoreAttributes,
    "Core attributes allowed on <surface>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <surface> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <surface>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22102
  { SedmlSedSurfaceAllowedCoreElements,
    "Core elements allowed on <surface>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <surface> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <surface>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22103
  { SedmlSedSurfaceAllowedAttributes,
    "Attributes allowed on <surface>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <surface> object must have the required attributes 'sedml:logZ' and "
    "'sedml:zDataReference'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <surface> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22104
  { SedmlSedSurfaceLogZMustBeBoolean,
    "The 'logZ' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logZ' on a <surface> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22105
  { SedmlSedSurfaceZDataReferenceMustBeDataGenerator,
    "The attribute 'zDataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:zDataReference' of a <surface> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22201
  { SedmlSedDataSetAllowedCoreAttributes,
    "Core attributes allowed on <dataSet>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSet> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSet>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22202
  { SedmlSedDataSetAllowedCoreElements,
    "Core elements allowed on <dataSet>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSet> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSet>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22203
  { SedmlSedDataSetAllowedAttributes,
    "Attributes allowed on <dataSet>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSet> object must have the required attributes 'sedml:id', "
    "'sedml:label' and 'sedml:dataReference', and may have the optional "
    "attribute 'sedml:name'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <dataSet> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22204
  { SedmlSedDataSetLabelMustBeString,
    "The 'label' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:label' on a <dataSet> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22205
  { SedmlSedDataSetDataReferenceMustBeDataGenerator,
    "The attribute 'dataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:dataReference' of a <dataSet> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22206
  { SedmlSedDataSetNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataSet> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22301
  { SedmlSedReportAllowedCoreAttributes,
    "Core attributes allowed on <report>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <report> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <report>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22302
  { SedmlSedReportAllowedCoreElements,
    "Core elements allowed on <report>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <report> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <report>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22303
  { SedmlSedReportAllowedElements,
    "Elements allowed on <report>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <report> object may contain one and only one instance of the "
    "<listOfDataSets> element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <report> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22304
  { SedmlSedReportLODataSetsAllowedCoreElements,
    "Core elements allowed on <listOfDataSets>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataSets> container object may only contain "
    "<dataSet> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22305
  { SedmlSedReportLODataSetsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataSets>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataSets> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataSets> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22401
  { SedmlSedAlgorithmParameterAllowedCoreAttributes,
    "Core attributes allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <algorithmParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22402
  { SedmlSedAlgorithmParameterAllowedCoreElements,
    "Core elements allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <algorithmParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22403
  { SedmlSedAlgorithmParameterAllowedAttributes,
    "Attributes allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object must have the required attributes "
    "'sedml:kisaoID' and 'sedml:value'. No other attributes from the SBML Level "
    "3 SEDML namespaces are permitted on an <algorithmParameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22404
  { SedmlSedAlgorithmParameterKisaoIDMustBeString,
    "The 'kisaoID' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:kisaoID' on an <algorithmParameter> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22405
  { SedmlSedAlgorithmParameterValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:value' on an <algorithmParameter> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22501
  { SedmlSedRangeAllowedCoreAttributes,
    "Core attributes allowed on <range>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <range> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <range>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22502
  { SedmlSedRangeAllowedCoreElements,
    "Core elements allowed on <range>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <range> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <range>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22503
  { SedmlSedRangeAllowedAttributes,
    "Attributes allowed on <range>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <range> object must have the required attribute 'sedml:id'. No other "
    "attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<range> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22601
  { SedmlSedChangeXMLAllowedCoreAttributes,
    "Core attributes allowed on <changeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <changeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22602
  { SedmlSedChangeXMLAllowedCoreElements,
    "Core elements allowed on <changeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeXML> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <changeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22603
  { SedmlSedChangeXMLAllowedElements,
    "Elements allowed on <changeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeXML> object may contain one and only one instance of the XMLNode "
    "element. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on a <changeXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22701
  { SedmlSedRemoveXMLAllowedCoreAttributes,
    "Core attributes allowed on <removeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <removeXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <removeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22702
  { SedmlSedRemoveXMLAllowedCoreElements,
    "Core elements allowed on <removeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <removeXML> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <removeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22801
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

  // 22802
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

  // 22803
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

  // 22804
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

  // 22805
  { SedmlSedSetValueModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <setValue> object "
    "must be the identifier of an existing <model> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22806
  { SedmlSedSetValueSymbolMustBeString,
    "The 'symbol' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbol' on a <setValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22807
  { SedmlSedSetValueTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <setValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22808
  { SedmlSedSetValueRangeMustBeRange,
    "The attribute 'range' must point to Range object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <setValue> object must be "
    "the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22901
  { SedmlSedUniformRangeAllowedCoreAttributes,
    "Core attributes allowed on <uniformRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformRange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <uniformRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22902
  { SedmlSedUniformRangeAllowedCoreElements,
    "Core elements allowed on <uniformRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformRange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <uniformRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22903
  { SedmlSedUniformRangeAllowedAttributes,
    "Attributes allowed on <uniformRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformRange> object must have the required attributes 'sedml:start', "
    "'sedml:end', 'sedml:numberOfPoints' and 'sedml:type'. No other attributes "
    "from the SBML Level 3 SEDML namespaces are permitted on an <uniformRange> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22904
  { SedmlSedUniformRangeStartMustBeDouble,
    "The 'start' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:start' on an <uniformRange> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22905
  { SedmlSedUniformRangeEndMustBeDouble,
    "The 'end' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:end' on an <uniformRange> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22906
  { SedmlSedUniformRangeNumberOfPointsMustBeInteger,
    "The 'numberOfPoints' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numberOfPoints' on an <uniformRange> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22907
  { SedmlSedUniformRangeTypeMustBeString,
    "The 'type' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:type' on an <uniformRange> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23001
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

  // 23002
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

  // 23003
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

  // 23004
  { SedmlSedVectorRangeValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:value' of a <vectorRange> object must be "
    "an vector of values of type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23101
  { SedmlSedFunctionalRangeAllowedCoreAttributes,
    "Core attributes allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <functionalRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23102
  { SedmlSedFunctionalRangeAllowedCoreElements,
    "Core elements allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <functionalRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23103
  { SedmlSedFunctionalRangeAllowedAttributes,
    "Attributes allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object must have the required attribute 'sedml:range'. "
    "No other attributes from the SBML Level 3 SEDML namespaces are permitted "
    "on a <functionalRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23104
  { SedmlSedFunctionalRangeAllowedElements,
    "Elements allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object may contain one and only one instance of each "
    "of the ASTNode, <listOfVariables> and <listOfParameters> elements. No "
    "other elements from the SBML Level 3 SEDML namespaces are permitted on a "
    "<functionalRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23105
  { SedmlSedFunctionalRangeRangeMustBeRange,
    "The attribute 'range' must point to Range object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <functionalRange> object "
    "must be the identifier of an existing <range> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23106
  { SedmlSedFunctionalRangeLOVariablesAllowedCoreElements,
    "Core elements allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfVariables> container object may only contain "
    "<variable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23107
  { SedmlSedFunctionalRangeLOParametersAllowedCoreElements,
    "Core elements allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfParameters> container object may only contain "
    "<parameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23108
  { SedmlSedFunctionalRangeLOVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23109
  { SedmlSedFunctionalRangeLOParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23201
  { SedmlSedSubTaskAllowedCoreAttributes,
    "Core attributes allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <subTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23202
  { SedmlSedSubTaskAllowedCoreElements,
    "Core elements allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <subTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23203
  { SedmlSedSubTaskAllowedAttributes,
    "Attributes allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object must have the required attributes 'sedml:order' and "
    "'sedml:task'. No other attributes from the SBML Level 3 SEDML namespaces "
    "are permitted on a <subTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23204
  { SedmlSedSubTaskOrderMustBeInteger,
    "The 'order' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:order' on a <subTask> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23205
  { SedmlSedSubTaskTaskMustBeAbstractTask,
    "The attribute 'task' must point to AbstractTask object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:task' of a <subTask> object must be the "
    "identifier of an existing <abstractTask> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23301
  { SedmlSedOneStepAllowedCoreAttributes,
    "Core attributes allowed on <oneStep>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <oneStep> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <oneStep>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23302
  { SedmlSedOneStepAllowedCoreElements,
    "Core elements allowed on <oneStep>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <oneStep> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <oneStep>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23303
  { SedmlSedOneStepAllowedAttributes,
    "Attributes allowed on <oneStep>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <oneStep> object must have the required attribute 'sedml:step'. No "
    "other attributes from the SBML Level 3 SEDML namespaces are permitted on "
    "an <oneStep> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23304
  { SedmlSedOneStepStepMustBeDouble,
    "The 'step' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:step' on an <oneStep> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23401
  { SedmlSedSteadyStateAllowedCoreAttributes,
    "Core attributes allowed on <steadyState>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <steadyState> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <steadyState>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23402
  { SedmlSedSteadyStateAllowedCoreElements,
    "Core elements allowed on <steadyState>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <steadyState> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <steadyState>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23501
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

  // 23502
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

  // 23503
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

  // 23504
  { SedmlSedRepeatedTaskAllowedElements,
    "Elements allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may contain one and only one instance of each of "
    "the <listOfRanges,> <listOfSetValues> and <listOfSubTasks> elements. No "
    "other elements from the SBML Level 3 SEDML namespaces are permitted on a "
    "<repeatedTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23505
  { SedmlSedRepeatedTaskRangeIdMustBeRange,
    "The attribute 'rangeId' must point to Range object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:rangeId' of a <repeatedTask> object must "
    "be the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23506
  { SedmlSedRepeatedTaskResetModelMustBeBoolean,
    "The 'resetModel' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:resetModel' on a <repeatedTask> must have a value of "
    "data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23507
  { SedmlSedRepeatedTaskLORangesAllowedCoreElements,
    "Core elements allowed on <listOfRanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfRanges> container object may only contain <range> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23508
  { SedmlSedRepeatedTaskLOSetValuesAllowedCoreElements,
    "Core elements allowed on <listOfSetValues>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSetValues> container object may only contain "
    "<setValue> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23509
  { SedmlSedRepeatedTaskLOSubTasksAllowedCoreElements,
    "Core elements allowed on <listOfSubTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSubTasks> container object may only contain "
    "<subTask> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23510
  { SedmlSedRepeatedTaskLORangesAllowedCoreAttributes,
    "Core attributes allowed on <listOfRanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfRanges> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfRanges> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23511
  { SedmlSedRepeatedTaskLOSetValuesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSetValues>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSetValues> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSetValues> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23512
  { SedmlSedRepeatedTaskLOSubTasksAllowedCoreAttributes,
    "Core attributes allowed on <listOfSubTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSubTasks> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSubTasks> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23601
  { SedmlSedComputeChangeAllowedCoreAttributes,
    "Core attributes allowed on <computeChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <computeChange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <computeChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23602
  { SedmlSedComputeChangeAllowedCoreElements,
    "Core elements allowed on <computeChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <computeChange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <computeChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23603
  { SedmlSedComputeChangeAllowedElements,
    "Elements allowed on <computeChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <computeChange> object may contain one and only one instance of each of "
    "the ASTNode, <listOfVariables> and <listOfParameters> elements. No other "
    "elements from the SBML Level 3 SEDML namespaces are permitted on a "
    "<computeChange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23604
  { SedmlSedComputeChangeLOVariablesAllowedCoreElements,
    "Core elements allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfVariables> container object may only contain "
    "<variable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23605
  { SedmlSedComputeChangeLOParametersAllowedCoreElements,
    "Core elements allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfParameters> container object may only contain "
    "<parameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23606
  { SedmlSedComputeChangeLOVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23607
  { SedmlSedComputeChangeLOParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23701
  { SedmlSedDataDescriptionAllowedCoreAttributes,
    "Core attributes allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <dataDescription>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23702
  { SedmlSedDataDescriptionAllowedCoreElements,
    "Core elements allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <dataDescription>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23703
  { SedmlSedDataDescriptionAllowedAttributes,
    "Attributes allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object must have the required attribute 'sedml:id', "
    "and may have the optional attributes 'sedml:name', 'sedml:format' and "
    "'sedml:source'. No other attributes from the SBML Level 3 SEDML namespaces "
    "are permitted on a <dataDescription> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23704
  { SedmlSedDataDescriptionAllowedElements,
    "Elements allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object may contain one and only one instance of each "
    "of the SedDimensionDescription and <listOfDataSources> elements. No other "
    "elements from the SBML Level 3 SEDML namespaces are permitted on a "
    "<dataDescription> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23705
  { SedmlSedDataDescriptionNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataDescription> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23706
  { SedmlSedDataDescriptionFormatMustBeString,
    "The 'format' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:format' on a <dataDescription> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23707
  { SedmlSedDataDescriptionSourceMustBeString,
    "The 'source' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <dataDescription> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23708
  { SedmlSedDataDescriptionLODataSourcesAllowedCoreElements,
    "Core elements allowed on <listOfDataSources>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataSources> container object may only contain "
    "<dataSource> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23709
  { SedmlSedDataDescriptionLODataSourcesAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataSources>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataSources> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataSources> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23801
  { SedmlSedDataSourceAllowedCoreAttributes,
    "Core attributes allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSource>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23802
  { SedmlSedDataSourceAllowedCoreElements,
    "Core elements allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSource>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23803
  { SedmlSedDataSourceAllowedAttributes,
    "Attributes allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object must have the required attribute 'sedml:id', and may "
    "have the optional attributes 'sedml:name' and 'sedml:indexSet'. No other "
    "attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<dataSource> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23804
  { SedmlSedDataSourceAllowedElements,
    "Elements allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object may contain one and only one instance of the "
    "<listOfSlices> element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <dataSource> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23805
  { SedmlSedDataSourceNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataSource> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23806
  { SedmlSedDataSourceIndexSetMustBe,
    "The attribute 'indexSet' must point to object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:indexSet' of a <dataSource> object must "
    "be the identifier of an existing < object> defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23807
  { SedmlSedDataSourceLOSlicesAllowedCoreElements,
    "Core elements allowed on <listOfSlices>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSlices> container object may only contain <slice> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23808
  { SedmlSedDataSourceLOSlicesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSlices>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSlices> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfSlices> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23901
  { SedmlSedSliceAllowedCoreAttributes,
    "Core attributes allowed on <slice>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <slice> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <slice>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23902
  { SedmlSedSliceAllowedCoreElements,
    "Core elements allowed on <slice>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <slice> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <slice>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23903
  { SedmlSedSliceAllowedAttributes,
    "Attributes allowed on <slice>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <slice> object must have the required attributes 'sedml:reference' and "
    "'sedml:value'. No other attributes from the SBML Level 3 SEDML namespaces "
    "are permitted on a <slice> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23904
  { SedmlSedSliceReferenceMustBe,
    "The attribute 'reference' must point to object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:reference' of a <slice> object must be "
    "the identifier of an existing < object> defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23905
  { SedmlSedSliceValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:value' on a <slice> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24001
  { SedmlSedParameterEstimationTaskAllowedCoreAttributes,
    "Core attributes allowed on <parameterEstimationTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationTask> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <parameterEstimationTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24002
  { SedmlSedParameterEstimationTaskAllowedCoreElements,
    "Core elements allowed on <parameterEstimationTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationTask> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <parameterEstimationTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24003
  { SedmlSedParameterEstimationTaskAllowedElements,
    "Elements allowed on <parameterEstimationTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationTask> object may contain one and only one instance "
    "of each of the SedAlgorithm, SedObjective, <listOfAdjustableParameters> "
    "and <listOfFitExperiments> elements. No other elements from the SBML Level "
    "3 SEDML namespaces are permitted on a <parameterEstimationTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24004
  { SedmlSedParameterEstimationTaskLOAdjustableParametersAllowedCoreElements,
    "Core elements allowed on <listOfAdjustableParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAdjustableParameters> container object may only "
    "contain <adjustableParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24005
  { SedmlSedParameterEstimationTaskLOFitExperimentsAllowedCoreElements,
    "Core elements allowed on <listOfFitExperiments>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFitExperiments> container object may only contain "
    "<fitExperiment> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24006
  { SedmlSedParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfAdjustableParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAdjustableParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfAdjustableParameters> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24007
  { SedmlSedParameterEstimationTaskLOFitExperimentsAllowedCoreAttributes,
    "Core attributes allowed on <listOfFitExperiments>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfFitExperiments> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFitExperiments> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24101
  { SedmlSedObjectiveAllowedCoreAttributes,
    "Core attributes allowed on <objective>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <objective> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <objective>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24102
  { SedmlSedObjectiveAllowedCoreElements,
    "Core elements allowed on <objective>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <objective> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <objective>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24201
  { SedmlSedLeastSquareObjectiveFunctionAllowedCoreAttributes,
    "Core attributes allowed on <leastSquareObjectiveFunction>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <leastSquareObjectiveFunction> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a "
    "<leastSquareObjectiveFunction>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24202
  { SedmlSedLeastSquareObjectiveFunctionAllowedCoreElements,
    "Core elements allowed on <leastSquareObjectiveFunction>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <leastSquareObjectiveFunction> object may have the optional SBML Level 3 "
    "Core subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a "
    "<leastSquareObjectiveFunction>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24301
  { SedmlSedAdjustableParameterAllowedCoreAttributes,
    "Core attributes allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <adjustableParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24302
  { SedmlSedAdjustableParameterAllowedCoreElements,
    "Core elements allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <adjustableParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24303
  { SedmlSedAdjustableParameterAllowedAttributes,
    "Attributes allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object may have the optional attributes "
    "'sedml:modelReference' and 'sedml:target'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on an <adjustableParameter> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24304
  { SedmlSedAdjustableParameterAllowedElements,
    "Elements allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object must contain one and only one instance of "
    "the SedBounds element, and may contain one and only one instance of the "
    "<listOfExperimentRefs> element. No other elements from the SBML Level 3 "
    "SEDML namespaces are permitted on an <adjustableParameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24305
  { SedmlSedAdjustableParameterModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of an "
    "<adjustableParameter> object must be the identifier of an existing <model> "
    "object defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24306
  { SedmlSedAdjustableParameterTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on an <adjustableParameter> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24307
  { SedmlSedAdjustableParameterLOExperimentRefsAllowedCoreElements,
    "Core elements allowed on <listOfExperimentRefs>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfExperimentRefs> container object may only contain "
    "<experimentRef> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24308
  { SedmlSedAdjustableParameterLOExperimentRefsAllowedCoreAttributes,
    "Core attributes allowed on <listOfExperimentRefs>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfExperimentRefs> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfExperimentRefs> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24401
  { SedmlSedExperimentRefAllowedCoreAttributes,
    "Core attributes allowed on <experimentRef>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <experimentRef> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <experimentRef>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24402
  { SedmlSedExperimentRefAllowedCoreElements,
    "Core elements allowed on <experimentRef>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <experimentRef> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <experimentRef>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24403
  { SedmlSedExperimentRefAllowedAttributes,
    "Attributes allowed on <experimentRef>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <experimentRef> object may have the optional attribute "
    "'sedml:experimentId'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on an <experimentRef> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24404
  { SedmlSedExperimentRefExperimentIdMustBeFitExperiment,
    "The attribute 'experimentId' must point to FitExperiment object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:experimentId' of an <experimentRef> "
    "object must be the identifier of an existing <fitExperiment> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24501
  { SedmlSedFitExperimentAllowedCoreAttributes,
    "Core attributes allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <fitExperiment>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24502
  { SedmlSedFitExperimentAllowedCoreElements,
    "Core elements allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <fitExperiment>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24503
  { SedmlSedFitExperimentAllowedAttributes,
    "Attributes allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may have the optional attributes 'sedml:source' "
    "and 'sedml:id'. No other attributes from the SBML Level 3 SEDML namespaces "
    "are permitted on a <fitExperiment> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24504
  { SedmlSedFitExperimentAllowedElements,
    "Elements allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may contain one and only one instance of each of "
    "the SedAlgorithm and <listOfFitMappings> elements. No other elements from "
    "the SBML Level 3 SEDML namespaces are permitted on a <fitExperiment> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24505
  { SedmlSedFitExperimentSourceMustBeString,
    "The 'source' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <fitExperiment> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24506
  { SedmlSedFitExperimentLOFitMappingsAllowedCoreElements,
    "Core elements allowed on <listOfFitMappings>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFitMappings> container object may only contain "
    "<fitMapping> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24507
  { SedmlSedFitExperimentLOFitMappingsAllowedCoreAttributes,
    "Core attributes allowed on <listOfFitMappings>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfFitMappings> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFitMappings> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24601
  { SedmlSedFitMappingAllowedCoreAttributes,
    "Core attributes allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <fitMapping>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24602
  { SedmlSedFitMappingAllowedCoreElements,
    "Core elements allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <fitMapping>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24603
  { SedmlSedFitMappingAllowedAttributes,
    "Attributes allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object must have the required attributes 'sedml:colNumber', "
    "'sedml:dataGenerator' and 'sedml:type'. No other attributes from the SBML "
    "Level 3 SEDML namespaces are permitted on a <fitMapping> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24604
  { SedmlSedFitMappingAllowedElements,
    "Elements allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object must contain one and only one instance of the "
    "SedScaling element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <fitMapping> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24605
  { SedmlSedFitMappingColNumberMustBeInteger,
    "The 'colNumber' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:colNumber' on a <fitMapping> must have a value of "
    "data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24606
  { SedmlSedFitMappingDataGeneratorMustBeDataGenerator,
    "The attribute 'dataGenerator' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:dataGenerator' of a <fitMapping> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24607
  { SedmlSedFitMappingTypeMustBeMappingTypeEnum,
    "The 'type' attribute must be MappingTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <fitMapping> object must "
    "conform to the syntax of SBML data type 'MappingType' and may only take on "
    "the allowed values of 'MappingType' defined in SBML; that is, the value "
    "must be one of the following: 'Variable' or 'Parameter'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24701
  { SedmlSedScalingAllowedCoreAttributes,
    "Core attributes allowed on <scaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <scaling> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <scaling>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24702
  { SedmlSedScalingAllowedCoreElements,
    "Core elements allowed on <scaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <scaling> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <scaling>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24801
  { SedmlSedValueScalingAllowedCoreAttributes,
    "Core attributes allowed on <valueScaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <valueScaling> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <valueScaling>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24802
  { SedmlSedValueScalingAllowedCoreElements,
    "Core elements allowed on <valueScaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <valueScaling> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <valueScaling>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24803
  { SedmlSedValueScalingAllowedAttributes,
    "Attributes allowed on <valueScaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <valueScaling> object must have the required attribute 'sedml:weight'. "
    "No other attributes from the SBML Level 3 SEDML namespaces are permitted "
    "on a <valueScaling> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24804
  { SedmlSedValueScalingWeightMustBeString,
    "The 'weight' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:weight' on a <valueScaling> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24901
  { SedmlSedColumnScalingAllowedCoreAttributes,
    "Core attributes allowed on <columnScaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <columnScaling> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <columnScaling>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24902
  { SedmlSedColumnScalingAllowedCoreElements,
    "Core elements allowed on <columnScaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <columnScaling> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <columnScaling>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24903
  { SedmlSedColumnScalingAllowedAttributes,
    "Attributes allowed on <columnScaling>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <columnScaling> object must have the required attribute "
    "'sedml:colNumber'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <columnScaling> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24904
  { SedmlSedColumnScalingColNumberMustBeInteger,
    "The 'colNumber' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:colNumber' on a <columnScaling> must have a value of "
    "data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25001
  { SedmlSedBoundsAllowedCoreAttributes,
    "Core attributes allowed on <bounds>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <bounds> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <bounds>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25002
  { SedmlSedBoundsAllowedCoreElements,
    "Core elements allowed on <bounds>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <bounds> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <bounds>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25003
  { SedmlSedBoundsAllowedAttributes,
    "Attributes allowed on <bounds>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <bounds> object may have the optional attributes 'sedml:startingValue', "
    "'sedml:lowerBound' and 'sedml:upperBound'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on a <bounds> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25004
  { SedmlSedBoundsStartingValueMustBeDouble,
    "The 'startingValue' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:startingValue' on a <bounds> must have a value of "
    "data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25005
  { SedmlSedBoundsLowerBoundMustBeDouble,
    "The 'lowerBound' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:lowerBound' on a <bounds> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25006
  { SedmlSedBoundsUpperBoundMustBeDouble,
    "The 'upperBound' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:upperBound' on a <bounds> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25101
  { SedmlSedFigureAllowedCoreAttributes,
    "Core attributes allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <figure>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25102
  { SedmlSedFigureAllowedCoreElements,
    "Core elements allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <figure>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25103
  { SedmlSedFigureAllowedAttributes,
    "Attributes allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may have the optional attributes 'sedml:numRows' and "
    "'sedml:numColumns'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <figure> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25104
  { SedmlSedFigureAllowedElements,
    "Elements allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may contain one and only one instance of the "
    "<listOfSubPlots> element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <figure> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25105
  { SedmlSedFigureNumRowsMustBeInteger,
    "The 'numRows' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numRows' on a <figure> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25106
  { SedmlSedFigureNumColumnsMustBeInteger,
    "The 'numColumns' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numColumns' on a <figure> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25107
  { SedmlSedFigureLOSubPlotsAllowedCoreElements,
    "Core elements allowed on <listOfSubPlots>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSubPlots> container object may only contain "
    "<subPlot> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25108
  { SedmlSedFigureLOSubPlotsAllowedCoreAttributes,
    "Core attributes allowed on <listOfSubPlots>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSubPlots> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSubPlots> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25201
  { SedmlSedSubPlotAllowedCoreAttributes,
    "Core attributes allowed on <subPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subPlot> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <subPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25202
  { SedmlSedSubPlotAllowedCoreElements,
    "Core elements allowed on <subPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subPlot> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <subPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25203
  { SedmlSedSubPlotAllowedAttributes,
    "Attributes allowed on <subPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subPlot> object must have the required attributes 'sedml:plot', "
    "'sedml:row' and 'sedml:column', and may have the optional attributes "
    "'sedml:rowSpan' and 'sedml:columnSpan'. No other attributes from the SBML "
    "Level 3 SEDML namespaces are permitted on a <subPlot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25204
  { SedmlSedSubPlotPlotMustBePlot,
    "The attribute 'plot' must point to Plot object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:plot' of a <subPlot> object must be the "
    "identifier of an existing <plot> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25205
  { SedmlSedSubPlotRowMustBeInteger,
    "The 'row' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:row' on a <subPlot> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25206
  { SedmlSedSubPlotColumnMustBeInteger,
    "The 'column' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:column' on a <subPlot> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25207
  { SedmlSedSubPlotRowSpanMustBeInteger,
    "The 'rowSpan' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:rowSpan' on a <subPlot> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25208
  { SedmlSedSubPlotColumnSpanMustBeInteger,
    "The 'columnSpan' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:columnSpan' on a <subPlot> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25301
  { SedmlSedAxisAllowedCoreAttributes,
    "Core attributes allowed on <axis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <axis> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <axis>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25302
  { SedmlSedAxisAllowedCoreElements,
    "Core elements allowed on <axis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <axis> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <axis>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25303
  { SedmlSedAxisAllowedAttributes,
    "Attributes allowed on <axis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <axis> object must have the required attribute 'sedml:type', and may "
    "have the optional attributes 'sedml:min', 'sedml:max', 'sedml:grid' and "
    "'sedml:style'. No other attributes from the SBML Level 3 SEDML namespaces "
    "are permitted on an <axis> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25304
  { SedmlSedAxisTypeMustBeAxisKindEnum,
    "The 'type' attribute must be AxisKindEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of an <axis> object must conform "
    "to the syntax of SBML data type 'AxisKind' and may only take on the "
    "allowed values of 'AxisKind' defined in SBML; that is, the value must be "
    "one of the following: 'linear' or 'log10'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25305
  { SedmlSedAxisMinMustBeDouble,
    "The 'min' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:min' on an <axis> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25306
  { SedmlSedAxisMaxMustBeDouble,
    "The 'max' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:max' on an <axis> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25307
  { SedmlSedAxisGridMustBeBoolean,
    "The 'grid' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:grid' on an <axis> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25308
  { SedmlSedAxisStyleMustBeStyle,
    "The attribute 'style' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of an <axis> object must be the "
    "identifier of an existing <style> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25401
  { SedmlSedStyleAllowedCoreAttributes,
    "Core attributes allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <style>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25402
  { SedmlSedStyleAllowedCoreElements,
    "Core elements allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <style>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25403
  { SedmlSedStyleAllowedAttributes,
    "Attributes allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may have the optional attribute 'sedml:baseStyle'. No "
    "other attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<style> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25404
  { SedmlSedStyleAllowedElements,
    "Elements allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may contain one and only one instance of each of the "
    "SedLine, SedMarker and SedFill elements. No other elements from the SBML "
    "Level 3 SEDML namespaces are permitted on a <style> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25405
  { SedmlSedStyleBaseStyleMustBeStyle,
    "The attribute 'baseStyle' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:baseStyle' of a <style> object must be "
    "the identifier of an existing <style> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25501
  { SedmlSedLineAllowedCoreAttributes,
    "Core attributes allowed on <line>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <line> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <line>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25502
  { SedmlSedLineAllowedCoreElements,
    "Core elements allowed on <line>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <line> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <line>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25503
  { SedmlSedLineAllowedAttributes,
    "Attributes allowed on <line>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <line> object may have the optional attributes 'sedml:style', "
    "'sedml:color' and 'sedml:thickness'. No other attributes from the SBML "
    "Level 3 SEDML namespaces are permitted on a <line> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25504
  { SedmlSedLineStyleMustBeLineKindEnum,
    "The 'style' attribute must be LineKindEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of a <line> object must conform "
    "to the syntax of SBML data type 'LineKind' and may only take on the "
    "allowed values of 'LineKind' defined in SBML; that is, the value must be "
    "one of the following: 'none', 'solid', 'dash', 'dot' or 'dashDot'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25505
  { SedmlSedLineColorMustBeString,
    "The 'color' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:color' on a <line> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25506
  { SedmlSedLineThicknessMustBeDouble,
    "The 'thickness' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:thickness' on a <line> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25601
  { SedmlSedMarkerAllowedCoreAttributes,
    "Core attributes allowed on <marker>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <marker> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <marker>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25602
  { SedmlSedMarkerAllowedCoreElements,
    "Core elements allowed on <marker>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <marker> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <marker>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25603
  { SedmlSedMarkerAllowedAttributes,
    "Attributes allowed on <marker>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <marker> object may have the optional attributes 'sedml:size', "
    "'sedml:style', 'sedml:fill', 'sedml:lineColor' and 'sedml:lineThickness'. "
    "No other attributes from the SBML Level 3 SEDML namespaces are permitted "
    "on a <marker> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25604
  { SedmlSedMarkerSizeMustBeDouble,
    "The 'size' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:size' on a <marker> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25605
  { SedmlSedMarkerStyleMustBeMarkerKindEnum,
    "The 'style' attribute must be MarkerKindEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of a <marker> object must conform "
    "to the syntax of SBML data type 'MarkerKind' and may only take on the "
    "allowed values of 'MarkerKind' defined in SBML; that is, the value must be "
    "one of the following: 'none', 'square', 'circle', 'diamond', 'xCross', "
    "'plus', 'star', 'triangleUp', 'triangleDown', 'triangleLeft', "
    "'triangleRight', 'hDash' or 'vDash'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25606
  { SedmlSedMarkerFillMustBeString,
    "The 'fill' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:fill' on a <marker> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25607
  { SedmlSedMarkerLineColorMustBeString,
    "The 'lineColor' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:lineColor' on a <marker> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25608
  { SedmlSedMarkerLineThicknessMustBeDouble,
    "The 'lineThickness' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:lineThickness' on a <marker> must have a value of "
    "data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25701
  { SedmlSedFillAllowedCoreAttributes,
    "Core attributes allowed on <fill>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fill> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <fill>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25702
  { SedmlSedFillAllowedCoreElements,
    "Core elements allowed on <fill>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fill> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <fill>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25703
  { SedmlSedFillAllowedAttributes,
    "Attributes allowed on <fill>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fill> object must have the required attribute 'sedml:color', and may "
    "have the optional attribute 'sedml:secondColor'. No other attributes from "
    "the SBML Level 3 SEDML namespaces are permitted on a <fill> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25704
  { SedmlSedFillColorMustBeString,
    "The 'color' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:color' on a <fill> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25705
  { SedmlSedFillSecondColorMustBeString,
    "The 'secondColor' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:secondColor' on a <fill> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25801
  { SedmlSedDependentVariableAllowedCoreAttributes,
    "Core attributes allowed on <dependentVariable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dependentVariable> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <dependentVariable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25802
  { SedmlSedDependentVariableAllowedCoreElements,
    "Core elements allowed on <dependentVariable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dependentVariable> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <dependentVariable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25803
  { SedmlSedDependentVariableAllowedAttributes,
    "Attributes allowed on <dependentVariable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dependentVariable> object must have the required attribute "
    "'sedml:term', and may have the optional attributes 'sedml:targetTwo' and "
    "'sedml:symbolTwo'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <dependentVariable> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25804
  { SedmlSedDependentVariableTermMustBeString,
    "The 'term' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:term' on a <dependentVariable> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25805
  { SedmlSedDependentVariableTarget2MustBeString,
    "The 'target2' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:targetTwo' on a <dependentVariable> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25806
  { SedmlSedDependentVariableSymbol2MustBeString,
    "The 'symbol2' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbolTwo' on a <dependentVariable> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25901
  { SedmlSedRemainingDimensionAllowedCoreAttributes,
    "Core attributes allowed on <remainingDimension>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <remainingDimension> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <remainingDimension>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25902
  { SedmlSedRemainingDimensionAllowedCoreElements,
    "Core elements allowed on <remainingDimension>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <remainingDimension> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <remainingDimension>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25903
  { SedmlSedRemainingDimensionAllowedAttributes,
    "Attributes allowed on <remainingDimension>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <remainingDimension> object may have the optional attributes "
    "'sedml:target' and 'sedml:dimensionTarget'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on a <remainingDimension> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25904
  { SedmlSedRemainingDimensionTargetMustBe,
    "The attribute 'target' must point to object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:target' of a <remainingDimension> object "
    "must be the identifier of an existing < object> defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25905
  { SedmlSedRemainingDimensionDimensionTargetMustBe,
    "The attribute 'dimensionTarget' must point to object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:dimensionTarget' of a "
    "<remainingDimension> object must be the identifier of an existing < "
    "object> defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26001
  { SedmlSedDataRangeAllowedCoreAttributes,
    "Core attributes allowed on <dataRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataRange> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <dataRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26002
  { SedmlSedDataRangeAllowedCoreElements,
    "Core elements allowed on <dataRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataRange> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <dataRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26003
  { SedmlSedDataRangeAllowedAttributes,
    "Attributes allowed on <dataRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataRange> object must have the required attribute 'sedml:sourceRef'. "
    "No other attributes from the SBML Level 3 SEDML namespaces are permitted "
    "on a <dataRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26004
  { SedmlSedDataRangeSourceRefMustBe,
    "The attribute 'sourceRef' must point to object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:sourceRef' of a <dataRange> object must "
    "be the identifier of an existing < object> defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26101
  { SedmlSedSimpleRepeatedTaskAllowedCoreAttributes,
    "Core attributes allowed on <simpleRepeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simpleRepeatedTask> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <simpleRepeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26102
  { SedmlSedSimpleRepeatedTaskAllowedCoreElements,
    "Core elements allowed on <simpleRepeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simpleRepeatedTask> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <simpleRepeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26103
  { SedmlSedSimpleRepeatedTaskAllowedAttributes,
    "Attributes allowed on <simpleRepeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simpleRepeatedTask> object must have the required attributes "
    "'sedml:resetModel' and 'sedml:numRepeats'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on a <simpleRepeatedTask> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26104
  { SedmlSedSimpleRepeatedTaskResetModelMustBeBoolean,
    "The 'resetModel' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:resetModel' on a <simpleRepeatedTask> must have a "
    "value of data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26105
  { SedmlSedSimpleRepeatedTaskNumRepeatsMustBeInteger,
    "The 'numRepeats' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numRepeats' on a <simpleRepeatedTask> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26201
  { SedmlSedShadedAreaAllowedCoreAttributes,
    "Core attributes allowed on <shadedArea>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <shadedArea> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <shadedArea>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26202
  { SedmlSedShadedAreaAllowedCoreElements,
    "Core elements allowed on <shadedArea>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <shadedArea> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <shadedArea>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26203
  { SedmlSedShadedAreaAllowedAttributes,
    "Attributes allowed on <shadedArea>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <shadedArea> object must have the required attributes "
    "'sedml:yDataReferenceFrom' and 'sedml:yDataReferenceTo'. No other "
    "attributes from the SBML Level 3 SEDML namespaces are permitted on a "
    "<shadedArea> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26204
  { SedmlSedShadedAreaYDataReferenceFromMustBeDataGenerator,
    "The attribute 'yDataReferenceFrom' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReferenceFrom' of a <shadedArea> "
    "object must be the identifier of an existing <dataGenerator> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26205
  { SedmlSedShadedAreaYDataReferenceToMustBeDataGenerator,
    "The attribute 'yDataReferenceTo' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReferenceTo' of a <shadedArea> "
    "object must be the identifier of an existing <dataGenerator> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99994
  {
    SedUnknownCoreAttribute,
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

