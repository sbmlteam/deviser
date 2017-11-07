/**
 * @file VersExtension.h
 * @brief Definition of VersExtension.
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
 *
 * @class VersExtension
 * @sbmlbrief{vers} Base extension class for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * This is the Vers package extension of the SBMLExtension class that is used
 * to facilitate libSBML plug-ins in the implementation of an SBMLLevel&nbsp;3
 * package.
 *
 * @class VersPkgNamespaces
 * @sbmlbrief{vers} SBMLNamespaces extension.
 *
 * @htmlinclude not-sbml-warning.html
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

#ifndef VERS_CREATE_NS_WITH_VERSION
#define VERS_CREATE_NS_WITH_VERSION(variable, sbmlns, version)\
  EXTENSION_CREATE_NS_WITH_VERSION(VersPkgNamespaces, variable, sbmlns, version);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN VersExtension : public SBMLExtension
{
public:

  /**
   * Returns the nickname of the SBML Level&nbsp;3 package implemented by this
   * libSBML extension.
   *
   * @return the package nickname, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getPackageName();


  /**
   * Returns the default SBML Level implemented by this libSBML extension.
   *
   * @return the SBML Level, as an unsigned integer.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultLevel();


  /**
   * Returns the default SBML Version implemented by this libSBML extension.
   *
   * @return the Version within the default SBML Level, as an unsigned integer.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultVersion();


  /**
   * Returns the default version of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the default version number of the SBML Level&nbsp;3 package
   * definition, as an unsigned integer.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultPackageVersion();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the XML namespace, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getXmlnsL3V1V1();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the XML namespace, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getXmlnsL3V1V2();


  /**
   * Creates a new VersExtension instance.
   */
  VersExtension();


  /**
   * Copy constructor for VersExtension.
   *
   * @param orig the VersExtension instance to copy.
   */
  VersExtension(const VersExtension& orig);


  /**
   * Assignment operator for VersExtension.
   *
   * @param rhs the VersExtension object whose values are to be used as the
   * basis of the assignment.
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
   * Returns the name of this SBML Level&nbsp;3 package ("vers").
   *
   * @return a string representing the name of this package ("vers").
   */
  virtual const std::string& getName() const;


  /**
   * Returns a string representing the SBML XML namespace of this SBML
   * Level&nbsp;3 package.
   *
   * @param sbmlLevel the level of SBML.
   *
   * @param sbmlVersion the version of SBML.
   *
   * @param pkgVersion the version of this package.
   *
   * @return a string representing the name of this package ("vers").
   *
   * The namespace URI constructed by this method corresponds to the
   * combination of the Level and Version of SBML, and the Version of the SBML
   * Level&nbsp;3 package. (At the time of this writing, the only SBML Level
   * that supports packages is Level&nbsp;3, so the value of @p sbmlLevel is
   * necessarily always <code>3</code>.)
   */
  virtual const std::string& getURI(unsigned int sbmlLevel,
                                    unsigned int sbmlVersion,
                                    unsigned int pkgVersion) const;


  /**
   * Returns the SBML Level for the given URI of this package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package.
   *
   * @return the SBML Level for the given URI of this package, or @c 0 if the
   * given URI is invalid, or for a different package.
   */
  virtual unsigned int getLevel(const std::string& uri) const;


  /**
   * Returns the Version within the SBML Level for the given URI of this
   * package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package.
   *
   * @return the SBML Version within the SBML Level for the given URI of this
   * package, or @c 0 if the given URI is invalid, or for a different package.
   */
  virtual unsigned int getVersion(const std::string& uri) const;


  /**
   * Returns the SBML Level&nbsp;3 package version for the given URI of this
   * package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package.
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid, or for a different
   * package.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a VersPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "vers" package.
   *
   * @return VersPkgNamespaces object corresponding to the given URI of this
   * package, or @c NULL if the given URI is not defined in the "vers" package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;vers&rdquo; package and returns a string
   * describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3 &ldquo;vers&rdquo; package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;vers&rdquo; package, the string returned will be <code>"(Unknown
   * SBML Vers Type)"</code>.
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
   * Returns true if the package has multiple versions.
   *
   * @return true if multiple versions, false otherwise.
   */
  virtual bool hasMultipleVersions() const;

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
 * @brief SBMLVersTypeCode_t Enumeration of possible types in the libSBML
 * &ldquo;vers&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
