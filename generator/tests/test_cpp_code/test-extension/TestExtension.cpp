/**
 * @file TestExtension.cpp
 * @brief Implementation of TestExtension.
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

#include <sbml/packages/test/extension/TestExtension.h>
#include <sbml/packages/test/extension/TestSBMLDocumentPlugin.h>
#include <sbml/packages/test/validator/TestSBMLErrorTable.h>
#include <sbml/packages/test/extension/TestModelPlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
TestExtension::getPackageName()
{
  static const std::string pkgName = "test";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
TestExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
TestExtension::getDefaultVersion()
{
  return 1;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
TestExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
TestExtension::getXmlnsL3V1V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/test/version1";
  return xmlns;
}


/**
 *
 * Adds this TestExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<TestExtension> testExtensionRegistry;

static
const char* SBML_TEST_TYPECODE_STRINGS[] =
{
    "MyBase"
  , "ClassTwo"
  , "ClassThree"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<TestExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<TestExtension>;

/*
 * Creates a new TestExtension instance.
 */
TestExtension::TestExtension()
{
}


/*
 * Copy constructor for TestExtension.
 */
TestExtension::TestExtension(const TestExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for TestExtension.
 */
TestExtension&
TestExtension::operator=(const TestExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this TestExtension object.
 */
TestExtension*
TestExtension::clone() const
{
  return new TestExtension(*this);
}


/*
 * Destructor for TestExtension.
 */
TestExtension::~TestExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("test").
 */
const std::string&
TestExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
TestExtension::getURI(unsigned int sbmlLevel,
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
TestExtension::getLevel(const std::string& uri) const
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
TestExtension::getVersion(const std::string& uri) const
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
TestExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns a TestPkgNamespaces object.
 */
SBMLNamespaces*
TestExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  TestPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V1V1())
  {
    pkgns = new TestPkgNamespaces(3, 1, 1);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;test&rdquo; package and returns a string
 * describing the code.
 */
const char*
TestExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_TEST_MYBASE;
  int max = SBML_TEST_CLASSTHREE;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Test Type)";
  }

  return SBML_TEST_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
TestExtension::getErrorTable(unsigned int index) const
{
  return testErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
TestExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize = sizeof(testErrorTable)/sizeof(testErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == testErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "test" package.
 */
unsigned int
TestExtension::getErrorIdOffset() const
{
  return 10000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes test extension by creating an object of this class with the
 * required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
TestExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  TestExtension testExtension;


  std::vector<std::string> packageURIs;
  packageURIs.push_back(getXmlnsL3V1V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);

  SBasePluginCreator<TestSBMLDocumentPlugin, TestExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<TestModelPlugin, TestExtension>
    modelPluginCreator(modelExtPoint, packageURIs);

  testExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  testExtension.addSBasePluginCreator(&modelPluginCreator);

  int result =
    SBMLExtensionRegistry::getInstance().addExtension(&testExtension);
}

/** @endcond */




#endif /* __cplusplus */


static
const char* SBML_ENUM_STRINGS[] =
{
  "One"
, "Two"
, "invalid Enum"
};


/*
 */
LIBSBML_EXTERN
const char*
Enum_toString(Enum_t e)
{
  int min = TEST_ENUM_ONE;
  int max = ENUM_INVALID;

  if (e < min || e > max)
  {
    return "(Unknown Enum value)";
  }

  return SBML_ENUM_STRINGS[e - min];
}


/*
 */
LIBSBML_EXTERN
Enum_t
Enum_fromString(const char* code)
{
  static int size = sizeof(SBML_ENUM_STRINGS)/sizeof(SBML_ENUM_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_ENUM_STRINGS[i])
    {
      return (Enum_t)(i);
    }
  }

  return ENUM_INVALID;
}


/*
 */
LIBSBML_EXTERN
int
Enum_isValid(Enum_t e)
{
  int min = TEST_ENUM_ONE;
  int max = ENUM_INVALID;

  if (e < min || e >= max)
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
Enum_isValidString(const char* code)
{
  return Enum_isValid(Enum_fromString(code));
}


static
const char* SBML_FRED_STRINGS[] =
{
  "tom"
, "dick"
, "invalid Fred"
};


/*
 */
LIBSBML_EXTERN
const char*
Fred_toString(Fred_t f)
{
  int min = TEST_FRED_T_TOM;
  int max = FRED_INVALID;

  if (f < min || f > max)
  {
    return "(Unknown Fred value)";
  }

  return SBML_FRED_STRINGS[f - min];
}


/*
 */
LIBSBML_EXTERN
Fred_t
Fred_fromString(const char* code)
{
  static int size = sizeof(SBML_FRED_STRINGS)/sizeof(SBML_FRED_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_FRED_STRINGS[i])
    {
      return (Fred_t)(i);
    }
  }

  return FRED_INVALID;
}


/*
 */
LIBSBML_EXTERN
int
Fred_isValid(Fred_t f)
{
  int min = TEST_FRED_T_TOM;
  int max = FRED_INVALID;

  if (f < min || f >= max)
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
Fred_isValidString(const char* code)
{
  return Fred_isValid(Fred_fromString(code));
}




LIBSBML_CPP_NAMESPACE_END


