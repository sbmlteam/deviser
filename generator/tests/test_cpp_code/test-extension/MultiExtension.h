/**
 * @file MultiExtension.h
 * @brief Definition of MultiExtension.
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
 * @class MultiExtension
 * @sbmlbrief{multi} Base extension class for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * This is the Multi package extension of the SBMLExtension class that is used
 * to facilitate libSBML plug-ins in the implementation of an SBMLLevel&nbsp;3
 * package.
 *
 * @class MultiPkgNamespaces
 * @sbmlbrief{multi} SBMLNamespaces extension.
 *
 * @htmlinclude not-sbml-warning.html
 */


#ifndef MultiExtension_H__
#define MultiExtension_H__


#include <sbml/common/extern.h>
#include <sbml/SBMLTypeCodes.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>

#ifndef MULTI_CREATE_NS
#define MULTI_CREATE_NS(variable, sbmlns)\
EXTENSION_CREATE_NS(MultiPkgNamespaces, variable, sbmlns);
#endif

#include <vector>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN MultiExtension : public SBMLExtension
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
   * Creates a new MultiExtension instance.
   */
  MultiExtension();


  /**
   * Copy constructor for MultiExtension.
   *
   * @param orig the MultiExtension instance to copy.
   */
  MultiExtension(const MultiExtension& orig);


  /**
   * Assignment operator for MultiExtension.
   *
   * @param rhs the MultiExtension object whose values are to be used as the
   * basis of the assignment.
   */
  MultiExtension& operator=(const MultiExtension& rhs);


  /**
   * Creates and returns a deep copy of this MultiExtension object.
   *
   * @return a (deep) copy of this MultiExtension object.
   */
  virtual MultiExtension* clone() const;


  /**
   * Destructor for MultiExtension.
   */
  virtual ~MultiExtension();


  /**
   * Returns the name of this SBML Level&nbsp;3 package ("multi").
   *
   * @return a string representing the name of this package ("multi").
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
   * @return a string representing the name of this package ("multi").
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
   * the "multi" package.
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
   * the "multi" package.
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
   * the "multi" package.
   *
   * @return the version of the SBML Level&nbsp;3 package for the given URI of
   * this package, or @c 0 if the given URI is invalid, or for a different
   * package.
   */
  virtual unsigned int getPackageVersion(const std::string& uri) const;


  /**
   * Returns a MultiPkgNamespaces object.
   *
   * @param uri the string of the URI that represents one of the versions of
   * the "multi" package.
   *
   * @return MultiPkgNamespaces object corresponding to the given URI of this
   * package, or @c NULL if the given URI is not defined in the "multi"
   * package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string& uri)
    const;


  /**
   * Takes a type code of the &ldquo;multi&rdquo; package and returns a string
   * describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension
   * implementing support for the SBML Level&nbsp;3 &ldquo;multi&rdquo;
   * package.
   *
   * @return a text string representing the type code given by @p typeCode. If
   * the type code is unrecognized for this implementation of the libSBML
   * &ldquo;multi&rdquo; package, the string returned will be <code>"(Unknown
   * SBML Multi Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the entry in the error table at this index.
   *
   * @param index an unsigned integer representing the index of the error.
   *
   * @return packageErrorTableEntry object in the MultiSBMLErrorTable.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Return the index in the error table with the given errorId.
   *
   * @param errorId an unsigned integer representing the errorId of the error.
   *
   * @return unsigned int representing the index in the MultiSBMLErrorTable
   * corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the offset for the errorId range for the "multi" package.
   *
   * @return unsigned int representing the offset for errors in the
   * MultiSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Initializes multi extension by creating an object of this class with the
   * required SBasePlugin derived objects and registering the object to the
   * SBMLExtensionRegistry class
   *
   * This function is automatically invoked when creatingthe following global
   * object in MultiExtension.cpp
   *
   * static SBMLExtensionRegister<MultiExtension> multiExtensionRegistry;
   */
  static void init();

  /** @endcond */


};

/**
 *
 * Required typedef definitions
 *
 * MultiPkgNamespace is derived from SBMLNamespaces class and used when
 * creating an object of SBase derived classes defined in the multi package
 *
 * SBMLExtensionNamespaces<MultiExtension> must be instantiated in
 * MultiExtension.cpp for DLL
 *
 */
typedef SBMLExtensionNamespaces<MultiExtension> MultiPkgNamespaces;


LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_BEGIN


/**
 * @enum SBMLMultiTypeCode_t
 * @brief SBMLMultiTypeCode_t Enumeration of possible types in the libSBML
 * &ldquo;multi&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
typedef enum
{
  SBML_MULTI_POSSIBLE_SPECIES_FEATURE_VALUE            =  1400  /*!<PossibleSpeciesFeatureValue */
