#ifndef SBMLErrorTable_H__
#define SBMLErrorTable_H__

#include <sbml/SBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibsbmlInternal */
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
} sbmlErrorTableEntry;


static const sbmlErrorTableEntry sbmlErrorTable[] =
{
  // 10000
  { SBMLmlUnknown,
    "Encountered unknown internal libSBML error",
    LIBSBML_CAT_INTERNAL, 
    LIBSBML_SEV_FATAL,
    "Unrecognized error encountered by libSBML",
    {"",
    }
  },

  //10001
  {
    SBMLNotUTF8,
    "File does not use UTF-8 encoding",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "An SBML_Lang XML file must use UTF-8 as the character encoding. More "
    "precisely, the 'encoding' attribute of the XML declaration at the "
    "beginning of the XML data stream cannot have a value other than "
    "'UTF-8'. An example valid declaration is "
    "'<?xml version=\"1.0\" encoding=\"UTF-8\"?>'.",
    {""
    }
  },

  //10002
  {
    SBMLUnrecognizedElement,
    "Encountered unrecognized element",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "An SBML_Lang XML document must not contain undefined elements or attributes "
    "in the SBML_Lang namespace. Documents containing unknown elements or "
    "attributes placed in the SBML_Lang namespace do not conform to the SBML_Lang "
    "specification.",  
    {""
    }
  },

  //10003
  {
    SBMLNotSchemaConformant,
    "Document does not conform to the SBML_Lang XML schema",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "An SBML_Lang XML document must conform to the XML Schema for the corresponding "
    "SBML_Lang Level, Version and Release. The XML Schema for SBML_Lang defines the "
    "basic SBML_Lang object structure, the data types used by those objects, and the "
    "order in which the objects may appear in an SBML_Lang document.",
    {""
    }
  },

  //10201
  {
    SBMLInvalidMathElement,
    "Invalid MathML",
    LIBSBML_CAT_MATHML_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "All MathML content in SBML_Lang must appear within a <math> element, and the "
    "<math> element must be either explicitly or implicitly in the XML "
    "namespace \"http://www.w3.org/1998/Math/MathML\".",
    {""
    }
  },

  //10401
  {
    SBMLMissingAnnotationNamespace,
    "Missing declaration of the XML namespace for the annotation",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "Every top-level element within an annotation element must "
    "have a namespace declared.",
    {""
    }
  },

  //10402
  {
    SBMLDuplicateAnnotationNamespaces,
    "Multiple annotations using the same XML namespace",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "There cannot be more than one top-level element using a "
    "given namespace inside a given annotation element. ", 
    {""
    }
  },

  //10403
  {
    SBMLNamespaceInAnnotation,
    "The SBML_Lang XML namespace cannot be used in an Annotation object",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any SBML_Lang "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    SBMLMultipleAnnotations,
    "Only one Annotation object is permitted under a given SBML_Lang object",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "A given SBML_Lang object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    SBMLNotesNotInXHTMLNamespace,
    "Notes must be placed in the XHTML XML namespace",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "The contents of the <notes> element must be explicitly placed in the "
    "XHTML XML namespace.", 
    {""
    }
  },

  //10802
  {
    SBMLNotesContainsXMLDecl,
    "XML declarations are not permitted in Notes objects",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML declaration "
    "(i.e., a string of the form \"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\" "
    "or similar).",
    {""
    }
  },

  //10803
  {
    SBMLNotesContainsDOCTYPE,
    "XML DOCTYPE elements are not permitted in Notes objects",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML DOCTYPE "
    "declaration (i.e., a string beginning with the characters \"<!DOCTYPE\". ",
    {""
    }
  },

  //10804
  {
    SBMLInvalidNotesContent,
    "Invalid notes content",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    SBMLOnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given SBML_Lang object",
    LIBSBML_CAT_SBML,
    LIBSBML_SEV_ERROR,
    "A given SBML_Lang object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  SBML_Lang specific errors.
   * ----------------------------------------------------------------------- */

<add_specific_error_table/>    
  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99994
  {
    SBMLUnknownCoreAttribute,
    "Unknown attribute",
    LIBSBML_CAT_INTERNAL,
    LIBSBML_SEV_ERROR,
    "An unknown attribute has been found.", 
    {""
    }
   },

  //99999
  {
    SBMLCodesUpperBound,
    "Upper boundary of libSBML-specific diagnostic codes",
    LIBSBML_CAT_INTERNAL,
    LIBSBML_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {""
    }
   }
};

LIBSBML_CPP_NAMESPACE_END
/** @endcond */



#endif /* !SBMLErrorTable_H__ */

