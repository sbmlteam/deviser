/**
 * @file SedAddXML.h
 * @brief Definition of the SedAddXML class.
 * @author DEVISER
 *
 * @class SedAddXML
 * @sbmlbrief{sedml} TODO:Definition of the SedAddXML class.
 */


#ifndef SedAddXML_H__
#define SedAddXML_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedChange.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedAddXML : public SedChange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* mNewXML;

  /** @endcond */

public:

  /**
   * Creates a new SedAddXML using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedAddXML.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedAddXML.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedAddXML(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAddXML using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedAddXML(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAddXML.
   *
   * @param orig the SedAddXML instance to copy.
   */
  SedAddXML(const SedAddXML& orig);


  /**
   * Assignment operator for SedAddXML.
   *
   * @param rhs the SedAddXML object whose values are to be used as the basis
   * of the assignment.
   */
  SedAddXML& operator=(const SedAddXML& rhs);


  /**
   * Creates and returns a deep copy of this SedAddXML object.
   *
   * @return a (deep) copy of this SedAddXML object.
   */
  virtual SedAddXML* clone() const;


  /**
   * Destructor for SedAddXML.
   */
  virtual ~SedAddXML();


  /**
   * Returns the value of the "newXML" element of this SedAddXML.
   *
   * @return the value of the "newXML" element of this SedAddXML as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getNewXML() const;


  /**
   * Returns the value of the "newXML" element of this SedAddXML.
   *
   * @return the value of the "newXML" element of this SedAddXML as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getNewXML();


  /**
   * Predicate returning @c true if this SedAddXML's "newXML" element is set.
   *
   * @return @c true if this SedAddXML's "newXML" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetNewXML() const;


  /**
   * Sets the value of the "newXML" element of this SedAddXML.
   *
   * @param newXML LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* value of the
   * "newXML" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNewXML(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* newXML);


  /**
   * Unsets the value of the "newXML" element of this SedAddXML.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNewXML();


  /**
   * Returns the XML element name of this SedAddXML object.
   *
   * For SedAddXML, the XML element name is always @c "addXML".
   *
   * @return the name of this element, i.e. @c "addXML".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedAddXML object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_ADDXML, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAddXML object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAddXML have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedAddXML object are:
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedAddXML object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedAddXML have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedAddXML object are:
   * @li "newXML"
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
 * Creates a new SedAddXML_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this SedAddXML_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedAddXML_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedAddXML_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedAddXML_t object.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @return a (deep) copy of this SedAddXML_t object.
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedAddXML_clone(const SedAddXML_t* saxml);


/**
 * Frees this SedAddXML_t object.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
void
SedAddXML_free(SedAddXML_t* saxml);


/**
 * Returns the value of the "newXML" element of this SedAddXML_t.
 *
 * @param saxml the SedAddXML_t structure whose newXML is sought.
 *
 * @return the value of the "newXML" element of this SedAddXML_t as a
 * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
SedAddXML_getNewXML(const SedAddXML_t * saxml);


/**
 * Predicate returning @c 1 if this SedAddXML_t's "newXML" element is set.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @return @c 1 if this SedAddXML_t's "newXML" element has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
int
SedAddXML_isSetNewXML(const SedAddXML_t * saxml);


/**
 * Sets the value of the "newXML" element of this SedAddXML_t.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @param newXML LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t* value of the
 * "newXML" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
int
SedAddXML_setNewXML(SedAddXML_t * saxml,
                    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t* newXML);


/**
 * Unsets the value of the "newXML" element of this SedAddXML_t.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
int
SedAddXML_unsetNewXML(SedAddXML_t * saxml);


/**
 * Predicate returning @c 1 if all the required attributes for this SedAddXML_t
 * object have been set.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SedAddXML_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedAddXML_t object are:
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredAttributes(const SedAddXML_t * saxml);


/**
 * Predicate returning @c 1 if all the required elements for this SedAddXML_t
 * object have been set.
 *
 * @param saxml the SedAddXML_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this SedAddXML_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the SedAddXML_t object are:
 * @li "newXML"
 *
 * @memberof SedAddXML_t
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredElements(const SedAddXML_t * saxml);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAddXML_H__ */


