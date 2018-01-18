/**
 * @file MultiExtension.cpp
 * @brief Implementation of MultiExtension.
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

#include <sbml/packages/multi/extension/MultiExtension.h>
#include <sbml/packages/multi/extension/MultiSBMLDocumentPlugin.h>
#include <sbml/packages/multi/validator/MultiSBMLErrorTable.h>
#include <sbml/packages/multi/extension/MultiModelPlugin.h>
#include <sbml/packages/multi/extension/MultiCompartmentPlugin.h>
#include <sbml/packages/multi/extension/MultiSpeciesPlugin.h>
#include <sbml/packages/multi/extension/MultiSimpleSpeciesReferencePlugin.h>
#include <sbml/packages/multi/extension/MultiSpeciesReferencePlugin.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
 * libSBML extension.
 */
const std::string&
MultiExtension::getPackageName()
{
  static const std::string pkgName = "multi";
  return pkgName;
}


/*
 * Returns the default SBML Level implemented by this libSBML extension.
 */
unsigned int
MultiExtension::getDefaultLevel()
{
  return 3;
}


/*
 * Returns the default SBML Version implemented by this libSBML extension.
 */
unsigned int
MultiExtension::getDefaultVersion()
{
  return 1;
}


/*
 * Returns the default version of the SBML Level&nbsp;3 package implemented by
 * this libSBML extension.
 */
unsigned int
MultiExtension::getDefaultPackageVersion()
{
  return 1;
}


/*
 * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
 * by this libSBML extension.
 */
const std::string&
MultiExtension::getXmlnsL3V1V1()
{
  static const std::string xmlns =
    "http://www.sbml.org/sbml/level3/version1/multi/version1";
  return xmlns;
}


/**
 *
 * Adds this MultiExtension to the SBMLExtensionRegistry class
 *
 */
static SBMLExtensionRegister<MultiExtension> multiExtensionRegistry;

static
const char* SBML_MULTI_TYPECODE_STRINGS[] =
{
    "PossibleSpeciesFeatureValue"
  , "CompartmentReference"
  , "SpeciesTypeInstance"
  , "InSpeciesTypeBond"
  , "OutwardBindingSite"
  , "SpeciesFeatureType"
  , "SpeciesTypeComponentIndex"
  , "SpeciesFeature"
  , "SpeciesFeatureValue"
  , "SpeciesTypeComponentMapInProduct"
  , "MultiSpeciesType"
  , "IntraSpeciesReaction"
  , "BindingSiteSpeciesType"
  , "SubListOfSpeciesFeatures"
};


/**
 *
 * Instantiate SBMLExtensionNamespaces<MultiExtension> for DLL
 *
 */
template class LIBSBML_EXTERN SBMLExtensionNamespaces<MultiExtension>;

/*
 * Creates a new MultiExtension instance.
 */
MultiExtension::MultiExtension()
{
}


/*
 * Copy constructor for MultiExtension.
 */
MultiExtension::MultiExtension(const MultiExtension& orig)
  : SBMLExtension( orig )
{
}


/*
 * Assignment operator for MultiExtension.
 */
