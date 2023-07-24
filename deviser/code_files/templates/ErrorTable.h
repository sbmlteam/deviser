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
  { SBMLUnknown,
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

