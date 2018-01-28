/**
 * @file QualExtension.cpp
 * @brief Implementation of QualExtension.
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
#include <sbml/extension/SBMLExtensionRegister.h>
#include <sbml/extension/SBMLExtensionRegistry.h>
#include <sbml/extension/SBasePluginCreator.h>
#include <sbml/extension/SBMLDocumentPlugin.h>

#include <sbml/packages/qual/extension/QualExtension.h>
#include <sbml/packages/qual/extension/QualSBMLDocumentPlugin.h>
#include <sbml/packages/qual/validator/QualSBMLErrorTable.h>
#include <sbml/packages/qual/extension/QualModelPlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
QualExtension::getPackageName()
{
  static const std::string pkgName = "qual";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
QualExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
QualExtension::getDefaultVersion()
{
  return 1;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
QualExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
QualExtension::getXmlnsL3V1V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/qual/version1";
  return xmlns;
}


/**
 *
 * Adds this QualExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<QualExtension> qualExtensionRegistry;

static
const char* SBML_QUAL_TYPECODE_STRINGS[] =
{
    "QualitativeSpecies"
  , "Transition"
  , "Input"
  , "Output"
  , "DefaultTerm"
  , "FunctionTerm"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<QualExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<QualExtension>;

/*
 * Creates a new QualExtension instance.
 */
QualExtension::QualExtension()
{
}


/*
 * Copy constructor for QualExtension.
 */
QualExtension::QualExtension(const QualExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for QualExtension.
 */
QualExtension&
QualExtension::operator=(const QualExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this QualExtension object.
 */
QualExtension*
QualExtension::clone() const
{
  return new QualExtension(*this);
}


/*
 * Destructor for QualExtension.
 */
QualExtension::~QualExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("qual").
 */
const std::string&
QualExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
QualExtension::getURI(unsigned int sbmlLevel,
                      unsigned int sbmlVersion,
                      unsigned int pkgVersion) const
{
  if (sbmlLevel == 3)
  {
    if (sbmlVersion == 1)
    {
      if (pkgVersion == 1)
      {
        return getXmlnsL3V1V1();
      }
    }
  }

  static std::string empty = "";
  return empty;
}


/*
 * Returns the SBML Level for the given URI of this package.
 */
unsigned int
QualExtension::getLevel(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 3;
  }

  return 0;
}


/*
 * Returns the Version within the SBML Level for the given URI of this package.
 */
unsigned int
QualExtension::getVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns the SBML Level&nbsp;3 package version for the given URI of this
 * package.
 */
unsigned int
QualExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns a QualPkgNamespaces object.
 */
SBMLNamespaces*
QualExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  QualPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V1V1())
  {
    pkgns = new QualPkgNamespaces(3, 1, 1);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;qual&rdquo; package and returns a string
 * describing the code.
 */
const char*
QualExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_QUAL_QUALITATIVE_SPECIES;
  int max = SBML_QUAL_FUNCTION_TERM;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Qual Type)";
  }

  return SBML_QUAL_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
QualExtension::getErrorTable(unsigned int index) const
{
  return qualErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
QualExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize = sizeof(qualErrorTable)/sizeof(qualErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == qualErrorTable[i].code)
    {
      index = i;
      break;
    }
  }

  return index;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the offset for the errorId range for the "qual" package.
 */
unsigned int
QualExtension::getErrorIdOffset() const
{
  return 3000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes qual extension by creating an object of this class with the
 * required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
QualExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  QualExtension qualExtension;


  std::vector<std::string> packageURIs;

  packageURIs.push_back(getXmlnsL3V1V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);

  SBasePluginCreator<QualSBMLDocumentPlugin, QualExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<QualModelPlugin, QualExtension>
    modelPluginCreator(modelExtPoint, packageURIs);

  qualExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  qualExtension.addSBasePluginCreator(&modelPluginCreator);

  SBMLExtensionRegistry::getInstance().addExtension(&qualExtension);
}

/** @endcond */




#endif /* __cplusplus */


static
const char* SBML_SIGN_STRINGS[] =
{
  "positive"
, "negative"
, "dual"
, "unknown"
, "invalid Sign"
};


/*
 * Returns the string version of the provided #Sign_t enumeration.
 */
LIBSBML_EXTERN
const char*
Sign_toString(Sign_t s)
{
  int min = INPUT_SIGN_POSITIVE;
  int max = INPUT_SIGN_INVALID;

  if (s < min || s > max)
  {
    return "(Unknown Sign value)";
  }

  return SBML_SIGN_STRINGS[s - min];
}


/*
 * Returns the #Sign_t enumeration corresponding to the given string or
 * @sbmlconstant{INPUT_SIGN_INVALID, Sign_t} if there is no such match.
 */
