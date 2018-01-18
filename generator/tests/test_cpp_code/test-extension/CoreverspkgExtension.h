/**
 * @file CoreverspkgExtension.h
 * @brief Definition of CoreverspkgExtension.
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
 *
 * @class CoreverspkgExtension
 * @sbmlbrief{coreverspkg} Base extension class for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * This is the Coreverspkg package extension of the SBMLExtension class that is
 * used to facilitate libSBML plug-ins in the implementation of an
 * SBMLLevel&nbsp;3 package.
 *
 * @class CoreverspkgPkgNamespaces
 * @sbmlbrief{coreverspkg} SBMLNamespaces extension.
 *
 * @htmlinclude not-sbml-warning.html
 */


#ifndef CoreverspkgExtension_H__
#define CoreverspkgExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef COREVERSPKG_CREATE_NS
#define COREVERSPKG_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(CoreverspkgPkgNamespaces, variable, sbmlns);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CoreverspkgExtension : public SBMLExtension
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
  static const std::string& getXmlnsL3V2V2();


  /**
   * Creates a new CoreverspkgExtension instance.
   */
  CoreverspkgExtension();


  /**
   * Copy constructor for CoreverspkgExtension.
   *
   * @param orig the CoreverspkgExtension instance to copy.
   */
  CoreverspkgExtension(const CoreverspkgExtension& orig);


  /**
   * Assignment operator for CoreverspkgExtension.
   *
   * @param rhs the CoreverspkgExtension object whose values are to be used as
   * the basis of the assignment.
   */
  CoreverspkgExtension& operator=(const CoreverspkgExtension& rhs);


  /**
   * Creates and returns a deep copy of this CoreverspkgExtension object.
   *
   * @return a (deep) copy of this CoreverspkgExtension object.
   */
  virtual CoreverspkgExtension* clone() const;


  /**
   * Destructor for CoreverspkgExtension.
   */
  virtual ~CoreverspkgExtension();


  /**
   * Returns the name of this SBML Level&nbsp;3 package ("coreverspkg").
   *
   * @return a string representing the name of this package ("coreverspkg").
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
   * @return a string representing the name of this package ("coreverspkg").
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
   * the "coreverspkg" package.
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
   * the "coreverspkg" package.
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
   * the "coreverspkg" package.
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid, or for a different
   * package.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a CoreverspkgPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "coreverspkg" package.
   *
   * @return CoreverspkgPkgNamespaces object corresponding to the given URI of
   * this package, or @c NULL if the given URI is not defined in the
   * "coreverspkg" package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;coreverspkg&rdquo; package and returns a
   * string describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3 &ldquo;coreverspkg&rdquo;
   * package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;coreverspkg&rdquo; package, the string returned will be
   * <code>"(Unknown SBML Coreverspkg Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the CoreverspkgSBMLErrorTable.
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
   * CoreverspkgSBMLErrorTable corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "coreverspkg" package.
   *
   * @return unsigned int representing the offset for errors in the
   * CoreverspkgSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Initializes coreverspkg extension by creating an object of this class with
   * the required SBasePlugin derived objects and registering the object to the
   * SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in CoreverspkgExtension.cpp
   *
   * static SBMLExtensionRegister<CoreverspkgExtension>
   * coreverspkgExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * CoreverspkgPkgNamespace is derived from SBMLNamespaces class and used when
 * creating an object of SBase derived classes defined in the coreverspkg
 * package
 *
 * SBMLExtensionNamespaces<CoreverspkgExtension> must be instantiated in
 * CoreverspkgExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<CoreverspkgExtension> CoreverspkgPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLCoreverspkgTypeCode_t
 * @brief SBMLCoreverspkgTypeCode_t Enumeration of possible types in the
 * libSBML &ldquo;coreverspkg&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
/**
 * @enum SBMLCoreverspkgTypeCode_t
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
} SBMLCoreverspkgTypeCode_t;




LIBSBML_CPP_NAMESPACE_END




#endif /* !CoreverspkgExtension_H__ */


