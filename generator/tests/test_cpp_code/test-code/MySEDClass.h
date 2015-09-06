/**
 * @file: MySEDClass.h
 * @brief: Definition of MySEDClass.
 * @author: SBMLTeam
 */


#ifndef MySEDClass_H__
#define MySEDClass_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SEDBase.h>
#include <sedml/packages/test/extension/TestExtension.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN MySEDClass : public SEDBase
{
protected:

  /** @cond doxygenLibsedmlInternal */

  std::string mId;

  /** @endcond */

public:

  /**
   * Creates a new MySEDClass using the given SEDML @p level, @ p version and
   * package version values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this MySEDClass
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * MySEDClass
   *
   * @param pkgVersion an unsigned int, the SEDML Test Version to assign to
   * this MySEDClass
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SEDMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MySEDClass(unsigned int level = TestExtension::getDefaultLevel(),
             unsigned int version = TestExtension::getDefaultVersion(),
             unsigned int pkgVersion =
               TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new MySEDClass using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SEDMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MySEDClass(TestPkgNamespaces *testns);


  /**
   * Copy constructor for MySEDClass.
   *
   * @param orig; the MySEDClass instance to copy.
   */
  MySEDClass(const MySEDClass& orig);


  /**
   * Assignment operator for MySEDClass.
   *
   * @param rhs; the MySEDClass object whose values are to be used as the basis
   * of the assignment
   */
  MySEDClass& operator=(const MySEDClass& rhs);


  /**
   * Creates and returns a deep copy of this MySEDClass object.
   *
   * @return a (deep) copy of this MySEDClass object.
   */
  virtual MySEDClass* clone() const;


  /**
   * Destructor for MySEDClass.
   */
  virtual ~MySEDClass();


  /**
   * Returns the value of the "id" attribute of this MySEDClass.
   *
   * @return the value of the "id" attribute of this MySEDClass as a string.
   */
  const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MySEDClass's "id" attribute has been set.
   *
   * @return @c true if this MySEDClass's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this MySEDClass.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant {LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Unsets the value of the "id" attribute of this MySEDClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Returns the XML name of this MySEDClass object.
   *
   * @return the name of this element; that is "mySEDClass".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML typcode of this MySEDClass object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{MY_TEST_TYPE, SEDMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * MySEDClass object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * MySEDClass have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the MySEDClass object are:
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsedmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsedmlInternal */

  /**
   * Accepts the given SEDMLVisitor
   */
  virtual bool accept(SEDMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsedmlInternal */

  /**
   * Sets the parent SEDMLDocument
   */
  virtual void setSEDMLDocument(SEDMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsedmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


protected:


  /** @cond doxygenLibsedmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsedmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsedmlInternal */

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
 * Creates a new MySEDClass_t using the given SEDML @p level, @ p version and
 * package version values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this MySEDClass_t
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * MySEDClass_t
 *
 * @param pkgVersion an unsigned int, the SEDML Test Version to assign to this
 * MySEDClass_t
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SEDMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
MySEDClass_t *
MySEDClass_create(unsigned int level = TestExtension::getDefaultLevel(),
                  unsigned int version = TestExtension::getDefaultVersion(),
                  unsigned int pkgVersion =
                    TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this MySEDClass_t object.
 *
 * @param msedc; the MySEDClass_t structure
 *
 * @return a (deep) copy of this MySEDClass_t object.
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
MySEDClass_t*
MySEDClass_clone(const MySEDClass_t* msedc);


/**
 * Frees this MySEDClass_t object.
 *
 * @param msedc; the MySEDClass_t structure
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
void
MySEDClass_free(MySEDClass_t* msedc);


/**
 * Returns the value of the "id" attribute of this MySEDClass_t.
 *
 * @param msedc the MySEDClass_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this MySEDClass_t as a pointer to
 * a string.
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
const char *
MySEDClass_getId(const MySEDClass_t * msedc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MySEDClass_t's
 * "id" attribute has been set.
 *
 * @param msedc the MySEDClass_t structure.
 *
 * @return @c 1 if this MySEDClass_t's "id" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
int
MySEDClass_isSetId(const MySEDClass_t * msedc);


/**
 * Sets the value of the "id" attribute of this MySEDClass_t.
 *
 * @param msedc the MySEDClass_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant {LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
int
MySEDClass_setId(MySEDClass_t * msedc, const char * id);


/**
 * Unsets the value of the "id" attribute of this MySEDClass_t.
 *
 * @param msedc the MySEDClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
int
MySEDClass_unsetId(MySEDClass_t * msedc);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * MySEDClass_t object have been set.
 *
 * @param msedc the MySEDClass_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * MySEDClass_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the MySEDClass_t object are:
 *
 * @memberof MySEDClass_t
 */
LIBSEDML_EXTERN
int
MySEDClass_hasRequiredAttributes(const MySEDClass_t * msedc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !MySEDClass_H__ */


