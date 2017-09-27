/**
 * @file CoreversExtension.h
 * @brief Definition of CoreversExtension.
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
 * @class CoreversExtension
 * @sbmlbrief{corevers} Base extension class for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * This is the Corevers package extension of the SBMLExtension class that is
 * used to facilitate libSBML plug-ins in the implementation of an
 * SBMLLevel&nbsp;3 package.
 *
 * @class CoreversPkgNamespaces
 * @sbmlbrief{corevers} SBMLNamespaces extension.
 *
 * @htmlinclude not-sbml-warning.html
 */


#ifndef CoreversExtension_H__
#define CoreversExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef COREVERS_CREATE_NS
#define COREVERS_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(CoreversPkgNamespaces, variable, sbmlns);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CoreversExtension : public SBMLExtension
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
  static const std::string& getXmlnsL3V2V1();


  /**
   * Creates a new CoreversExtension instance.
   */
  CoreversExtension();


  /**
   * Copy constructor for CoreversExtension.
   *
   * @param orig the CoreversExtension instance to copy.
   */
  CoreversExtension(const CoreversExtension& orig);


  /**
   * Assignment operator for CoreversExtension.
   *
   * @param rhs the CoreversExtension object whose values are to be used as the
   * basis of the assignment.
   */
  CoreversExtension& operator=(const CoreversExtension& rhs);


  /**
   * Creates and returns a deep copy of this CoreversExtension object.
   *
   * @return a (deep) copy of this CoreversExtension object.
   */
  virtual CoreversExtension* clone() const;


  /**
   * Destructor for CoreversExtension.
   */
  virtual ~CoreversExtension();


  /**
   * Returns the name of this SBML Level&nbsp;3 package ("corevers").
   *
   * @return a string representing the name of this package ("corevers").
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
   * @return a string representing the name of this package ("corevers").
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
   * the "corevers" package.
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
   * the "corevers" package.
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
   * the "corevers" package.
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid, or for a different
   * package.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a CoreversPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "corevers" package.
   *
   * @return CoreversPkgNamespaces object corresponding to the given URI of
   * this package, or @c NULL if the given URI is not defined in the "corevers"
   * package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;corevers&rdquo; package and returns a
   * string describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3 &ldquo;corevers&rdquo;
   * package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;corevers&rdquo; package, the string returned will be
   * <code>"(Unknown SBML Corevers Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the CoreversSBMLErrorTable.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Return the index in the error table with the given errorId.
   *
   * @param errorId an unsigned integer representing the errorId of the error.
   *
   * @return unsigned int representing the index in the CoreversSBMLErrorTable
   * corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "corevers" package.
   *
   * @return unsigned int representing the offset for errors in the
   * CoreversSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Initializes corevers extension by creating an object of this class with
   * the required SBasePlugin derived objects and registering the object to the
   * SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in CoreversExtension.cpp
   *
   * static SBMLExtensionRegister<CoreversExtension> coreversExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * CoreversPkgNamespace is derived from SBMLNamespaces class and used when
 * creating an object of SBase derived classes defined in the corevers package
 *
 * SBMLExtensionNamespaces<CoreversExtension> must be instantiated in
 * CoreversExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<CoreversExtension> CoreversPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLCoreversTypeCode_t
 * @brief SBMLCoreversTypeCode_t Enumeration of possible types in the libSBML
 * &ldquo;corevers&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
typedef enum
{
  SBML_COREVERS_CLASSONETWO     =   100  /*!<ClassOneTwo */
} SBMLCoreversTypeCode_t;




LIBSBML_CPP_NAMESPACE_END




#endif /* !CoreversExtension_H__ */