/**
 * @enum SBMLVersTypeCode_t
 * @brief Enumeration of values permitted as the value of the "one" attribute
 * on Class objects.
 *
 * @if conly
 * @see Class_getOne()
 * @see Class_setOne()
 * @elseif java
 * @see Class::getOne()
 * @see Class::setOne(long)
 * @else
 * @see Class::getOne()
 * @see Class::setOne()
 * @endif
 */
typedef enum
{
  CLASS_ONE       =  1400  /*!< The class one is @c "ClassOne". */
, CLASS_A         =  1401  /*!< The class a is @c "Another". */
, CLASS_B         =  1402  /*!< The class b is @c "BBB". */
, CLASS_TWO       =  1403  /*!< The class two is @c "ClassTwo". */
, CLASS_THREE     =  1404  /*!< The class three is @c "ClassThree". */
} SBMLVersTypeCode_t;


/**
 * @enum FbcType_t
 * @brief Enumeration of values permitted as the value of the "type" attribute
 * on Objective objects.
 *
 * @if conly
 * @see Objective_getType()
 * @see Objective_setType()
 * @elseif java
 * @see Objective::getType()
 * @see Objective::setType(long)
 * @else
 * @see Objective::getType()
 * @see Objective::setType()
 * @endif
 */
typedef enum
{
  OBJECTIVE_TYPE_MAXIMIZE       /*!< The objective type is @c "maximize". */
, OBJECTIVE_TYPE_MINIMIZE       /*!< The objective type is @c "minimize". */
, FBC_TYPE_INVALID              /*!< Invalid FbcType value. */
} FbcType_t;


/**
 * Returns the string version of the provided #FbcType_t enumeration.
 *
 * @param ft the #FbcType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "maximize",
 * "minimize",
 * or @c NULL if the value is @sbmlconstant{FBC_TYPE_INVALID, FbcType_t} or
 * another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Objective_t
 * @endif
 */
LIBSBML_EXTERN
const char*
FbcType_toString(FbcType_t ft);


/**
 * Returns the #FbcType_t enumeration corresponding to the given string or
 * @sbmlconstant{FBC_TYPE_INVALID, FbcType_t} if there is no such match.
 *
 * @param code the string to convert to a #FbcType_t.
 *
 * @return the corresponding #FbcType_t or @sbmlconstant{FBC_TYPE_INVALID,
 * FbcType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "maximize" will return
 * @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, FbcType_t}, but "Maximize" will
 * return @sbmlconstant{FBC_TYPE_INVALID, FbcType_t}.
 *
 * @if conly
 * @memberof Objective_t
 * @endif
 */
LIBSBML_EXTERN
FbcType_t
FbcType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #FbcType_t is valid.
 *
 * @param ft the #FbcType_t enumeration to query.
 *
 * @return @c 1 (true) if the #FbcType_t is
 * @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, FbcType_t}, or
 * @sbmlconstant{OBJECTIVE_TYPE_MINIMIZE, FbcType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{FBC_TYPE_INVALID,
 * FbcType_t}).
 *
 * @if conly
 * @memberof Objective_t
 * @endif
 */
LIBSBML_EXTERN
int
FbcType_isValid(FbcType_t ft);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #FbcType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "maximize", or
 * "minimize";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "maximize" will return @c 1 (true),
 * but "Maximize" will return @c 0 (false).
 *
 * @if conly
 * @memberof Objective_t
 * @endif
 */
LIBSBML_EXTERN
int
FbcType_isValidString(const char* code);




LIBSBML_CPP_NAMESPACE_END




#endif /* !VersExtension_H__ */


