/**
 * @file SedDataGenerator.h
 * @brief Definition of the SedDataGenerator class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedDataGenerator
 * @sbmlbrief{sedml} TODO:Definition of the SedDataGenerator class.
 */


#ifndef SedDataGenerator_H__
#define SedDataGenerator_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/math/ASTNode.h>
#include <sedml/SedListOfVariables.h>
#include <sedml/SedListOfParameters.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataGenerator : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mId;
  std::string mName;
  SedListOfVariables mVariables;
  SedListOfParameters mParameters;
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* mMath;

  /** @endcond */

public:

  /**
   * Creates a new SedDataGenerator using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedDataGenerator.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedDataGenerator.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedDataGenerator(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataGenerator using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedDataGenerator(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDataGenerator.
   *
   * @param orig the SedDataGenerator instance to copy.
   */
  SedDataGenerator(const SedDataGenerator& orig);


  /**
   * Assignment operator for SedDataGenerator.
   *
   * @param rhs the SedDataGenerator object whose values are to be used as the
   * basis of the assignment.
   */
  SedDataGenerator& operator=(const SedDataGenerator& rhs);


  /**
   * Creates and returns a deep copy of this SedDataGenerator object.
   *
   * @return a (deep) copy of this SedDataGenerator object.
   */
  virtual SedDataGenerator* clone() const;


  /**
   * Destructor for SedDataGenerator.
   */
  virtual ~SedDataGenerator();


  /**
   * Returns the value of the "id" attribute of this SedDataGenerator.
   *
   * @return the value of the "id" attribute of this SedDataGenerator as a
   * string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this SedDataGenerator.
   *
   * @return the value of the "name" attribute of this SedDataGenerator as a
   * string.
   */
  const std::string& getName() const;


  /**
   * Predicate returning @c true if this SedDataGenerator's "id" attribute is
   * set.
   *
   * @return @c true if this SedDataGenerator's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this SedDataGenerator's "name" attribute is
   * set.
   *
   * @return @c true if this SedDataGenerator's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetName() const;


  /**
   * Sets the value of the "id" attribute of this SedDataGenerator.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this SedDataGenerator.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setName(const std::string& name);


  /**
   * Unsets the value of the "id" attribute of this SedDataGenerator.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "name" attribute of this SedDataGenerator.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetName();


  /**
   * Returns the value of the "math" element of this SedDataGenerator.
   *
   * @return the value of the "math" element of this SedDataGenerator as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this SedDataGenerator.
   *
   * @return the value of the "math" element of this SedDataGenerator as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath();


  /**
   * Predicate returning @c true if this SedDataGenerator's "math" element is
   * set.
   *
   * @return @c true if this SedDataGenerator's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Sets the value of the "math" element of this SedDataGenerator.
   *
   * @param math LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* value of the "math"
   * element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* math);


  /**
   * Unsets the value of the "math" element of this SedDataGenerator.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * Returns the SedListOfVariables from this SedDataGenerator.
   *
   * @return the SedListOfVariables from this SedDataGenerator.
   */
  const SedListOfVariables* getListOfVariables() const;


  /**
   * Returns the SedListOfVariables from this SedDataGenerator.
   *
   * @return the SedListOfVariables from this SedDataGenerator.
   */
  SedListOfVariables* getListOfVariables();


  /**
   * Get a SedVariable from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedDataGenerator.
   *
   * @see getNumVariables()
   */
  SedVariable* getVariable(unsigned int n);


  /**
   * Get a SedVariable from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedDataGenerator.
   *
   * @see getNumVariables()
   */
  const SedVariable* getVariable(unsigned int n) const;


  /**
   * Adds a copy of the given SedVariable to this SedDataGenerator.
   *
   * @param sv the SedVariable object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createVariable()
   */
  int addVariable(const SedVariable* sv);


  /**
   * Get the number of SedVariable objects in this SedDataGenerator.
   *
   * @return the number of SedVariable objects in this SedDataGenerator.
   */
  unsigned int getNumVariables() const;


  /**
   * Creates a new SedVariable object, adds it to this SedDataGenerator object
   * and returns the SedVariable object created.
   *
   * @return a new SedVariable object instance.
   *
   * @see addVariable(const SedVariable* sv)
   */
  SedVariable* createVariable();


  /**
   * Removes the nth SedVariable from this SedDataGenerator and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * remove.
   *
   * @return a pointer to the nth SedVariable in this SedDataGenerator.
   *
   * @see getNumVariables
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  SedVariable* removeVariable(unsigned int n);


  /**
   * Returns the SedListOfParameters from this SedDataGenerator.
   *
   * @return the SedListOfParameters from this SedDataGenerator.
   */
  const SedListOfParameters* getListOfParameters() const;


  /**
   * Returns the SedListOfParameters from this SedDataGenerator.
   *
   * @return the SedListOfParameters from this SedDataGenerator.
   */
  SedListOfParameters* getListOfParameters();


  /**
   * Get a SedParameter from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedDataGenerator.
   *
   * @see getNumParameters()
   */
  SedParameter* getParameter(unsigned int n);


  /**
   * Get a SedParameter from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedDataGenerator.
   *
   * @see getNumParameters()
   */
  const SedParameter* getParameter(unsigned int n) const;


  /**
   * Adds a copy of the given SedParameter to this SedDataGenerator.
   *
   * @param sp the SedParameter object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createParameter()
   */
  int addParameter(const SedParameter* sp);


  /**
   * Get the number of SedParameter objects in this SedDataGenerator.
   *
   * @return the number of SedParameter objects in this SedDataGenerator.
   */
  unsigned int getNumParameters() const;


  /**
   * Creates a new SedParameter object, adds it to this SedDataGenerator object
   * and returns the SedParameter object created.
   *
   * @return a new SedParameter object instance.
   *
   * @see addParameter(const SedParameter* sp)
   */
  SedParameter* createParameter();


  /**
   * Removes the nth SedParameter from this SedDataGenerator and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * remove.
   *
   * @return a pointer to the nth SedParameter in this SedDataGenerator.
   *
   * @see getNumParameters
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  SedParameter* removeParameter(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedDataGenerator object.
   *
   * For SedDataGenerator, the XML element name is always @c "dataGenerator".
   *
   * @return the name of this element, i.e. @c "dataGenerator".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDataGenerator object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_DATAGENERATOR, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDataGenerator object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDataGenerator have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDataGenerator object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedDataGenerator object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedDataGenerator have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedDataGenerator object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Accepts the given SedVisitor
   */
  virtual bool accept(SedVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the parent SedDocument
   */
  virtual void setSedDocument(SedDocument* d);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SedBase element with the given @p id.
   */
  virtual SedBase* getElementBySId(const std::string& id);


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedDataGenerator_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedDataGenerator_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedDataGenerator_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t *
SedDataGenerator_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDataGenerator_t object.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return a (deep) copy of this SedDataGenerator_t object.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDataGenerator_clone(const SedDataGenerator_t* sdg);


/**
 * Frees this SedDataGenerator_t object.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
void
SedDataGenerator_free(SedDataGenerator_t* sdg);


/**
 * Returns the value of the "id" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedDataGenerator_t as a
 * pointer to a string.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
const char *
SedDataGenerator_getId(const SedDataGenerator_t * sdg);


/**
 * Returns the value of the "name" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedDataGenerator_t as a
 * pointer to a string.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
const char *
SedDataGenerator_getName(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 if this SedDataGenerator_t's "id" attribute is set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 if this SedDataGenerator_t's "id" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetId(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 if this SedDataGenerator_t's "name" attribute is
 * set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 if this SedDataGenerator_t's "name" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetName(const SedDataGenerator_t * sdg);


/**
 * Sets the value of the "id" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setId(SedDataGenerator_t * sdg, const char * id);


/**
 * Sets the value of the "name" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setName(SedDataGenerator_t * sdg, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetId(SedDataGenerator_t * sdg);


/**
 * Unsets the value of the "name" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetName(SedDataGenerator_t * sdg);


/**
 * Returns the value of the "math" element of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose math is sought.
 *
 * @return the value of the "math" element of this SedDataGenerator_t as a
 * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedDataGenerator_getMath(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 if this SedDataGenerator_t's "math" element is set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 if this SedDataGenerator_t's "math" element has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetMath(const SedDataGenerator_t * sdg);


/**
 * Sets the value of the "math" element of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @param math LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* value of the "math"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setMath(SedDataGenerator_t * sdg,
                         const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
                           math);


/**
 * Unsets the value of the "math" element of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetMath(SedDataGenerator_t * sdg);


/**
 * Returns a ListOf_t* containing SedVariable_t objects from this
 * SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose "SedListOfVariables" is
 * sought.
 *
 * @return the "SedListOfVariables" from this SedDataGenerator_t as a ListOf_t
 * *.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataGenerator_getListOfVariables(SedDataGenerator_t* sdg);


/**
 * Get a SedVariable_t from the SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * retrieve.
 *
 * @return the nth SedVariable_t in the SedListOfVariables within this
 * SedDataGenerator.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
const SedVariable_t*
SedDataGenerator_getVariable(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Adds a copy of the given SedVariable_t to this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedVariable_t
 * should be added.
 *
 * @param sv the SedVariable_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_addVariable(SedDataGenerator_t* sdg,
                             const SedVariable_t* sv);


/**
 * Get the number of SedVariable_t objects in this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to query.
 *
 * @return the number of SedVariable_t objects in this SedDataGenerator_t.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumVariables(SedDataGenerator_t* sdg);


/**
 * Creates a new SedVariable_t object, adds it to this SedDataGenerator_t
 * object and returns the SedVariable_t object created.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedVariable_t
 * should be added.
 *
 * @return a new SedVariable_t object instance.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_createVariable(SedDataGenerator_t* sdg);


/**
 * Removes the nth SedVariable_t from this SedDataGenerator_t and returns a
 * pointer to it.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * remove.
 *
 * @return a pointer to the nth SedVariable_t in this SedDataGenerator_t.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_removeVariable(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Returns a ListOf_t* containing SedParameter_t objects from this
 * SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose "SedListOfParameters" is
 * sought.
 *
 * @return the "SedListOfParameters" from this SedDataGenerator_t as a ListOf_t
 * *.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataGenerator_getListOfParameters(SedDataGenerator_t* sdg);


/**
 * Get a SedParameter_t from the SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * retrieve.
 *
 * @return the nth SedParameter_t in the SedListOfParameters within this
 * SedDataGenerator.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
const SedParameter_t*
SedDataGenerator_getParameter(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Adds a copy of the given SedParameter_t to this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedParameter_t
 * should be added.
 *
 * @param sp the SedParameter_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_addParameter(SedDataGenerator_t* sdg,
                              const SedParameter_t* sp);


/**
 * Get the number of SedParameter_t objects in this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to query.
 *
 * @return the number of SedParameter_t objects in this SedDataGenerator_t.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumParameters(SedDataGenerator_t* sdg);


/**
 * Creates a new SedParameter_t object, adds it to this SedDataGenerator_t
 * object and returns the SedParameter_t object created.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedParameter_t
 * should be added.
 *
 * @return a new SedParameter_t object instance.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_createParameter(SedDataGenerator_t* sdg);


/**
 * Removes the nth SedParameter_t from this SedDataGenerator_t and returns a
 * pointer to it.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * remove.
 *
 * @return a pointer to the nth SedParameter_t in this SedDataGenerator_t.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_removeParameter(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * SedDataGenerator_t object have been set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SedDataGenerator_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedDataGenerator_t object are:
 * @li "id"
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredAttributes(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 if all the required elements for this
 * SedDataGenerator_t object have been set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * SedDataGenerator_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the SedDataGenerator_t object are:
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredElements(const SedDataGenerator_t * sdg);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDataGenerator_H__ */


