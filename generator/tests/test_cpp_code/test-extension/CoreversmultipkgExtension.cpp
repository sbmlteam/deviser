/**
 * @file CoreversmultipkgExtension.cpp
 * @brief Implementation of CoreversmultipkgExtension.
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

#include <sbml/packages/coreversmultipkg/extension/CoreversmultipkgExtension.h>
#include <sbml/packages/coreversmultipkg/extension/CoreversmultipkgSBMLDocumentPlugin.h>
#include <sbml/packages/coreversmultipkg/validator/CoreversmultipkgSBMLErrorTable.h>
#include <sbml/packages/coreversmultipkg/extension/CoreversmultipkgModelPlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
CoreversmultipkgExtension::getPackageName()
{
  static const std::string pkgName = "coreversmultipkg";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
CoreversmultipkgExtension::getDefaultLevel()
{
  return 4;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
CoreversmultipkgExtension::getDefaultVersion()
{
  return 1;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
CoreversmultipkgExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
CoreversmultipkgExtension::getXmlnsL3V1V2()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/coreversmultipkg/version2";
  return xmlns;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
CoreversmultipkgExtension::getXmlnsL3V2V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version2/coreversmultipkg/version1";
  return xmlns;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
CoreversmultipkgExtension::getXmlnsL3V2V2()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version2/coreversmultipkg/version2";
  return xmlns;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
CoreversmultipkgExtension::getXmlnsL4V1V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level4/version1/coreversmultipkg/version1";
  return xmlns;
}


/**
 *
 * Adds this CoreversmultipkgExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<CoreversmultipkgExtension>
  coreversmultipkgExtensionRegistry;

static
const char* SBML_COREVERSMULTIPKG_TYPECODE_STRINGS[] =
{
    "ClassOneTwo"
  , "ClassMult"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<CoreversmultipkgExtension> for DLL
 *
 */
template class LIBSBML_EXTERN
  SBMLExtensionNamespaces<CoreversmultipkgExtension>;

/*
 * Creates a new CoreversmultipkgExtension instance.
 */
CoreversmultipkgExtension::CoreversmultipkgExtension()
{
}


/*
 * Copy constructor for CoreversmultipkgExtension.
 */