, SBML_MULTI_COMPARTMENT_REFERENCE                     =  1401  /*!<CompartmentReference */
, SBML_MULTI_SPECIES_TYPE_INSTANCE                     =  1402  /*!<SpeciesTypeInstance */
, SBML_MULTI_IN_SPECIES_TYPE_BOND                      =  1403  /*!<InSpeciesTypeBond */
, SBML_MULTI_OUTWARD_BINDING_SITE                      =  1404  /*!<OutwardBindingSite */
, SBML_MULTI_SPECIES_FEATURE_TYPE                      =  1405  /*!<SpeciesFeatureType */
, SBML_MULTI_SPECIES_TYPE_COMPONENT_INDEX              =  1406  /*!<SpeciesTypeComponentIndex */
, SBML_MULTI_SPECIES_FEATURE                           =  1407  /*!<SpeciesFeature */
, SBML_MULTI_SPECIES_FEATURE_VALUE                     =  1408  /*!<SpeciesFeatureValue */
, SBML_MULTI_SPECIES_TYPE_COMPONENT_MAP_IN_PRODUCT     =  1409  /*!<SpeciesTypeComponentMapInProduct */
, SBML_MULTI_SPECIES_TYPE                              =  1410  /*!<MultiSpeciesType */
, SBML_MULTI_INTRA_SPECIES_REACTION                    =  1411  /*!<IntraSpeciesReaction */
, SBML_MULTI_BINDINGSITESPECIESTYPE                    =  1412  /*!<BindingSiteSpeciesType */
, SBML_MULTI_SUBLISTOFSPECIESFEATURES                  =  1413  /*!<SubListOfSpeciesFeatures */
} SBMLMultiTypeCode_t;


/**
 * @enum BindingStatus_t
 * @brief Enumeration of values permitted as the value of the "binding"
 * attribute on Multi objects.
 *
 * @if conly
 * @see Multi_getBinding()
 * @see Multi_setBinding()
 * @elseif java
 * @see Multi::getBinding()
 * @see Multi::setBinding(long)
 * @else
 * @see Multi::getBinding()
 * @see Multi::setBinding()
 * @endif
 */
typedef enum
{
  MULTI_BINDING_STATUS_BOUND         /*!< The multi binding is @c "bound". */
, MULTI_BINDING_STATUS_UNBOUND       /*!< The multi binding is @c "unbound". */
, MULTI_BINDING_STATUS_EITHER        /*!< The multi binding is @c "either". */
, MULTI_BINDING_INVALID              /*!< Invalid BindingStatus value. */
} BindingStatus_t;


/**
 * Returns the string version of the provided #BindingStatus_t enumeration.
 *
 * @param bs the #BindingStatus_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "bound",
 * "unbound",
 * "either",
 * "invalid BindingStatus value",
 * or @c NULL if the value is @sbmlconstant{MULTI_BINDING_INVALID,
 * BindingStatus_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
const char*
BindingStatus_toString(BindingStatus_t bs);


/**
 * Returns the #BindingStatus_t enumeration corresponding to the given string
 * or @sbmlconstant{MULTI_BINDING_INVALID, BindingStatus_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #BindingStatus_t.
 *
 * @return the corresponding #BindingStatus_t or
 * @sbmlconstant{MULTI_BINDING_INVALID, BindingStatus_t} if no match is found.
 *
 * @note The matching is case-sensitive: "bound" will return
 * @sbmlconstant{MULTI_BINDING_STATUS_BOUND, BindingStatus_t}, but "Bound" will
 * return @sbmlconstant{MULTI_BINDING_INVALID, BindingStatus_t}.
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
BindingStatus_t
BindingStatus_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #BindingStatus_t is valid.
 *
 * @param bs the #BindingStatus_t enumeration to query.
 *
 * @return @c 1 (true) if the #BindingStatus_t is
 * @sbmlconstant{MULTI_BINDING_STATUS_BOUND, BindingStatus_t},
 * @sbmlconstant{MULTI_BINDING_STATUS_UNBOUND, BindingStatus_t}, or
 * @sbmlconstant{MULTI_BINDING_STATUS_EITHER, BindingStatus_t};
 * @c 0 (false) otherwise (including @sbmlconstant{MULTI_BINDING_INVALID,
 * BindingStatus_t}).
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
int
BindingStatus_isValid(BindingStatus_t bs);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #BindingStatus_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "bound",
 * "unbound",
 * "either", or
 * "invalid BindingStatus value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "bound" will return @c 1 (true), but
 * "Bound" will return @c 0 (false).
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
int
BindingStatus_isValidString(const char* code);


/**
 * @enum Relation_t
 * @brief Enumeration of values permitted as the value of the "relation"
 * attribute on Multi objects.
 *
 * @if conly
 * @see Multi_getRelation()
 * @see Multi_setRelation()
 * @elseif java
 * @see Multi::getRelation()
 * @see Multi::setRelation(long)
 * @else
 * @see Multi::getRelation()
 * @see Multi::setRelation()
 * @endif
 */
typedef enum
{
  MULTI_RELATION_AND           /*!< The multi relation is @c "and". */
, MULTI_RELATION_OR            /*!< The multi relation is @c "or". */
, MULTI_RELATION_NOT           /*!< The multi relation is @c "not". */
, MULTI_RELATION_INVALID       /*!< Invalid Relation value. */
} Relation_t;


