/**
 * @file: VersExtension.h
 * @brief: Definition of VersExtension.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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


#ifndef VersExtension_H__
#define VersExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef VERS_CREATE_NS
#define VERS_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(VersPkgNamespaces, variable, sbmlns);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN VersExtension : public SBMLExtension
{
public:

  /**
   * Returns the packageName used by this libSBML package extension.
   *
   * @return the packageName as a string.
   */
  static const std::string& getPackageName();


  /**
   * Returns the defaultLevel used by this libSBML package extension.
   *
   * @return the defaultLevel as a unsigned integer.
   */
  static unsigned int getDefaultLevel();


  /**
   * Returns the defaultVersion used by this libSBML package extension.
   *
   * @return the defaultVersion as a unsigned integer.
   */
  static unsigned int getDefaultVersion();


  /**
   * Returns the defaultPackageVersion used by this libSBML package extension.
   *
   * @return the defaultPackageVersion as a unsigned integer.
   */
  static unsigned int getDefaultPackageVersion();


  /**
   * Returns the xmlnsL3V1V1 used by this libSBML package extension.
   *
   * @return the xmlnsL3V1V1 as a string.
   */
  static const std::string& getXmlnsL3V1V1();


  /**
   * Returns the xmlnsL3V1V2 used by this libSBML package extension.
   *
   * @return the xmlnsL3V1V2 as a string.
   */
  static const std::string& getXmlnsL3V1V2();


  /**
   * Creates a new VersExtension.
   */
  VersExtension();


  /**
   * Copy constructor for VersExtension.
   *
   * @param orig; the VersExtension instance to copy.
   */
  VersExtension(const VersExtension& orig);


  /**
   * Assignment operator for VersExtension.
   *
   * @param rhs; the VersExtension object whose values are to be used as the
   * basis of the assignment
   */
  VersExtension& operator=(const VersExtension& rhs);


  /**
   * Creates and returns a deep copy of this VersExtension object.
   *
   * @return a (deep) copy of this VersExtension object.
   */
  virtual VersExtension* clone() const;


  /**
   * Destructor for VersExtension.
   */
  virtual ~VersExtension();


  /**
   * Returns the name of this package ("vers").
   *
   * @return a string representing the name of this package ("vers").
   */
  virtual const std::string& getName() const;


  /**
   * Returns the namespace URI corresponding to the given SBML Level, Version
   * and PackageVersion
   *
   * @param sbmlLevel, the level of SBML
   *
   * @param sbmlVersion the version of SBML
   *
   * @param pkgVersion the version of this package
   *
   * @return a string representing the name of this package ("vers").
   */
  virtual const std::string& getURI(unsigned int sbmlLevel,
                                    unsigned int sbmlVersion,
                                    unsigned int pkgVersion) const;


  /**
   * Returns the SBML Level for the given URI of this package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package
   *
   * @return the SBML Level with the given URI of this package, or @c 0 if the
   * given URI is invalid.
   */
  virtual unsigned int getLevel(const std::string& uri) const;


  /**
   * Returns the SBML Version for the given URI of this package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package
   *
   * @return the SBML Version with the given URI of this package, or @c 0 if
   * the given URI is invalid.
   */
  virtual unsigned int getVersion(const std::string& uri) const;


  /**
   * Returns the SBML PackageVersion for the given URI of this package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package
   *
   * @return the SBML PackageVersion with the given URI of this package, or @c
   * 0 if the given URI is invalid.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a VersPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package
   *
   * @return VersPkgNamespaces object corresponding to the given URI of this
   * package, or @c NULL if the given URI is not defined in the "vers" package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Returns the given SBMLVersTypeCode_t(int) as a string.
   *
   * @param typeCode a TypeCode from the "vers" package.
   *
   * @return the typecode as a string.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the VersSBMLErrorTable.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Return the index in the error table with the given errorId.
   *
   * @param errorId an unsigned integer representing the errorId of the error.
   *
   * @return unsigned int representing the index in the VersSBMLErrorTable
   * corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "vers" package.
   *
   * @return unsigned int representing the offset for errors in the
   * VersSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Initializes vers extension by creating an object of this class with the
   * required SBasePlugin derived objects and registering the object to the
   * SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in VersExtension.cpp
   *
   * static SBMLExtensionRegister<VersExtension> versExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * VersPkgNamespace is derived from SBMLNamespaces class and used when creating
 * an object of SBase derived classes defined in the vers package
 *
 * SBMLExtensionNamespaces<VersExtension> must be instantiated in
 * VersExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<VersExtension> VersPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLVersTypeCode_t
 * @brief SBMLVersTypeCode_t is the enumeration of possible types from the
 * "vers" package.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
typedef enum
{
  CLASS_ONE       =   100  /*!<ClassOne */
, CLASS_A         =   101  /*!<Another */
, CLASS_TWO       =   102  /*!<ClassTwo */
, CLASS_THREE     =   103  /*!<ClassThree */
} SBMLVersTypeCode_t;


typedef enum
{
  OBJECTIVE_TYPE_MAXIMIZE       /*!<maximize */
, OBJECTIVE_TYPE_MINIMIZE       /*!<minimize */
, FBC_TYPE_INVALID              /*!<invalid FbcType */
} FbcType_t;


/**
 */
LIBSBML_EXTERN
const char*
FbcType_toString(FbcType_t ft);


/**
 */
LIBSBML_EXTERN
FbcType_t
FbcType_fromString(const char* code);


/**
 */
LIBSBML_EXTERN
int
FbcType_isValid(FbcType_t ft);


/**
 */
LIBSBML_EXTERN
int
FbcType_isValidString(const char* code);




LIBSBML_CPP_NAMESPACE_END




#endif /* !VersExtension_H__ */


