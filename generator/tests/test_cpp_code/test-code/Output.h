/**
 * @file: Output.h
 * @brief: Definition of Output.
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


#ifndef Output_H__
#define Output_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/qual/extension/QualExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Output : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  std::string mQualitativeSpecies;
  TransitionOutputEffect_t mTransitionEffect;
  std::string mName;
  int mOutputLevel;
  bool mIsSetOutputLevel;

  /** @endcond */

public:

  /**
   * Creates a new Output using the given SBML @p level, @ p version and
   * package version values.
   *
   * @param level an unsigned int, the SBML Level to assign to this Output
   *
   * @param version an unsigned int, the SBML Version to assign to this Output
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
   * Output
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Output(unsigned int level = QualExtension::getDefaultLevel(),
         unsigned int version = QualExtension::getDefaultVersion(),
         unsigned int pkgVersion = QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new Output using the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Output(QualPkgNamespaces *qualns);


  /**
   * Copy constructor for Output.
   *
   * @param orig; the Output instance to copy.
   */
  Output(const Output& orig);


  /**
   * Assignment operator for Output.
   *
   * @param rhs; the Output object whose values are to be used as the basis of
   * the assignment
   */
  Output& operator=(const Output& rhs);


  /**
   * Creates and returns a deep copy of this Output object.
   *
   * @return a (deep) copy of this Output object.
   */
  virtual Output* clone() const;


  /**
   * Destructor for Output.
   */
  virtual ~Output();


  /**
   * Returns the value of the "id" attribute of this Output.
   *
   * @return the value of the "id" attribute of this Output as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "qualitativeSpecies" attribute of this Output.
   *
   * @return the value of the "qualitativeSpecies" attribute of this Output as
   * a string.
   */
  const std::string& getQualitativeSpecies() const;


  /**
   * Returns the value of the "transitionEffect" attribute of this Output.
   *
   * @return the value of the "transitionEffect" attribute of this Output as a
   * TransitionOutputEffect_t.
   */
  TransitionOutputEffect_t getTransitionEffect() const;


  /**
   * Returns the value of the "transitionEffect" attribute of this Output.
   *
   * @return the value of the "transitionEffect" attribute of this Output as a
   * string.
   */
  const std::string& getTransitionEffectAsString() const;


  /**
   * Returns the value of the "name" attribute of this Output.
   *
   * @return the value of the "name" attribute of this Output as a string.
   */
  const std::string& getName() const;


  /**
   * Returns the value of the "outputLevel" attribute of this Output.
   *
   * @return the value of the "outputLevel" attribute of this Output as a
   * integer.
   */
  int getOutputLevel() const;


  /**
   * Predicate returning @c true or @c false depending on whether this Output's
   * "id" attribute has been set.
   *
   * @return @c true if this Output's "id" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this Output's
   * "qualitativeSpecies" attribute has been set.
   *
   * @return @c true if this Output's "qualitativeSpecies" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetQualitativeSpecies() const;


  /**
   * Predicate returning @c true or @c false depending on whether this Output's
   * "transitionEffect" attribute has been set.
   *
   * @return @c true if this Output's "transitionEffect" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetTransitionEffect() const;


  /**
   * Predicate returning @c true or @c false depending on whether this Output's
   * "name" attribute has been set.
   *
   * @return @c true if this Output's "name" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this Output's
   * "outputLevel" attribute has been set.
   *
   * @return @c true if this Output's "outputLevel" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetOutputLevel() const;


  /**
   * Sets the value of the "id" attribute of this Output.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "qualitativeSpecies" attribute of this Output.
   *
   * @param qualitativeSpecies std::string& value of the "qualitativeSpecies"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setQualitativeSpecies(const std::string& qualitativeSpecies);


  /**
   * Sets the value of the "transitionEffect" attribute of this Output.
   *
   * @param transitionEffect TransitionOutputEffect_t value of the
   * "transitionEffect" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTransitionEffect(const TransitionOutputEffect_t transitionEffect);


  /**
   * Sets the value of the "transitionEffect" attribute of this Output.
   *
   * @param transitionEffect std::string& of the "transitionEffect" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTransitionEffect(const std::string& transitionEffect);


  /**
   * Sets the value of the "name" attribute of this Output.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setName(const std::string& name);


  /**
   * Sets the value of the "outputLevel" attribute of this Output.
   *
   * @param outputLevel int value of the "outputLevel" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOutputLevel(int outputLevel);


  /**
   * Unsets the value of the "id" attribute of this Output.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "qualitativeSpecies" attribute of this Output.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetQualitativeSpecies();


  /**
   * Unsets the value of the "transitionEffect" attribute of this Output.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTransitionEffect();


  /**
   * Unsets the value of the "name" attribute of this Output.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetName();


  /**
   * Unsets the value of the "outputLevel" attribute of this Output.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutputLevel();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML name of this Output object.
   *
   * @return the name of this element; that is "output".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this Output object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_QUAL_OUTPUT, SBMLQualTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Output
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * Output have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Output object are:
   * @li "qualitativeSpecies"
   * @li "transitionEffect"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Output_t using the given SBML @p level, @ p version and
 * package version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this Output_t
 *
 * @param version an unsigned int, the SBML Version to assign to this Output_t
 *
 * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
 * Output_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
Output_t *
Output_create(unsigned int level = QualExtension::getDefaultLevel(),
              unsigned int version = QualExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                QualExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Output_t object.
 *
 * @param o; the Output_t structure
 *
 * @return a (deep) copy of this Output_t object.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
Output_t*
Output_clone(const Output_t* o);


/**
 * Frees this Output_t object.
 *
 * @param o; the Output_t structure
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
void
Output_free(Output_t* o);


/**
 * Returns the value of the "id" attribute of this Output_t.
 *
 * @param o the Output_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Output_t as a pointer to a
 * string.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
const char *
Output_getId(const Output_t * o);


/**
 * Returns the value of the "qualitativeSpecies" attribute of this Output_t.
 *
 * @param o the Output_t structure whose qualitativeSpecies is sought.
 *
 * @return the value of the "qualitativeSpecies" attribute of this Output_t as
 * a pointer to a string.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
const char *
Output_getQualitativeSpecies(const Output_t * o);


/**
 * Returns the value of the "transitionEffect" attribute of this Output_t.
 *
 * @param o the Output_t structure whose transitionEffect is sought.
 *
 * @return the value of the "transitionEffect" attribute of this Output_t as a
 * TransitionOutputEffect_t.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
TransitionOutputEffect_t
Output_getTransitionEffect(const Output_t * o);


/**
 * Returns the value of the "transitionEffect" attribute of this Output_t.
 *
 * @param o the Output_t structure whose transitionEffect is sought.
 *
 * @return the value of the "transitionEffect" attribute of this Output_t as a
 * const char *.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
const char *
Output_getTransitionEffectAsString(const Output_t * o);


/**
 * Returns the value of the "name" attribute of this Output_t.
 *
 * @param o the Output_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this Output_t as a pointer to a
 * string.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
const char *
Output_getName(const Output_t * o);


/**
 * Returns the value of the "outputLevel" attribute of this Output_t.
 *
 * @param o the Output_t structure whose outputLevel is sought.
 *
 * @return the value of the "outputLevel" attribute of this Output_t as a
 * integer.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_getOutputLevel(const Output_t * o);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this Output_t's "id"
 * attribute has been set.
 *
 * @param o the Output_t structure.
 *
 * @return @c 1 if this Output_t's "id" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_isSetId(const Output_t * o);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this Output_t's
 * "qualitativeSpecies" attribute has been set.
 *
 * @param o the Output_t structure.
 *
 * @return @c 1 if this Output_t's "qualitativeSpecies" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_isSetQualitativeSpecies(const Output_t * o);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this Output_t's
 * "transitionEffect" attribute has been set.
 *
 * @param o the Output_t structure.
 *
 * @return @c 1 if this Output_t's "transitionEffect" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_isSetTransitionEffect(const Output_t * o);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this Output_t's "name"
 * attribute has been set.
 *
 * @param o the Output_t structure.
 *
 * @return @c 1 if this Output_t's "name" attribute has been set, otherwise @c
 * 0 is returned.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_isSetName(const Output_t * o);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this Output_t's
 * "outputLevel" attribute has been set.
 *
 * @param o the Output_t structure.
 *
 * @return @c 1 if this Output_t's "outputLevel" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_isSetOutputLevel(const Output_t * o);


/**
 * Sets the value of the "id" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_setId(Output_t * o, const char * id);


/**
 * Sets the value of the "qualitativeSpecies" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @param qualitativeSpecies const char * value of the "qualitativeSpecies"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_setQualitativeSpecies(Output_t * o, const char * qualitativeSpecies);


/**
 * Sets the value of the "transitionEffect" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @param transitionEffect TransitionOutputEffect_t value of the
 * "transitionEffect" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_setTransitionEffect(Output_t * o,
                           TransitionOutputEffect_t transitionEffect);


/**
 * Sets the value of the "transitionEffect" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @param transitionEffect const char * of the "transitionEffect" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_setTransitionEffectAsString(Output_t * o,
                                   const char * transitionEffect);


/**
 * Sets the value of the "name" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_setName(Output_t * o, const char * name);


/**
 * Sets the value of the "outputLevel" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @param outputLevel int value of the "outputLevel" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_setOutputLevel(Output_t * o, int outputLevel);


/**
 * Unsets the value of the "id" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_unsetId(Output_t * o);


/**
 * Unsets the value of the "qualitativeSpecies" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_unsetQualitativeSpecies(Output_t * o);


/**
 * Unsets the value of the "transitionEffect" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_unsetTransitionEffect(Output_t * o);


/**
 * Unsets the value of the "name" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_unsetName(Output_t * o);


/**
 * Unsets the value of the "outputLevel" attribute of this Output_t.
 *
 * @param o the Output_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_unsetOutputLevel(Output_t * o);


/**
 * Predicate returning @c 1 if all the required attributes for this Output_t
 * object have been set.
 *
 * @param o the Output_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this Output_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the Output_t object are:
 * @li "qualitativeSpecies"
 * @li "transitionEffect"
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
int
Output_hasRequiredAttributes(const Output_t * o);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Output_H__ */


