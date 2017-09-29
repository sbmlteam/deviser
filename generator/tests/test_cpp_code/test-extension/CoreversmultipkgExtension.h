/**
 * @file CoreversmultipkgExtension.h
 * @brief Definition of CoreversmultipkgExtension.
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
 * @class CoreversmultipkgExtension
 * @sbmlbrief{coreversmultipkg} Base extension class for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * This is the Coreversmultipkg package extension of the SBMLExtension class
 * that is used to facilitate libSBML plug-ins in the implementation of an
 * SBMLLevel&nbsp;3 package.
 *
 * @class CoreversmultipkgPkgNamespaces
 * @sbmlbrief{coreversmultipkg} SBMLNamespaces extension.
 *
 * @htmlinclude not-sbml-warning.html
 */


#ifndef CoreversmultipkgExtension_H__
#define CoreversmultipkgExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef COREVERSMULTIPKG_CREATE_NS
#define COREVERSMULTIPKG_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(CoreversmultipkgPkgNamespaces, variable, sbmlns);
#endif

#ifndef COREVERSMULTIPKG_CREATE_NS_WITH_VERSION
#define COREVERSMULTIPKG_CREATE_NS_WITH_VERSION(variable, sbmlns, version)\
EXTENSION_CREATE_NS_WITH_VERSION(CoreversmultipkgPkgNamespaces, variable,
  sbmlns, version);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CoreversmultipkgExtension : public SBMLExtension
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
  static const std::string& getXmlnsL3V1V2();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the XML namespace, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getXmlnsL3V2V1();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the XML namespace, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getXmlnsL3V2V2();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the XML namespace, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getXmlnsL4V1V1();


  /**
   * Creates a new CoreversmultipkgExtension instance.
   */
  CoreversmultipkgExtension();


  /**
   * Copy constructor for CoreversmultipkgExtension.
   *
   * @param orig the CoreversmultipkgExtension instance to copy.
   */
  CoreversmultipkgExtension(const CoreversmultipkgExtension& orig);


  /**
   * Assignment operator for CoreversmultipkgExtension.
   *
   * @param rhs the CoreversmultipkgExtension object whose values are to be
   * used as the basis of the assignment.
   */
  CoreversmultipkgExtension& operator=(const CoreversmultipkgExtension& rhs);


  /**
   * Creates and returns a deep copy of this CoreversmultipkgExtension object.
   *
   * @return a (deep) copy of this CoreversmultipkgExtension object.
   */
  virtual CoreversmultipkgExtension* clone() const;


  /**
   * Destructor for CoreversmultipkgExtension.
   */
  virtual ~CoreversmultipkgExtension();


  /**
   * Returns the name of this SBML Level&nbsp;3 package ("coreversmultipkg").
   *
   * @return a string representing the name of this package
   * ("coreversmultipkg").
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
   * @return a string representing the name of this package
   * ("coreversmultipkg").
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
   * the "coreversmultipkg" package.
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
   * the "coreversmultipkg" package.
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
   * the "coreversmultipkg" package.
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid, or for a different
   * package.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a CoreversmultipkgPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "coreversmultipkg" package.
   *
   * @return CoreversmultipkgPkgNamespaces object corresponding to the given
   * URI of this package, or @c NULL if the given URI is not defined in the
   * "coreversmultipkg" package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;coreversmultipkg&rdquo; package and
   * returns a string describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3
   * &ldquo;coreversmultipkg&rdquo; package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;coreversmultipkg&rdquo; package, the string returned will be
   * <code>"(Unknown SBML Coreversmultipkg Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the
   * CoreversmultipkgSBMLErrorTable.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Return the index in the error table with the given errorId.
   *
   * @param errorId an unsigned integer representing the errorId of the error.
   *
   * @return unsigned int representing the index in the
   * CoreversmultipkgSBMLErrorTable corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "coreversmultipkg"
   * package.
   *
   * @return unsigned int representing the offset for errors in the
   * CoreversmultipkgSBMLErrorTable.
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
   * Initializes coreversmultipkg extension by creating an object of this class
   * with the required SBasePlugin derived objects and registering the object
   * to the SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in CoreversmultipkgExtension.cpp
   *
   * static SBMLExtensionRegister<CoreversmultipkgExtension>
   * coreversmultipkgExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * CoreversmultipkgPkgNamespace is derived from SBMLNamespaces class and used
 * when creating an object of SBase derived classes defined in the
 * coreversmultipkg package
 *
 * SBMLExtensionNamespaces<CoreversmultipkgExtension> must be instantiated in
 * CoreversmultipkgExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<CoreversmultipkgExtension>
  CoreversmultipkgPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLCoreversmultipkgTypeCode_t
 * @brief SBMLCoreversmultipkgTypeCode_t Enumeration of possible types in the
 * libSBML &ldquo;coreversmultipkg&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
/**
 * @enum SBMLCoreversmultipkgTypeCode_t
 * @brief Enumeration of values permitted as the value of the "corevers"
 * attribute on Sbml objects.
 *
 * @if conly
 * @see Sbml_getCorevers()
 * @see Sbml_setCorevers()
 * @elseif java
 * @see Sbml::getCorevers()
 * @see Sbml::setCorevers(long)
 * @else
 * @see Sbml::getCorevers()
 * @see Sbml::setCorevers()
 * @endif
 */
typedef enum
{
  SBML_COREVERS_CLASSONETWO     =   100  /*!< The sbml corevers is @c "ClassOneTwo". */
, SBML_COREVERS_CLASSONETWO     =   101  /*!< The sbml corevers is @c "ClassMult". */
} SBMLCoreversmultipkgTypeCode_t;


/**
 * @enum AbcType_t
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
, ABC_TYPE_INVALID              /*!< Invalid AbcType value. */
} AbcType_t;


/**
 * Returns the string version of the provided #AbcType_t enumeration.
 *
 * @param at the #AbcType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "maximize",
 * "minimize",
 * or @c NULL if the value is @sbmlconstant{ABC_TYPE_INVALID, AbcType_t} or
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
AbcType_toString(AbcType_t at);


/**
 * Returns the #AbcType_t enumeration corresponding to the given string or
 * @sbmlconstant{ABC_TYPE_INVALID, AbcType_t} if there is no such match.
 *
 * @param code the string to convert to a #AbcType_t.
 *
 * @return the corresponding #AbcType_t or @sbmlconstant{ABC_TYPE_INVALID,
 * AbcType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "maximize" will return
 * @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, AbcType_t}, but "Maximize" will
 * return @sbmlconstant{ABC_TYPE_INVALID, AbcType_t}.
 *
 * @if conly
 * @memberof Objective_t
 * @endif
 */
LIBSBML_EXTERN
AbcType_t
AbcType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #AbcType_t is valid.
 *
 * @param at the #AbcType_t enumeration to query.
 *
 * @return @c 1 (true) if the #AbcType_t is
 * @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, AbcType_t}, or
 * @sbmlconstant{OBJECTIVE_TYPE_MINIMIZE, AbcType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{ABC_TYPE_INVALID,
 * AbcType_t}).
 *
 * @if conly
 * @memberof Objective_t
 * @endif
 */
LIBSBML_EXTERN
int
AbcType_isValid(AbcType_t at);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #AbcType_t.
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
AbcType_isValidString(const char* code);




LIBSBML_CPP_NAMESPACE_END




#endif /* !CoreversmultipkgExtension_H__ */


