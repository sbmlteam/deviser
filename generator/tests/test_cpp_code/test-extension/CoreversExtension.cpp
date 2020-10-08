/**
 * @file CoreversExtension.cpp
 * @brief Implementation of CoreversExtension.
 * @author SBMLTeam
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
#include <sbml/extension/SBMLExtensionRegister.h>
#include <sbml/extension/SBMLExtensionRegistry.h>
#include <sbml/extension/SBasePluginCreator.h>
#include <sbml/extension/SBMLDocumentPlugin.h>

#include <sbml/packages/corevers/extension/CoreversExtension.h>
#include <sbml/packages/corevers/extension/CoreversSBMLDocumentPlugin.h>
#include <sbml/packages/corevers/validator/CoreversSBMLErrorTable.h>
#include <sbml/packages/corevers/extension/CoreversModelPlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
CoreversExtension::getPackageName()
{
  static const std::string pkgName = "corevers";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
CoreversExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
CoreversExtension::getDefaultVersion()
{
  return 2;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
CoreversExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
CoreversExtension::getXmlnsL3V2V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version2/corevers/version1";
  return xmlns;
}


/**
 *
 * Adds this CoreversExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<CoreversExtension> coreversExtensionRegistry;

static
const char* SBML_COREVERS_TYPECODE_STRINGS[] =
{
    "ClassOneTwo"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<CoreversExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<CoreversExtension>;

/*
 * Creates a new CoreversExtension instance.
 */
CoreversExtension::CoreversExtension()
{
}


/*
 * Copy constructor for CoreversExtension.
 */
CoreversExtension::CoreversExtension(const CoreversExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for CoreversExtension.
 */
CoreversExtension&
CoreversExtension::operator=(const CoreversExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CoreversExtension object.
 */
CoreversExtension*
CoreversExtension::clone() const
{
  return new CoreversExtension(*this);
}


/*
 * Destructor for CoreversExtension.
 */
CoreversExtension::~CoreversExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("corevers").
 */
const std::string&
CoreversExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
CoreversExtension::getURI(unsigned int sbmlLevel,
                          unsigned int sbmlVersion,
                          unsigned int pkgVersion) const
{
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
CoreversExtension::getLevel(const std::string& uri) const
{
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
CoreversExtension::getVersion(const std::string& uri) const
{
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
CoreversExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V2V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns a CoreversPkgNamespaces object.
 */
SBMLNamespaces*
CoreversExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  CoreversPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V2V1())
  {
    pkgns = new CoreversPkgNamespaces(3, 2, 1);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;corevers&rdquo; package and returns a string
 * describing the code.
 */
const char*
CoreversExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_COREVERS_CLASSONETWO;
  int max = SBML_COREVERS_CLASSONETWO;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Corevers Type)";
  }

  return SBML_COREVERS_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
CoreversExtension::getErrorTable(unsigned int index) const
{
  return coreversErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
CoreversExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize =
    sizeof(coreversErrorTable)/sizeof(coreversErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == coreversErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "corevers" package.
 */
unsigned int
CoreversExtension::getErrorIdOffset() const
{
  return 10000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes corevers extension by creating an object of this class with the
 * required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
CoreversExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  CoreversExtension coreversExtension;


  std::vector<std::string> packageURIs;

  packageURIs.push_back(getXmlnsL3V2V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);

  SBasePluginCreator<CoreversSBMLDocumentPlugin, CoreversExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<CoreversModelPlugin, CoreversExtension>
    modelPluginCreator(modelExtPoint, packageURIs);

  coreversExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  coreversExtension.addSBasePluginCreator(&modelPluginCreator);

  SBMLExtensionRegistry::getInstance().addExtension(&coreversExtension);
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