LIBSBML_EXTERN
Sign_t
Sign_fromString(const char* code)
{
  static int size = sizeof(SBML_SIGN_STRINGS)/sizeof(SBML_SIGN_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_SIGN_STRINGS[i])
    {
      return (Sign_t)(i);
    }
  }

  return INPUT_SIGN_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Sign_t is valid.
 */
LIBSBML_EXTERN
int
Sign_isValid(Sign_t s)
{
  int min = INPUT_SIGN_POSITIVE;
  int max = INPUT_SIGN_INVALID;

  if (s < min || s >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Sign_t.
 */
LIBSBML_EXTERN
int
Sign_isValidString(const char* code)
{
  return Sign_isValid(Sign_fromString(code));
}


static
const char* SBML_TRANSITION_OUTPUT_EFFECT_STRINGS[] =
{
  "production"
, "assignmentLevel"
, "invalid TransitionOutputEffect"
};


/*
 * Returns the string version of the provided #TransitionOutputEffect_t
 * enumeration.
 */
LIBSBML_EXTERN
const char*
TransitionOutputEffect_toString(TransitionOutputEffect_t toe)
{
  int min = OUTPUT_TRANSITION_EFFECT_PRODUCTION;
  int max = OUTPUT_TRANSITION_EFFECT_INVALID;

  if (toe < min || toe > max)
  {
    return "(Unknown TransitionOutputEffect value)";
  }

  return SBML_TRANSITION_OUTPUT_EFFECT_STRINGS[toe - min];
}


/*
 * Returns the #TransitionOutputEffect_t enumeration corresponding to the given
 * string or @sbmlconstant{OUTPUT_TRANSITION_EFFECT_INVALID,
 * TransitionOutputEffect_t} if there is no such match.
 */
LIBSBML_EXTERN
TransitionOutputEffect_t
TransitionOutputEffect_fromString(const char* code)
{
  static int size =
    sizeof(SBML_TRANSITION_OUTPUT_EFFECT_STRINGS)/sizeof(SBML_TRANSITION_OUTPUT_EFFECT_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_TRANSITION_OUTPUT_EFFECT_STRINGS[i])
    {
      return (TransitionOutputEffect_t)(i);
    }
  }

  return OUTPUT_TRANSITION_EFFECT_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #TransitionOutputEffect_t is valid.
 */
LIBSBML_EXTERN
int
TransitionOutputEffect_isValid(TransitionOutputEffect_t toe)
{
  int min = OUTPUT_TRANSITION_EFFECT_PRODUCTION;
  int max = OUTPUT_TRANSITION_EFFECT_INVALID;

  if (toe < min || toe >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #TransitionOutputEffect_t.
 */
LIBSBML_EXTERN
int
TransitionOutputEffect_isValidString(const char* code)
{
  return
    TransitionOutputEffect_isValid(TransitionOutputEffect_fromString(code));
}


static
const char* SBML_TRANSITION_INPUT_EFFECT_STRINGS[] =
{
  "none"
, "consumption"
, "invalid TransitionInputEffect"
};


/*
 * Returns the string version of the provided #TransitionInputEffect_t
 * enumeration.
 */
LIBSBML_EXTERN
const char*
TransitionInputEffect_toString(TransitionInputEffect_t tie)
{
  int min = INPUT_TRANSITION_EFFECT_NONE;
  int max = INPUT_TRANSITION_EFFECT_INVALID;

  if (tie < min || tie > max)
  {
    return "(Unknown TransitionInputEffect value)";
  }

  return SBML_TRANSITION_INPUT_EFFECT_STRINGS[tie - min];
}


/*
 * Returns the #TransitionInputEffect_t enumeration corresponding to the given
 * string or @sbmlconstant{INPUT_TRANSITION_EFFECT_INVALID,
 * TransitionInputEffect_t} if there is no such match.
 */
LIBSBML_EXTERN
TransitionInputEffect_t
TransitionInputEffect_fromString(const char* code)
{
  static int size =
    sizeof(SBML_TRANSITION_INPUT_EFFECT_STRINGS)/sizeof(SBML_TRANSITION_INPUT_EFFECT_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_TRANSITION_INPUT_EFFECT_STRINGS[i])
    {
      return (TransitionInputEffect_t)(i);
    }
  }

  return INPUT_TRANSITION_EFFECT_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #TransitionInputEffect_t is valid.
 */
LIBSBML_EXTERN
int
TransitionInputEffect_isValid(TransitionInputEffect_t tie)
{
  int min = INPUT_TRANSITION_EFFECT_NONE;
  int max = INPUT_TRANSITION_EFFECT_INVALID;

  if (tie < min || tie >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #TransitionInputEffect_t.
 */
LIBSBML_EXTERN
int
TransitionInputEffect_isValidString(const char* code)
{
  return TransitionInputEffect_isValid(TransitionInputEffect_fromString(code));
}




LIBSBML_CPP_NAMESPACE_END