MultiExtension&
MultiExtension::operator=(const MultiExtension& rhs)
{
  if (&rhs != this)
  {
    SBMLExtension::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MultiExtension object.
 */
MultiExtension*
MultiExtension::clone() const
{
  return new MultiExtension(*this);
}


/*
 * Destructor for MultiExtension.
 */
MultiExtension::~MultiExtension()
{
}


/*
 * Returns the name of this SBML Level&nbsp;3 package ("multi").
 */
const std::string&
MultiExtension::getName() const
{
  return getPackageName();
}


/*
 * Returns a string representing the SBML XML namespace of this SBML
 * Level&nbsp;3 package.
 */
const std::string&
MultiExtension::getURI(unsigned int sbmlLevel,
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
MultiExtension::getLevel(const std::string& uri) const
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
MultiExtension::getVersion(const std::string& uri) const
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
MultiExtension::getPackageVersion(const std::string& uri) const
{
  if (uri == getXmlnsL3V1V1())
  {
    return 1;
  }

  return 0;
}


/*
 * Returns a MultiPkgNamespaces object.
 */
SBMLNamespaces*
MultiExtension::getSBMLExtensionNamespaces(const std::string& uri) const
{
  MultiPkgNamespaces* pkgns = NULL;

  if (uri == getXmlnsL3V1V1())
  {
    pkgns = new MultiPkgNamespaces(3, 1, 1);
  }

  return pkgns;
}


/*
 * Takes a type code of the &ldquo;multi&rdquo; package and returns a string
 * describing the code.
 */
const char*
MultiExtension::getStringFromTypeCode(int typeCode) const
{
  int min = SBML_MULTI_POSSIBLE_SPECIES_FEATURE_VALUE;
  int max = SBML_MULTI_SUBLISTOFSPECIESFEATURES;

  if (typeCode < min || typeCode > max)
  {
    return "(Unknown SBML Multi Type)";
  }

  return SBML_MULTI_TYPECODE_STRINGS[typeCode - min];
}



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the entry in the error table at this index.
 */
packageErrorTableEntry
MultiExtension::getErrorTable(unsigned int index) const
{
  return multiErrorTable[index];
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Return the index in the error table with the given errorId.
 */
unsigned int
MultiExtension::getErrorTableIndex(unsigned int errorId) const
{
  unsigned int tableSize = sizeof(multiErrorTable)/sizeof(multiErrorTable[0]);
  unsigned int index = 0;

  for (unsigned int i = 0; i < tableSize; i++)
  {
    if (errorId == multiErrorTable[i].code)
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
 * Returns the offset for the errorId range for the "multi" package.
 */
unsigned int
MultiExtension::getErrorIdOffset() const
{
  return 7000000;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Initializes multi extension by creating an object of this class with the
 * required SBasePlugin derived objects and registering the object to the
 * SBMLExtensionRegistry class
 */
void
MultiExtension::init()
{
  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))
  {
    return;
  }

  MultiExtension multiExtension;


  std::vector<std::string> packageURIs;

  packageURIs.push_back(getXmlnsL3V1V1());

  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);
  SBaseExtensionPoint modelExtPoint("core", SBML_MODEL);
  SBaseExtensionPoint compartmentExtPoint("core", SBML_COMPARTMENT);
  SBaseExtensionPoint speciesExtPoint("core", SBML_SPECIES);
  SBaseExtensionPoint simplespeciesreferenceExtPoint("core",
    SBML_SIMPLE_SPECIES_REFERENCE);
  SBaseExtensionPoint speciesreferenceExtPoint("core", SBML_SPECIES_REFERENCE);

  SBasePluginCreator<MultiSBMLDocumentPlugin, MultiExtension>
    sbmldocPluginCreator(sbmldocExtPoint, packageURIs);
  SBasePluginCreator<MultiModelPlugin, MultiExtension>
    modelPluginCreator(modelExtPoint, packageURIs);
  SBasePluginCreator<MultiCompartmentPlugin, MultiExtension>
    compartmentPluginCreator(compartmentExtPoint, packageURIs);
  SBasePluginCreator<MultiSpeciesPlugin, MultiExtension>
    speciesPluginCreator(speciesExtPoint, packageURIs);
  SBasePluginCreator<MultiSimpleSpeciesReferencePlugin, MultiExtension>
    simplespeciesreferencePluginCreator(simplespeciesreferenceExtPoint,
      packageURIs);
  SBasePluginCreator<MultiSpeciesReferencePlugin, MultiExtension>
    speciesreferencePluginCreator(speciesreferenceExtPoint, packageURIs);

  multiExtension.addSBasePluginCreator(&sbmldocPluginCreator);
  multiExtension.addSBasePluginCreator(&modelPluginCreator);
  multiExtension.addSBasePluginCreator(&compartmentPluginCreator);
  multiExtension.addSBasePluginCreator(&speciesPluginCreator);
  multiExtension.addSBasePluginCreator(&simplespeciesreferencePluginCreator);
  multiExtension.addSBasePluginCreator(&speciesreferencePluginCreator);

  SBMLExtensionRegistry::getInstance().addExtension(&multiExtension);
}

/** @endcond */




#endif /* __cplusplus */


static
const char* SBML_BINDING_STATUS_STRINGS[] =
{
  "bound"
, "unbound"
, "either"
, "invalid BindingStatus"
};


/*
 * Returns the string version of the provided #BindingStatus_t enumeration.
 */
LIBSBML_EXTERN
const char*
BindingStatus_toString(BindingStatus_t bs)
{
  int min = MULTI_BINDING_STATUS_BOUND;
  int max = BINDING_STATUS_INVALID;

  if (bs < min || bs > max)
  {
    return "(Unknown BindingStatus value)";
  }

  return SBML_BINDING_STATUS_STRINGS[bs - min];
}


/*
 * Returns the #BindingStatus_t enumeration corresponding to the given string
 * or @sbmlconstant{BINDING_STATUS_INVALID, BindingStatus_t} if there is no
 * such match.
 */
LIBSBML_EXTERN
BindingStatus_t
BindingStatus_fromString(const char* code)
{
  static int size =
    sizeof(SBML_BINDING_STATUS_STRINGS)/sizeof(SBML_BINDING_STATUS_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_BINDING_STATUS_STRINGS[i])
    {
      return (BindingStatus_t)(i);
    }
  }

  return BINDING_STATUS_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #BindingStatus_t is valid.
 */
LIBSBML_EXTERN
int
BindingStatus_isValid(BindingStatus_t bs)
{
  int min = MULTI_BINDING_STATUS_BOUND;
  int max = BINDING_STATUS_INVALID;

  if (bs < min || bs >= max)
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
 * given string is a valid #BindingStatus_t.
 */
LIBSBML_EXTERN
int
BindingStatus_isValidString(const char* code)
{
  return BindingStatus_isValid(BindingStatus_fromString(code));
}


static
const char* SBML_RELATION_STRINGS[] =
{
  "and"
, "or"
, "not"
, "invalid Relation"
};


/*
 * Returns the string version of the provided #Relation_t enumeration.
 */
LIBSBML_EXTERN
const char*
Relation_toString(Relation_t r)
{
  int min = MULTI_RELATION_AND;
  int max = RELATION_INVALID;

  if (r < min || r > max)
  {
    return "(Unknown Relation value)";
  }

  return SBML_RELATION_STRINGS[r - min];
}


/*
 * Returns the #Relation_t enumeration corresponding to the given string or
 * @sbmlconstant{RELATION_INVALID, Relation_t} if there is no such match.
 */
LIBSBML_EXTERN
Relation_t
Relation_fromString(const char* code)
{
  static int size =
    sizeof(SBML_RELATION_STRINGS)/sizeof(SBML_RELATION_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_RELATION_STRINGS[i])
    {
      return (Relation_t)(i);
    }
  }

  return RELATION_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Relation_t is valid.
 */
LIBSBML_EXTERN
int
Relation_isValid(Relation_t r)
{
  int min = MULTI_RELATION_AND;
  int max = RELATION_INVALID;

  if (r < min || r >= max)
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
 * given string is a valid #Relation_t.
 */
LIBSBML_EXTERN
int
Relation_isValidString(const char* code)
{
  return Relation_isValid(Relation_fromString(code));
}


static
const char* SBML_REPRESENTATION_TYPE_STRINGS[] =
{
  "sum"
, "numericValue"
, "invalid RepresentationType"
};


/*
 * Returns the string version of the provided #RepresentationType_t
 * enumeration.
 */
LIBSBML_EXTERN
const char*
RepresentationType_toString(RepresentationType_t rt)
{
  int min = MULTI_REPRESENTATIONTYPE_SUM;
  int max = REPRESENTATION_TYPE_INVALID;

  if (rt < min || rt > max)
  {
    return "(Unknown RepresentationType value)";
  }

  return SBML_REPRESENTATION_TYPE_STRINGS[rt - min];
}


/*
 * Returns the #RepresentationType_t enumeration corresponding to the given
 * string or @sbmlconstant{REPRESENTATION_TYPE_INVALID, RepresentationType_t}
 * if there is no such match.
 */
LIBSBML_EXTERN
RepresentationType_t
RepresentationType_fromString(const char* code)
{
  static int size =
    sizeof(SBML_REPRESENTATION_TYPE_STRINGS)/sizeof(SBML_REPRESENTATION_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBML_REPRESENTATION_TYPE_STRINGS[i])
    {
      return (RepresentationType_t)(i);
    }
  }

  return REPRESENTATION_TYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #RepresentationType_t is valid.
 */
LIBSBML_EXTERN
int
RepresentationType_isValid(RepresentationType_t rt)
{
  int min = MULTI_REPRESENTATIONTYPE_SUM;
  int max = REPRESENTATION_TYPE_INVALID;

  if (rt < min || rt >= max)
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
 * given string is a valid #RepresentationType_t.
 */
LIBSBML_EXTERN
int
RepresentationType_isValidString(const char* code)
{
  return RepresentationType_isValid(RepresentationType_fromString(code));
}




LIBSBML_CPP_NAMESPACE_END


