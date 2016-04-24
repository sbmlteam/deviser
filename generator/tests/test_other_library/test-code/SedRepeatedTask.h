/**
 * @file SedRepeatedTask.h
 * @brief Definition of the SedRepeatedTask class.
 * @author DEVISER
 *
 * @class SedRepeatedTask
 * @sbmlbrief{sedml} TODO:Definition of the SedRepeatedTask class.
 */


#ifndef SedRepeatedTask_H__
#define SedRepeatedTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedTask.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedRepeatedTask : public SedTask
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mRangeId;
  bool mResetModel;
  bool mIsSetResetModel;

  /** @endcond */

public:

  /**
   * Creates a new SedRepeatedTask using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedRepeatedTask.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedRepeatedTask.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedRepeatedTask(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedRepeatedTask using the given SedNamespaces object @p
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
  SedRepeatedTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedRepeatedTask.
   *
   * @param orig the SedRepeatedTask instance to copy.
   */
  SedRepeatedTask(const SedRepeatedTask& orig);


  /**
   * Assignment operator for SedRepeatedTask.
   *
   * @param rhs the SedRepeatedTask object whose values are to be used as the
   * basis of the assignment.
   */
  SedRepeatedTask& operator=(const SedRepeatedTask& rhs);


  /**
   * Creates and returns a deep copy of this SedRepeatedTask object.
   *
   * @return a (deep) copy of this SedRepeatedTask object.
   */
  virtual SedRepeatedTask* clone() const;


  /**
   * Destructor for SedRepeatedTask.
   */
  virtual ~SedRepeatedTask();


  /**
   * Returns the value of the "rangeId" attribute of this SedRepeatedTask.
   *
   * @return the value of the "rangeId" attribute of this SedRepeatedTask as a
   * string.
   */
  const std::string& getRangeId() const;


  /**
   * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
   *
   * @return the value of the "resetModel" attribute of this SedRepeatedTask as
   * a boolean.
   */
  bool getResetModel() const;


  /**
   * Predicate returning @c true if this SedRepeatedTask's "rangeId" attribute
   * is set.
   *
   * @return @c true if this SedRepeatedTask's "rangeId" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetRangeId() const;


  /**
   * Predicate returning @c true if this SedRepeatedTask's "resetModel"
   * attribute is set.
   *
   * @return @c true if this SedRepeatedTask's "resetModel" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetResetModel() const;


  /**
   * Sets the value of the "rangeId" attribute of this SedRepeatedTask.
   *
   * @param rangeId std::string& value of the "rangeId" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRangeId(const std::string& rangeId);


  /**
   * Sets the value of the "resetModel" attribute of this SedRepeatedTask.
   *
   * @param resetModel bool value of the "resetModel" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setResetModel(bool resetModel);


  /**
   * Unsets the value of the "rangeId" attribute of this SedRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRangeId();


  /**
   * Unsets the value of the "resetModel" attribute of this SedRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetResetModel();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedRepeatedTask object.
   *
   * For SedRepeatedTask, the XML element name is always @c "repeatedTask".
   *
   * @return the name of this element, i.e. @c "repeatedTask".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedRepeatedTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_TASK_REPEATEDTASK, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedRepeatedTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedRepeatedTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedRepeatedTask object are:
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

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


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedRepeatedTask_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedRepeatedTask_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedRepeatedTask_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedRepeatedTask_t object.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return a (deep) copy of this SedRepeatedTask_t object.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t*
SedRepeatedTask_clone(const SedRepeatedTask_t* srt);


/**
 * Frees this SedRepeatedTask_t object.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t* srt);


/**
 * Returns the value of the "rangeId" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose rangeId is sought.
 *
 * @return the value of the "rangeId" attribute of this SedRepeatedTask_t as a
 * pointer to a string.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
const char *
SedRepeatedTask_getRangeId(const SedRepeatedTask_t * srt);


/**
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose resetModel is sought.
 *
 * @return the value of the "resetModel" attribute of this SedRepeatedTask_t as
 * a boolean.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(const SedRepeatedTask_t * srt);


/**
 * Predicate returning @c 1 if this SedRepeatedTask_t's "rangeId" attribute is
 * set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 if this SedRepeatedTask_t's "rangeId" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRangeId(const SedRepeatedTask_t * srt);


/**
 * Predicate returning @c 1 if this SedRepeatedTask_t's "resetModel" attribute
 * is set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 if this SedRepeatedTask_t's "resetModel" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(const SedRepeatedTask_t * srt);


/**
 * Sets the value of the "rangeId" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @param rangeId const char * value of the "rangeId" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setRangeId(SedRepeatedTask_t * srt, const char * rangeId);


/**
 * Sets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @param resetModel int value of the "resetModel" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel);


/**
 * Unsets the value of the "rangeId" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRangeId(SedRepeatedTask_t * srt);


/**
 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * SedRepeatedTask_t object have been set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SedRepeatedTask_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedRepeatedTask_t object are:
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(const SedRepeatedTask_t * srt);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedRepeatedTask_H__ */


