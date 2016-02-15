/**
 * @file QualExtension.h
 * @brief Definition of QualExtension.
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
 *
 * @class QualExtension
 * @sbmlbrief{qual} Base extension class.
 *
 * @class QualPkgNamespaces
 * @sbmlbrief{qual} SBMLNamespaces extension.
 */


#ifndef QualExtension_H__
#define QualExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef QUAL_CREATE_NS
#define QUAL_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(QualPkgNamespaces, variable, sbmlns);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN QualExtension : public SBMLExtension
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
   * Creates a new QualExtension instance.
   */
  QualExtension();


  /**
   * Copy constructor for QualExtension.
   *
   * @param orig; the QualExtension instance to copy.
   */
  QualExtension(const QualExtension& orig);


  /**
   * Assignment operator for QualExtension.
   *
   * @param rhs; the QualExtension object whose values are to be used as the
   * basis of the assignment
   */
  QualExtension& operator=(const QualExtension& rhs);


  /**
   * Creates and returns a deep copy of this QualExtension object.
   *
   * @return a (deep) copy of this QualExtension object.
   */
  virtual QualExtension* clone() const;


  /**
   * Destructor for QualExtension.
   */
  virtual ~QualExtension();


  /**
   * Returns the name of this SBML Level&nbsp;3 package ("qual").
   *
   * @return a string representing the name of this package ("qual").
   */
  virtual const std::string& getName() const;


  /**
   * Returns a string representing the SBML XML namespace of this SBML
   * Level&nbsp;3 package.
   *
   * @param sbmlLevel, the level of SBML
   *
   * @param sbmlVersion the version of SBML
   *
   * @param pkgVersion the version of this package
   *
   * @return a string representing the name of this package ("qual").
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
   * the "qual" package
   *
   * @return the SBML Level for the given URI of this package, or @c 0 if the
   * given URI is invalid.
   */
  virtual unsigned int getLevel(const std::string& uri) const;


  /**
   * Returns the Version within the SBML Level for the given URI of this
   * package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "qual" package
   *
   * @return the SBML Version within the SBML Level for the given URI of this
   * package, or @c 0 if the given URI is invalid.
   */
  virtual unsigned int getVersion(const std::string& uri) const;


  /**
   * Returns the SBML Level&nbsp;3 package version for the given URI of this
   * package.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "qual" package
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a QualPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "qual" package
   *
   * @return QualPkgNamespaces object corresponding to the given URI of this
   * package, or @c NULL if the given URI is not defined in the "qual" package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;qual&rdquo; package and returns a string
   * describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3 &ldquo;qual&rdquo; package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;qual&rdquo; package, the string returned will be <code>"(Unknown
   * SBML Qual Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the QualSBMLErrorTable.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Return the index in the error table with the given errorId.
   *
   * @param errorId an unsigned integer representing the errorId of the error.
   *
   * @return unsigned int representing the index in the QualSBMLErrorTable
   * corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "qual" package.
   *
   * @return unsigned int representing the offset for errors in the
   * QualSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Initializes qual extension by creating an object of this class with the
   * required SBasePlugin derived objects and registering the object to the
   * SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in QualExtension.cpp
   *
   * static SBMLExtensionRegister<QualExtension> qualExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * QualPkgNamespace is derived from SBMLNamespaces class and used when creating
 * an object of SBase derived classes defined in the qual package
 *
 * SBMLExtensionNamespaces<QualExtension> must be instantiated in
 * QualExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<QualExtension> QualPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLQualTypeCode_t
 * @brief SBMLQualTypeCode_t Enumeration of possible types in the libSBML
 * &ldquo;qual&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
typedef enum
{
  SBML_QUAL_QUALITATIVE_SPECIES     =  1100  /*!<QualitativeSpecies */
, SBML_QUAL_TRANSITION              =  1101  /*!<Transition */
, SBML_QUAL_INPUT                   =  1102  /*!<Input */
, SBML_QUAL_OUTPUT                  =  1103  /*!<Output */
, SBML_QUAL_DEFAULT_TERM            =  1104  /*!<DefaultTerm */
, SBML_QUAL_FUNCTION_TERM           =  1105  /*!<FunctionTerm */
} SBMLQualTypeCode_t;


typedef enum
{
  INPUT_SIGN_POSITIVE       /*!<positive */
, INPUT_SIGN_NEGATIVE       /*!<negative */
, INPUT_SIGN_DUAL           /*!<dual */
, INPUT_SIGN_UNKNOWN        /*!<unknown */
, SIGN_INVALID              /*!<invalid Sign */
} Sign_t;


/**
 */
LIBSBML_EXTERN
const char*
Sign_toString(Sign_t s);


/**
 */
LIBSBML_EXTERN
Sign_t
Sign_fromString(const char* code);


/**
 */
LIBSBML_EXTERN
int
Sign_isValid(Sign_t s);


/**
 */
LIBSBML_EXTERN
int
Sign_isValidString(const char* code);


typedef enum
{
  OUTPUT_TRANSITION_EFFECT_PRODUCTION             /*!<production */
, OUTPUT_TRANSITION_EFFECT_ASSIGNMENT_LEVEL       /*!<assignmentLevel */
, TRANSITION_OUTPUT_EFFECT_INVALID                /*!<invalid TransitionOutputEffect */
} TransitionOutputEffect_t;


/**
 */
LIBSBML_EXTERN
const char*
TransitionOutputEffect_toString(TransitionOutputEffect_t toe);


/**
 */
LIBSBML_EXTERN
TransitionOutputEffect_t
TransitionOutputEffect_fromString(const char* code);


/**
 */
LIBSBML_EXTERN
int
TransitionOutputEffect_isValid(TransitionOutputEffect_t toe);


/**
 */
LIBSBML_EXTERN
int
TransitionOutputEffect_isValidString(const char* code);


typedef enum
{
  INPUT_TRANSITION_EFFECT_NONE              /*!<none */
, INPUT_TRANSITION_EFFECT_CONSUMPTION       /*!<consumption */
, TRANSITION_INPUT_EFFECT_INVALID           /*!<invalid TransitionInputEffect */
} TransitionInputEffect_t;


/**
 */
LIBSBML_EXTERN
const char*
TransitionInputEffect_toString(TransitionInputEffect_t tie);


/**
 */
LIBSBML_EXTERN
TransitionInputEffect_t
TransitionInputEffect_fromString(const char* code);


/**
 */
LIBSBML_EXTERN
int
TransitionInputEffect_isValid(TransitionInputEffect_t tie);


/**
 */
LIBSBML_EXTERN
int
TransitionInputEffect_isValidString(const char* code);




LIBSBML_CPP_NAMESPACE_END




#endif /* !QualExtension_H__ */


