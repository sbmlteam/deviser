/**
 * @file TSBErrorTable.h
 * @brief Definition of the TSBErrorTable class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
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


#ifndef TSBErrorTable_H__
#define TSBErrorTable_H__

#include <tsb/TSBError.h>


LIBTSB_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibtsbInternal */
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
} tsbErrorTableEntry;


static const tsbErrorTableEntry tsbErrorTable[] =
{
  // 10000
  { TSBUnknown,
    "Encountered unknown internal libTSB error",
    LIBTSB_CAT_INTERNAL, 
    LIBTSB_SEV_FATAL,
    "Unrecognized error encountered by libTSB",
    {"",
    }
  },

  //10001
  {
    TSBNotUTF8,
    "File does not use UTF-8 encoding",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "An TSB XML file must use UTF-8 as the character encoding. More "
    "precisely, the 'encoding' attribute of the XML declaration at the "
    "beginning of the XML data stream cannot have a value other than "
    "'UTF-8'. An example valid declaration is "
    "'<?xml version=\"1.0\" encoding=\"UTF-8\"?>'.",
    {""
    }
  },

  //10002
  {
    TSBUnrecognizedElement,
    "Encountered unrecognized element",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "An TSB XML document must not contain undefined elements or attributes "
    "in the TSB namespace. Documents containing unknown elements or "
    "attributes placed in the TSB namespace do not conform to the TSB "
    "specification.",  
    {""
    }
  },

  //10003
  {
    TSBNotSchemaConformant,
    "Document does not conform to the TSB XML schema",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "An TSB XML document must conform to the XML Schema for the corresponding "
    "TSB Level, Version and Release. The XML Schema for TSB defines the "
    "basic TSB object structure, the data types used by those objects, and the "
    "order in which the objects may appear in an TSB document.",
    {""
    }
  },

  //10201
  {
    TSBInvalidMathElement,
    "Invalid MathML",
    LIBTSB_CAT_MATHML_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "All MathML content in TSB must appear within a <math> element, and the "
    "<math> element must be either explicitly or implicitly in the XML "
    "namespace \"http://www.w3.org/1998/Math/MathML\".",
    {""
    }
  },

  //10401
  {
    TSBMissingTestAnnotationNamespace,
    "Missing declaration of the XML namespace for the annotation",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "Every top-level element within an annotation element must "
    "have a namespace declared.",
    {""
    }
  },

  //10402
  {
    TSBDuplicateTestAnnotationNamespaces,
    "Multiple annotations using the same XML namespace",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "There cannot be more than one top-level element using a "
    "given namespace inside a given annotation element. ", 
    {""
    }
  },

  //10403
  {
    TSBNamespaceInTestAnnotation,
    "The TSB XML namespace cannot be used in an TestAnnotation object",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any TSB "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    TSBMultipleTestAnnotations,
    "Only one TestAnnotation object is permitted under a given TSB object",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "A given TSB object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    TSBNotesNotInXHTMLNamespace,
    "Notes must be placed in the XHTML XML namespace",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "The contents of the <notes> element must be explicitly placed in the "
    "XHTML XML namespace.", 
    {""
    }
  },

  //10802
  {
    TSBNotesContainsXMLDecl,
    "XML declarations are not permitted in Notes objects",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML declaration "
    "(i.e., a string of the form \"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\" "
    "or similar).",
    {""
    }
  },

  //10803
  {
    TSBNotesContainsDOCTYPE,
    "XML DOCTYPE elements are not permitted in Notes objects",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML DOCTYPE "
    "declaration (i.e., a string beginning with the characters \"<!DOCTYPE\". ",
    {""
    }
  },

  //10804
  {
    TSBInvalidNotesContent,
    "Invalid notes content",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    TSBOnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given TSB object",
    LIBTSB_CAT_TSB,
    LIBTSB_SEV_ERROR,
    "A given TSB object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  TSB specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { TsbNSUndeclared,
    "The Tsb namespace is not correctly declared.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "To conform to the Package specification for SBML Level 0 Version 1, an "
    "SBML document must declare "
    "'http://www.sbml.org/sbml/level0/version1/tsb/version0' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Tsb V1 Section 3.1"
    }
  },

  // 10102
  { TsbElementNotInNs,
    "Element not in Tsb namespace",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Package must use the "
    "'http://www.sbml.org/sbml/level0/version1/tsb/version0' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Tsb V1 Section 3.1"
    }
  },

  // 10301
  { TsbDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 10302
  { TsbIdSyntaxRule,
    "Invalid SId syntax",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The value of a 'tsb:id' must conform to the syntax of the <sbml> data type "
    "'SId'",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 10303
  { TSBInvalidMetaidSyntax,
    "Invalid SId syntax",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The value of a 'tsb:metaid' must conform to the syntax of the XML Type "
    "ID",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20101
  { InvalidNamespaceOnTSB,
    "Invalid namespace",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Invalid namespace declared.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20102
  { AllowedAttributes,
    "Allowed attributes",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Allowed attributes",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20103
  { TSBEmptyListElement,
    "No empty listOf",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "No empty lists",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20201
  { TsbDocumentAllowedCoreAttributes,
    "Core attributes allowed on <document>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <document> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <document>.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20202
  { TsbDocumentAllowedCoreElements,
    "Core elements allowed on <document>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <document> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <document>.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20203
  { TsbDocumentAllowedAttributes,
    "Attributes allowed on <document>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <document> object must have the required attributes 'tsb:level' and "
    "'tsb:version'. No other attributes from the SBML Level 3 Test SB XML "
    "Library namespaces are permitted on a <document> object. ",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20204
  { TsbDocumentAllowedElements,
    "Elements allowed on <document>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <document> object may contain one and only one instance of the "
    "<listOfComments> element. No other elements from the SBML Level 3 Test SB "
    "XML Library namespaces are permitted on a <document> object. ",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20205
  { TsbDocumentLevelMustBeNonNegativeInteger,
    "The 'level' attribute must be NonNegativeInteger.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:level' on a <document> must have a value of data type "
    "'integer', and must be non negative.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20206
  { TsbDocumentVersionMustBeNonNegativeInteger,
    "The 'version' attribute must be NonNegativeInteger.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:version' on a <document> must have a value of data type "
    "'integer', and must be non negative.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20207
  { TsbDocumentLOCommentsAllowedCoreElements,
    "Core elements allowed on <listOfComments>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfComments> container object may only contain "
    "<comment> objects.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20208
  { TsbDocumentLOCommentsAllowedCoreAttributes,
    "Core attributes allowed on <listOfComments>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <listOfComments> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfComments> object.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20301
  { TsbCommentAllowedCoreAttributes,
    "Core attributes allowed on <comment>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <comment> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <comment>.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20302
  { TsbCommentAllowedCoreElements,
    "Core elements allowed on <comment>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <comment> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <comment>.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20303
  { TsbCommentAllowedAttributes,
    "Attributes allowed on <comment>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <comment> object must have the required attributes 'tsb:contributor' and "
    "'tsb:number', and may have the optional attribute 'tsb:point'. No other "
    "attributes from the SBML Level 3 Test SB XML Library namespaces are "
    "permitted on a <comment> object. ",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20304
  { TsbCommentContributorMustBeString,
    "The 'contributor' attribute must be String.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:contributor' on a <comment> must have a value of data "
    "type 'string'.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20305
  { TsbCommentNumberMustBeDouble,
    "The 'number' attribute must be Double.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:number' on a <comment> must have a value of data type "
    "'double'.",
    { "L3V1 Tsb V1 Section"
    }
  },

  // 20306
  { TsbCommentPointMustBeString,
    "The 'point' attribute must be String.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:point' on a <comment> must have a value of data type "
    "'string'.",
    { "L3V1 Tsb V1 Section"
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99994
  {
    TSBUnknownCoreAttribute,
    "Unknown attribute",
    LIBTSB_CAT_INTERNAL,
    LIBTSB_SEV_ERROR,
    "An unknown attribute has been found.", 
    {""
    }
   },

  //99999
  {
    TSBCodesUpperBound,
    "Upper boundary of libTSB-specific diagnostic codes",
    LIBTSB_CAT_INTERNAL,
    LIBTSB_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {""
    }
   }
};

LIBTSB_CPP_NAMESPACE_END
/** @endcond */



#endif /* !TSBErrorTable_H__ */

