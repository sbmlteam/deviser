/**
 * @file TwoatonceExtension.cpp
 * @brief Implementation of TwoatonceExtension.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2017 jointly by the following organizations:
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

#include <sbml/packages/twoatonce/extension/TwoatonceExtension.h>
#include <sbml/packages/twoatonce/extension/TwoatonceSBMLDocumentPlugin.h>
#include <sbml/packages/twoatonce/validator/TwoatonceSBMLErrorTable.h>
#include <sbml/packages/twoatonce/extension/TwoatonceSBasePlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
TwoatonceExtension::getPackageName()
{
  static const std::string pkgName = "twoatonce";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
TwoatonceExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
TwoatonceExtension::getDefaultVersion()
{
  return 2;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
TwoatonceExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
TwoatonceExtension::getXmlnsL3V1V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/twoatonce/version1";
  return xmlns;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
TwoatonceExtension::getXmlnsL3V2V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version2/twoatonce/version1";
  return xmlns;
}


/**
 *
 * Adds this TwoatonceExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<TwoatonceExtension> twoatonceExtensionRegistry;

static
const char* SBML_TWOATONCE_TYPECODE_STRINGS[] =
{
    "NormalClass"
  , "ClassWithRequiredID"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<TwoatonceExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<TwoatonceExtension>;

/*
 * Creates a new TwoatonceExtension instance.
 */
TwoatonceExtension::TwoatonceExtension()
{
}


/*
 * Copy constructor for TwoatonceExtension.
 */
TwoatonceExtension::TwoatonceExtension(const TwoatonceExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for TwoatonceExtension.
 */
TwoatonceExtension&
TwoatonceExtension::operator=(const TwoatonceExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this TwoatonceExtension object.
 */
TwoatonceExtension*
TwoatonceExtension::clone() const
{
  return new TwoatonceExtension(*this);
}


/*
 * Destructor for TwoatonceExtension.
 */
TwoatonceExtension::~TwoatonceExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("twoatonce").
 */
const std::string&
TwoatonceExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
TwoatonceExtension::getURI(unsigned int sbmlLevel,
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

  if (sbmlLevel == 3)
  {
    if (sbmlVersion == 2)
    {
      if (pkgVersion == 1)
      {
        return getXmlnsL3V2V1();
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
TwoatonceExtension::getLevel(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 3;
  }

  if (uri == getXmlnsL3V2V1())
  {
    return 3;
  }

  return 0;
}


/*
 * Returns the Version within the SBML Level for the given URI of this package.
 */
unsigned int
TwoatonceExtension::getVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }

  if (uri == getXmlnsL3V2V1())
  {
    return 2;
  }

  return 0;
}


/*
 * Returns the SBML Level&nbsp;3 package version for the given URI of this
 * package.
 */
unsigned int
TwoatonceExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }

  if (uri == getXmlnsL3V2V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns a TwoatoncePkgNamespaces object.
 */
SBMLNamespaces*
TwoatonceExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  TwoatoncePkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V1V1())
  {
    pkgns = new TwoatoncePkgNamespaces(3, 1, 1);
  }

  if (uri == getXmlnsL3V2V1())
  {
    pkgns = new TwoatoncePkgNamespaces(3, 2, 1);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;twoatonce&rdquo; package and returns a
 * string describing the code.
 */
const char*
TwoatonceExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_TWOATONCE_NORMALCLASS;
  int max = SBML_TWOATONCE_CLASSWITHREQUIREDID;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Twoatonce Type)";
  }

  return SBML_TWOATONCE_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
TwoatonceExtension::getErrorTable(unsigned int index) const
{
  return twoatonceErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
TwoatonceExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize =
    sizeof(twoatonceErrorTable)/sizeof(twoatonceErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == twoatonceErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "twoatonce" package.
 */
unsigned int
TwoatonceExtension::getErrorIdOffset() const
{
  return 2000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns true if the package has multiple versions.
 */
bool
TwoatonceExtension::hasMultipleVersions() const
{
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes twoatonce extension by creating an object of this class with the
 * required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
TwoatonceExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  TwoatonceExtension twoatonceExtension;


  std::vector<std::string> packageURIs;

  packageURIs.push_back(getXmlnsL3V1V1());

  packageURIs.push_back(getXmlnsL3V2V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint sbaseExtPoint("all", SBML_GENERIC_SBASE);

  SBasePluginCreator<TwoatonceSBMLDocumentPlugin, TwoatonceExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<TwoatonceSBasePlugin, TwoatonceExtension>
    sbasePluginCreator(sbaseExtPoint, packageURIs);

  twoatonceExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  twoatonceExtension.addSBasePluginCreator(&sbasePluginCreator);

  SBMLExtensionRegistry::getInstance().addExtension(&twoatonceExtension);
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