/**
 * Returns the string version of the provided #Relation_t enumeration.
 *
 * @param r the #Relation_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "and",
 * "or",
 * "not",
 * "invalid Relation value",
 * or @c NULL if the value is @sbmlconstant{MULTI_RELATION_INVALID, Relation_t}
 * or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
const char*
Relation_toString(Relation_t r);


/**
 * Returns the #Relation_t enumeration corresponding to the given string or
 * @sbmlconstant{MULTI_RELATION_INVALID, Relation_t} if there is no such match.
 *
 * @param code the string to convert to a #Relation_t.
 *
 * @return the corresponding #Relation_t or
 * @sbmlconstant{MULTI_RELATION_INVALID, Relation_t} if no match is found.
 *
 * @note The matching is case-sensitive: "and" will return
 * @sbmlconstant{MULTI_RELATION_AND, Relation_t}, but "And" will return
 * @sbmlconstant{MULTI_RELATION_INVALID, Relation_t}.
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
Relation_t
Relation_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Relation_t is valid.
 *
 * @param r the #Relation_t enumeration to query.
 *
 * @return @c 1 (true) if the #Relation_t is
 * @sbmlconstant{MULTI_RELATION_AND, Relation_t},
 * @sbmlconstant{MULTI_RELATION_OR, Relation_t}, or
 * @sbmlconstant{MULTI_RELATION_NOT, Relation_t};
 * @c 0 (false) otherwise (including @sbmlconstant{MULTI_RELATION_INVALID,
 * Relation_t}).
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
int
Relation_isValid(Relation_t r);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Relation_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "and",
 * "or",
 * "not", or
 * "invalid Relation value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "and" will return @c 1 (true), but
 * "And" will return @c 0 (false).
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
int
Relation_isValidString(const char* code);


/**
 * @enum RepresentationType_t
 * @brief Enumeration of values permitted as the value of the
 * "representationtype" attribute on Multi objects.
 *
 * @if conly
 * @see Multi_getRepresentationtype()
 * @see Multi_setRepresentationtype()
 * @elseif java
 * @see Multi::getRepresentationtype()
 * @see Multi::setRepresentationtype(long)
 * @else
 * @see Multi::getRepresentationtype()
 * @see Multi::setRepresentationtype()
 * @endif
 */
typedef enum
{
  MULTI_REPRESENTATIONTYPE_SUM                /*!< The multi representationtype is @c "sum". */
, MULTI_REPRESENTATIONTYPE_NUMERICVALUE       /*!< The multi representationtype is @c "numericValue". */
, MULTI_REPRESENTATIONTYPE_INVALID            /*!< Invalid RepresentationType value. */
} RepresentationType_t;


/**
 * Returns the string version of the provided #RepresentationType_t
 * enumeration.
 *
 * @param rt the #RepresentationType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "sum",
 * "numericValue",
 * "invalid RepresentationType value",
 * or @c NULL if the value is @sbmlconstant{MULTI_REPRESENTATIONTYPE_INVALID,
 * RepresentationType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
const char*
RepresentationType_toString(RepresentationType_t rt);


/**
 * Returns the #RepresentationType_t enumeration corresponding to the given
 * string or @sbmlconstant{MULTI_REPRESENTATIONTYPE_INVALID,
 * RepresentationType_t} if there is no such match.
 *
 * @param code the string to convert to a #RepresentationType_t.
 *
 * @return the corresponding #RepresentationType_t or
 * @sbmlconstant{MULTI_REPRESENTATIONTYPE_INVALID, RepresentationType_t} if no
 * match is found.
 *
 * @note The matching is case-sensitive: "sum" will return
 * @sbmlconstant{MULTI_REPRESENTATIONTYPE_SUM, RepresentationType_t}, but "Sum"
 * will return @sbmlconstant{MULTI_REPRESENTATIONTYPE_INVALID,
 * RepresentationType_t}.
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
RepresentationType_t
RepresentationType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #RepresentationType_t is valid.
 *
 * @param rt the #RepresentationType_t enumeration to query.
 *
 * @return @c 1 (true) if the #RepresentationType_t is
 * @sbmlconstant{MULTI_REPRESENTATIONTYPE_SUM, RepresentationType_t}, or
 * @sbmlconstant{MULTI_REPRESENTATIONTYPE_NUMERICVALUE, RepresentationType_t};
 * @c 0 (false) otherwise (including
 * @sbmlconstant{MULTI_REPRESENTATIONTYPE_INVALID, RepresentationType_t}).
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
int
RepresentationType_isValid(RepresentationType_t rt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #RepresentationType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "sum",
 * "numericValue", or
 * "invalid RepresentationType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "sum" will return @c 1 (true), but
 * "Sum" will return @c 0 (false).
 *
 * @if conly
 * @memberof Multi_t
 * @endif
 */
LIBSBML_EXTERN
int
RepresentationType_isValidString(const char* code);




LIBSBML_CPP_NAMESPACE_END




#endif /* !MultiExtension_H__ */


