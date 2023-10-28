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

  /* --------------------------------------------------------------------------
   * Boundary marker.  TSB specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { TSBNSUndeclared,
    "The TSB namespace is not correctly declared.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "To conform to the tsb specification for TSB Level 1 Version 1, an TSB "
    "document must declare 'http://testsbxml.org/l1v1' as the XMLNamespace to "
    "use for elements of this package.",
    { "TSB L1V1 Section "
    }
  },

  // 10102
  { TSBElementNotInNs,
    "Element not in TSB namespace",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Wherever they appear in a TSB document, elements and attributes from the "
    "tsb must use the 'http://testsbxml.org/l1v1' namespace, declaring so "
    "either explicitly or implicitly.",
    { "TSB L1V1 Section "
    }
  },

  // 10201
  { TSBInvalidMetaidSyntax,
    "Invalid SId syntax",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The value of a 'tsb:metaid' must conform to the syntax of the XML Type "
    "ID",
    { "TSB L1V1 Section "
    }
  },

  // 10301
  { TSBNoAnnotationNS,
    "No ns for TestAnnotation",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Every top-level XML element within an <testAnnotation> object must have an "
    "XML namespace declared.",
    { "TSB L1V1 Section "
    }
  },

  // 10302
  { TSBRepeatAnnotationNS,
    "Repeat ns for TestAnnotation",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A given XML namespace cannot be the namespace of more than one "
    "top-levelelement within a given <testAnnotation> object.",
    { "TSB L1V1 Section "
    }
  },

  // 10303
  { TSBOnlyOneAnnotation,
    "Only one TestAnnotation",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A given TSB element may contain at most one <testAnnotation> subobject.",
    { "TSB L1V1 Section "
    }
  },

  // 10401
  { NotesInXHTML,
    "Notes not in XHTML",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The contents of a <notes> object must be explicitly placed in the XHTML "
    "XML namespace. ",
    { "TSB L1V1 Section "
    }
  },

  // 10402
  { XMLDeclNotes,
    "No XML decl in Notes",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The contents of a <notes> object must not contain an XML declaration, <ie> "
    "a string of the form '<?xml version="1.0" encoding="UTF-8"?>' or
    similar.",
    { "TSB L1V1 Section "
    }
  },

  // 10403
  { DOCTYPEInNotes,
    "No DOCTYPE in Notes",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The content of a <notes> object must not contain an XML DOCTYPE "
    "declaration, <ie> a string beginning with the characters '<!DOCTYPE'.",
    { "TSB L1V1 Section "
    }
  },

  // 10404
  { TSBOnlyOneNotes,
    "Only one Notes",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A given TSB element may contain at most one <notes> subobject.",
    { "TSB L1V1 Section "
    }
  },

  // 20101
  { TSBTSBDocumentAllowedAttributes,
    "Attributes allowed on <tSBDocument>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <TSBDocument> object must have the required attributes 'tsb:level' and "
    "'tsb:version', and may have the optional attribute 'tsb:metaid'. No other "
    "attributes from the TSB Level 1 Version 1 namespaces are permitted on a "
    "<TSBDocument> object. ",
    { "TSB L1V1 Section "
    }
  },

  // 20102
  { TSBTSBDocumentAllowedElements,
    "Elements allowed on <tSBDocument>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Apart from the general <notes> and <testAnnotation> subobjects permitted "
    "on all TSB components, A <TSBDocument> object may contain one and only one "
    "instance of the <listOfComments> element. No other objects from the TSB "
    "Level 1 Version 1 namespaces are permitted on a <TSBDocument> object. ",
    { "TSB L1V1 Section "
    }
  },

  // 20103
  { TSBTSBDocumentLevelMustBeNonNegativeInteger,
    "The 'level' attribute must be NonNegativeInteger.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:level' on a <TSBDocument> must have a value of data "
    "type 'integer', and must be non negative.",
    { "TSB L1V1 Section "
    }
  },

  // 20104
  { TSBTSBDocumentVersionMustBeNonNegativeInteger,
    "The 'version' attribute must be NonNegativeInteger.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:version' on a <TSBDocument> must have a value of data "
    "type 'integer', and must be non negative.",
    { "TSB L1V1 Section "
    }
  },

  // 20201
  { TSBTSBDocumentLOCommentAllowedCoreElements,
    "Core elements allowed on <listOfComment>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "Apart from the general <notes> and <testAnnotation> subobjects permitted "
    "on all TSB objects, a <listOfComments> container object may only contain "
    "<comment> objects.",
    { "TSB L1V1 Section "
    }
  },

  // 20202
  { TSBTSBDocumentLOCommentsAllowedCoreAttributes,
    "Core attributes allowed on <listOfComments>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <listOfComments> object may have the optional attribute 'metaid'. No "
    "other attributes from the TSB Level 1 Version 1 namespaces are permitted "
    "on a <listOfComments> object.",
    { "TSB L1V1 Section "
    }
  },

  // 20301
  { TSBCommentAllowedAttributes,
    "Attributes allowed on <comment>.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "A <comment> object must have the required attributes 'tsb:contributor' and "
    "'tsb:number', and may have the optional attributes 'tsb:point' and "
    "'tsb:metaid'. No other attributes from the TSB Level 1 Version 1 "
    "namespaces are permitted on a <comment> object. ",
    { "TSB L1V1 Section "
    }
  },

  // 20302
  { TSBCommentContributorMustBeString,
    "The 'contributor' attribute must be String.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:contributor' on a <comment> must have a value of data "
    "type 'string'.",
    { "TSB L1V1 Section "
    }
  },

  // 20303
  { TSBCommentNumberMustBeDouble,
    "The 'number' attribute must be Double.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:number' on a <comment> must have a value of data type "
    "'double'.",
    { "TSB L1V1 Section "
    }
  },

  // 20304
  { TSBCommentPointMustBeString,
    "The 'point' attribute must be String.",
    LIBTSB_CAT_GENERAL_CONSISTENCY,
    LIBTSB_SEV_ERROR,
    "The attribute 'tsb:point' on a <comment> must have a value of data type "
    "'string'.",
    { "TSB L1V1 Section "
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

