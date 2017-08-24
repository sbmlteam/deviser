/**
 * @file CoreverspkgExtension.cpp
 * @brief Implementation of CoreverspkgExtension.
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

#include <sbml/packages/coreverspkg/extension/CoreverspkgExtension.h>
#include <sbml/packages/coreverspkg/extension/CoreverspkgSBMLDocumentPlugin.h>
#include <sbml/packages/coreverspkg/validator/CoreverspkgSBMLErrorTable.h>
#include <sbml/packages/coreverspkg/extension/CoreverspkgModelPlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
CoreverspkgExtension::getPackageName()
{
  static const std::string pkgName = "coreverspkg";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
CoreverspkgExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
CoreverspkgExtension::getDefaultVersion()
{
  return 2;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
CoreverspkgExtension::getDefaultPackageVersion()
{
  return 2;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
CoreverspkgExtension::getXmlnsL3V2V2()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version2/coreverspkg/version2";
  return xmlns;
}


/**
 *
 * Adds this CoreverspkgExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<CoreverspkgExtension>
  coreverspkgExtensionRegistry;

static
const char* SBML_COREVERSPKG_TYPECODE_STRINGS[] =
{
    "ClassOneTwo"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<CoreverspkgExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<CoreverspkgExtension>;

/*
 * Creates a new CoreverspkgExtension instance.
 */
CoreverspkgExtension::CoreverspkgExtension()
{
}


/*
 * Copy constructor for CoreverspkgExtension.
 */
CoreverspkgExtension::CoreverspkgExtension(const CoreverspkgExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for CoreverspkgExtension.
 */
CoreverspkgExtension&
CoreverspkgExtension::operator=(const CoreverspkgExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CoreverspkgExtension object.
 */
CoreverspkgExtension*
CoreverspkgExtension::clone() const
{
  return new CoreverspkgExtension(*this);
}


/*
 * Destructor for CoreverspkgExtension.
 */
CoreverspkgExtension::~CoreverspkgExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("coreverspkg").
 */
const std::string&
CoreverspkgExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
CoreverspkgExtension::getURI(unsigned int sbmlLevel,
                             unsigned int sbmlVersion,
                             unsigned int pkgVersion) const
{
  if (sbmlLevel == 3)
  {
    if (sbmlVersion == 2)
    {
      if (pkgVersion == 2)
      {
        return getXmlnsL3V2V2();
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
CoreverspkgExtension::getLevel(const std::string& uri) const
{
  if (uri == getXmlnsL3V2V2())
  {
    return 3;
  }

  return 0;
}


/*
 * Returns the Version within the SBML Level for the given URI of this package.
 */
unsigned int
CoreverspkgExtension::getVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V2V2())
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
CoreverspkgExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V2V2())
  {
    return 2;
  }

  return 0;
}


/*
 * Returns a CoreverspkgPkgNamespaces object.
 */
SBMLNamespaces*
CoreverspkgExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  CoreverspkgPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V2V2())
  {
    pkgns = new CoreverspkgPkgNamespaces(3, 2, 2);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;coreverspkg&rdquo; package and returns a
 * string describing the code.
 */
const char*
CoreverspkgExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_COREVERS_CLASSONETWO;
  int max = SBML_COREVERS_CLASSONETWO;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Coreverspkg Type)";
  }

  return SBML_COREVERSPKG_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
CoreverspkgExtension::getErrorTable(unsigned int index) const
{
  return coreverspkgErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
CoreverspkgExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize =
    sizeof(coreverspkgErrorTable)/sizeof(coreverspkgErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == coreverspkgErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "coreverspkg" package.
 */
unsigned int
CoreverspkgExtension::getErrorIdOffset() const
{
  return 10000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes coreverspkg extension by creating an object of this class with
 * the required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
CoreverspkgExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  CoreverspkgExtension coreverspkgExtension;


  std::vector<std::string> packageURIs;

  packageURIs.push_back(getXmlnsL3V2V2());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);

  SBasePluginCreator<CoreverspkgSBMLDocumentPlugin, CoreverspkgExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<CoreverspkgModelPlugin, CoreverspkgExtension>
    modelPluginCreator(modelExtPoint, packageURIs);

  coreverspkgExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  coreverspkgExtension.addSBasePluginCreator(&modelPluginCreator);

  int result =
    SBMLExtensionRegistry::getInstance().addExtension(&coreverspkgExtension);
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


