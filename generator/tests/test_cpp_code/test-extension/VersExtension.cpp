/**
 * @file VersExtension.cpp
 * @brief Implementation of VersExtension.
 * @author SBMLTeam
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
#include <sbml/extension/SBMLExtensionRegister.h>
#include <sbml/extension/SBMLExtensionRegistry.h>
#include <sbml/extension/SBasePluginCreator.h>
#include <sbml/extension/SBMLDocumentPlugin.h>

#include <sbml/packages/vers/extension/VersExtension.h>
#include <sbml/packages/vers/extension/VersSBMLDocumentPlugin.h>
#include <sbml/packages/vers/validator/VersSBMLErrorTable.h>
#include <sbml/packages/vers/extension/VersModelPlugin.h>
#include <sbml/packages/vers/extension/VersSpeciesPlugin.h>
#include <sbml/packages/vers/extension/VersReactionPlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
VersExtension::getPackageName()
{
  static const std::string pkgName = "vers";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
VersExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
VersExtension::getDefaultVersion()
{
  return 1;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
VersExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
VersExtension::getXmlnsL3V1V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/vers/version1";
  return xmlns;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
VersExtension::getXmlnsL3V1V2()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/vers/version2";
  return xmlns;
}


/**
 *
 * Adds this VersExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<VersExtension> versExtensionRegistry;

static
const char* SBML_VERS_TYPECODE_STRINGS[] =
{
    "ClassOne"
  , "Another"
  , "BBB"
  , "ClassTwo"
  , "ClassThree"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<VersExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<VersExtension>;

/*
 * Creates a new VersExtension instance.
 */
VersExtension::VersExtension()
{
}


/*
 * Copy constructor for VersExtension.
 */
VersExtension::VersExtension(const VersExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for VersExtension.
 */
VersExtension&
VersExtension::operator=(const VersExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this VersExtension object.
 */
VersExtension*
VersExtension::clone() const
{
  return new VersExtension(*this);
}


/*
 * Destructor for VersExtension.
 */
VersExtension::~VersExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("vers").
 */
const std::string&
VersExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
VersExtension::getURI(unsigned int sbmlLevel,
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
      else
      {
        return getXmlnsL3V1V2();
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
VersExtension::getLevel(const std::string& uri) const
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
VersExtension::getVersion(const std::string& uri) const
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
VersExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }
  else if (uri == getXmlnsL3V1V2())
  {
    return 2;
  }

  return 0;
}


/*
 * Returns a VersPkgNamespaces object.
 */
SBMLNamespaces*
VersExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  VersPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V1V1())
  {
    pkgns = new VersPkgNamespaces(3, 1, 1);
  }
  else if (uri == getXmlnsL3V1V2())
  {
    pkgns = new VersPkgNamespaces(3, 1, 2);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;vers&rdquo; package and returns a string
 * describing the code.
 */
const char*
VersExtension::getStringFromTypeCode(int typeCode) const
{
  int min = CLASS_ONE;
  int max = CLASS_THREE;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Vers Type)";
  }

  return SBML_VERS_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
VersExtension::getErrorTable(unsigned int index) const
{
  return versErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
VersExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize = sizeof(versErrorTable)/sizeof(versErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == versErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "vers" package.
 */
unsigned int
VersExtension::getErrorIdOffset() const
{
  return 10000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns true if the package has multiple versions.
 */
bool
VersExtension::hasMultipleVersions() const
{
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes vers extension by creating an object of this class with the
 * required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
VersExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  VersExtension versExtension;


  std::vector<std::string> packageURIs;
  packageURIs.push_back(getXmlnsL3V1V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);
  SBaseExtensionPoint speciesExtPoint("core", SBML_SPECIES);
  SBaseExtensionPoint reactionExtPoint("core", SBML_REACTION);

  SBasePluginCreator<VersSBMLDocumentPlugin, VersExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<VersModelPlugin, VersExtension>
    modelPluginCreator(modelExtPoint, packageURIs);
  SBasePluginCreator<VersSpeciesPlugin, VersExtension>
    speciesPluginCreator(speciesExtPoint, packageURIs);
  SBasePluginCreator<VersReactionPlugin, VersExtension>
    reactionPluginCreator(reactionExtPoint, packageURIs);

  versExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  versExtension.addSBasePluginCreator(&modelPluginCreator);
  versExtension.addSBasePluginCreator(&speciesPluginCreator);
  versExtension.addSBasePluginCreator(&reactionPluginCreator);

  int result =
    SBMLExtensionRegistry::getInstance().addExtension(&versExtension);
}

/** @endcond */




#endif /* __cplusplus */


static
const char* SBML_FBC_TYPE_STRINGS[] =
{
  "maximize"
, "minimize"
, "invalid FbcType"
};


/*
 */
LIBSBML_EXTERN
const char*
FbcType_toString(FbcType_t ft)
{
  int min = OBJECTIVE_TYPE_MAXIMIZE;
  int max = FBC_TYPE_INVALID;

  if (ft < min || ft > max)
  {
    return "(Unknown FbcType value)";
  }

  return SBML_FBC_TYPE_STRINGS[ft - min];
}


/*
 */
LIBSBML_EXTERN
FbcType_t
FbcType_fromString(const char* code)
{
  static int size =
    sizeof(SBML_FBC_TYPE_STRINGS)/sizeof(SBML_FBC_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_FBC_TYPE_STRINGS[i])
    {
      return (FbcType_t)(i);
    }
  }

  return FBC_TYPE_INVALID;
}


/*
 */
LIBSBML_EXTERN
int
FbcType_isValid(FbcType_t ft)
{
  int min = OBJECTIVE_TYPE_MAXIMIZE;
  int max = FBC_TYPE_INVALID;

  if (ft < min || ft >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 */
LIBSBML_EXTERN
int
FbcType_isValidString(const char* code)
{
  return FbcType_isValid(FbcType_fromString(code));
}




LIBSBML_CPP_NAMESPACE_END