CoreversmultipkgExtension::CoreversmultipkgExtension(const
  CoreversmultipkgExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for CoreversmultipkgExtension.
 */
CoreversmultipkgExtension&
CoreversmultipkgExtension::operator=(const CoreversmultipkgExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CoreversmultipkgExtension object.
 */
CoreversmultipkgExtension*
CoreversmultipkgExtension::clone() const
{
  return new CoreversmultipkgExtension(*this);
}


/*
 * Destructor for CoreversmultipkgExtension.
 */
CoreversmultipkgExtension::~CoreversmultipkgExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("coreversmultipkg").
 */
const std::string&
CoreversmultipkgExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
CoreversmultipkgExtension::getURI(unsigned int sbmlLevel,
                                  unsigned int sbmlVersion,
                                  unsigned int pkgVersion) const
{
  if (sbmlLevel == 3)
  {
    if (sbmlVersion == 1)
    {
      if (pkgVersion == 2)
      {
        return getXmlnsL3V1V2();
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

  if (sbmlLevel == 4)
  {
    if (sbmlVersion == 1)
    {
      if (pkgVersion == 1)
      {
        return getXmlnsL4V1V1();
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
CoreversmultipkgExtension::getLevel(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V2())
  {
    return 3;
  }

  if (uri == getXmlnsL3V2V1())
  {
    return 3;
  }

  if (uri == getXmlnsL3V2V2())
  {
    return 3;
  }

  if (uri == getXmlnsL4V1V1())
  {
    return 4;
  }

  return 0;
}


/*
 * Returns the Version within the SBML Level for the given URI of this package.
 */
unsigned int
CoreversmultipkgExtension::getVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V2())
  {
    return 1;
  }

  if (uri == getXmlnsL3V2V1())
  {
    return 2;
  }

  if (uri == getXmlnsL3V2V2())
  {
    return 2;
  }

  if (uri == getXmlnsL4V1V1())
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
CoreversmultipkgExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V2())
  {
    return 2;
  }

  if (uri == getXmlnsL3V2V1())
  {
    return 1;
  }

  if (uri == getXmlnsL3V2V2())
  {
    return 2;
  }

  if (uri == getXmlnsL4V1V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns a CoreversmultipkgPkgNamespaces object.
 */
SBMLNamespaces*
CoreversmultipkgExtension::getSBMLExtensionNamespaces(const std::string& uri)
  const
{
  CoreversmultipkgPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V1V2())
  {
    pkgns = new CoreversmultipkgPkgNamespaces(3, 1, 2);
  }

  if (uri == getXmlnsL3V2V1())
  {
    pkgns = new CoreversmultipkgPkgNamespaces(3, 2, 1);
  }

  if (uri == getXmlnsL3V2V2())
  {
    pkgns = new CoreversmultipkgPkgNamespaces(3, 2, 2);
  }

  if (uri == getXmlnsL4V1V1())
  {
    pkgns = new CoreversmultipkgPkgNamespaces(4, 1, 1);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;coreversmultipkg&rdquo; package and returns
 * a string describing the code.
 */
const char*
CoreversmultipkgExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_COREVERS_CLASSONETWO;
  int max = SBML_COREVERS_CLASSONETWO;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Coreversmultipkg Type)";
  }

  return SBML_COREVERSMULTIPKG_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
CoreversmultipkgExtension::getErrorTable(unsigned int index) const
{
  return coreversmultipkgErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
CoreversmultipkgExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize =
    sizeof(coreversmultipkgErrorTable)/sizeof(coreversmultipkgErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == coreversmultipkgErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "coreversmultipkg" package.
 */
unsigned int
CoreversmultipkgExtension::getErrorIdOffset() const
{
  return 10000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns true if the package has multiple versions.
 */
bool
CoreversmultipkgExtension::hasMultipleVersions() const
{
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes coreversmultipkg extension by creating an object of this class
 * with the required SBasePlugin derived objects and registering the object to
 * the SBMLExtensionRegistry class
 */
void
CoreversmultipkgExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  CoreversmultipkgExtension coreversmultipkgExtension;


  std::vector<std::string> packageURIs;

  packageURIs.push_back(getXmlnsL3V1V2());

  packageURIs.push_back(getXmlnsL3V2V1());

  packageURIs.push_back(getXmlnsL3V2V2());

  packageURIs.push_back(getXmlnsL4V1V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);

  SBasePluginCreator<CoreversmultipkgSBMLDocumentPlugin,
    CoreversmultipkgExtension> sbmldocPluginCreator(sbmldocExtPoint,
      packageURIs);
  SBasePluginCreator<CoreversmultipkgModelPlugin, CoreversmultipkgExtension>
    modelPluginCreator(modelExtPoint, packageURIs);

  coreversmultipkgExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  coreversmultipkgExtension.addSBasePluginCreator(&modelPluginCreator);

  int result =
    SBMLExtensionRegistry::getInstance().addExtension(&coreversmultipkgExtension);
}

/** @endcond */




#endif /* __cplusplus */


static
const char* SBML_ABC_TYPE_STRINGS[] =
{
  "maximize"
, "minimize"
, "invalid AbcType"
};


/*
 */
LIBSBML_EXTERN
const char*
AbcType_toString(AbcType_t at)
{
  int min = OBJECTIVE_TYPE_MAXIMIZE;
  int max = ABC_TYPE_INVALID;

  if (at < min || at > max)
  {
    return "(Unknown AbcType value)";
  }

  return SBML_ABC_TYPE_STRINGS[at - min];
}


/*
 */
LIBSBML_EXTERN
AbcType_t
AbcType_fromString(const char* code)
{
  static int size =
    sizeof(SBML_ABC_TYPE_STRINGS)/sizeof(SBML_ABC_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_ABC_TYPE_STRINGS[i])
    {
      return (AbcType_t)(i);
    }
  }

  return ABC_TYPE_INVALID;
}


/*
 */
LIBSBML_EXTERN
int
AbcType_isValid(AbcType_t at)
{
  int min = OBJECTIVE_TYPE_MAXIMIZE;
  int max = ABC_TYPE_INVALID;

  if (at < min || at >= max)
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
AbcType_isValidString(const char* code)
{
  return AbcType_isValid(AbcType_fromString(code));
}




LIBSBML_CPP_NAMESPACE_END


