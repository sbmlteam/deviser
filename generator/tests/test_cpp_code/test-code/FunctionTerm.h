/**
 * @file FunctionTerm.h
 * @brief Definition of the FunctionTerm class.
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
 * @class FunctionTerm
 * @sbmlbrief{qual} TODO:Definition of the FunctionTerm class.
 */


#ifndef FunctionTerm_H__
#define FunctionTerm_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/qual/extension/QualExtension.h>
#include <sbml/math/ASTNode.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN FunctionTerm : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  unsigned int mResultLevel;
  bool mIsSetResultLevel;
  ASTNode* mMath;

  /** @endcond */

public:

  /**
   * Creates a new FunctionTerm using the given SBML Level, Version and
   * &ldquo;qual&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * FunctionTerm.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * FunctionTerm.
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
   * FunctionTerm.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  FunctionTerm(unsigned int level = QualExtension::getDefaultLevel(),
               unsigned int version = QualExtension::getDefaultVersion(),
               unsigned int pkgVersion =
                 QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new FunctionTerm using the given QualPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param qualns the QualPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  FunctionTerm(QualPkgNamespaces *qualns);


  /**
   * Copy constructor for FunctionTerm.
   *
   * @param orig the FunctionTerm instance to copy.
   */
  FunctionTerm(const FunctionTerm& orig);


  /**
   * Assignment operator for FunctionTerm.
   *
   * @param rhs the FunctionTerm object whose values are to be used as the
   * basis of the assignment.
   */
  FunctionTerm& operator=(const FunctionTerm& rhs);


  /**
   * Creates and returns a deep copy of this FunctionTerm object.
   *
   * @return a (deep) copy of this FunctionTerm object.
   */
  virtual FunctionTerm* clone() const;


  /**
   * Destructor for FunctionTerm.
   */
  virtual ~FunctionTerm();


  /**
   * Returns the value of the "resultLevel" attribute of this FunctionTerm.
   *
   * @return the value of the "resultLevel" attribute of this FunctionTerm as a
   * unsigned integer.
   */
  unsigned int getResultLevel() const;


  /**
   * Predicate returning @c true if this FunctionTerm's "resultLevel" attribute
   * is set.
   *
   * @return @c true if this FunctionTerm's "resultLevel" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetResultLevel() const;


  /**
   * Sets the value of the "resultLevel" attribute of this FunctionTerm.
   *
   * @param resultLevel unsigned int value of the "resultLevel" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setResultLevel(unsigned int resultLevel);


  /**
   * Unsets the value of the "resultLevel" attribute of this FunctionTerm.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetResultLevel();


  /**
   * Returns the value of the "math" element of this FunctionTerm.
   *
   * @return the value of the "math" element of this FunctionTerm as a
   * ASTNode*.
   */
  const ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this FunctionTerm.
   *
   * @return the value of the "math" element of this FunctionTerm as a
   * ASTNode*.
   */
  ASTNode* getMath();


  /**
   * Predicate returning @c true if this FunctionTerm's "math" element is set.
   *
   * @return @c true if this FunctionTerm's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Sets the value of the "math" element of this FunctionTerm.
   *
   * @param math ASTNode* value of the "math" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMath(const ASTNode* math);


  /**
   * Unsets the value of the "math" element of this FunctionTerm.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this FunctionTerm object.
   *
   * For FunctionTerm, the XML element name is always @c "functionTerm".
   *
   * @return the name of this element, i.e. @c "functionTerm".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this FunctionTerm object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_QUAL_FUNCTION_TERM, SBMLQualTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * FunctionTerm object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * FunctionTerm have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the FunctionTerm object are:
   * @li "resultLevel"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * FunctionTerm object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * FunctionTerm have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the FunctionTerm object are:
   * @li "math"
   */
  virtual bool hasRequiredElements() const;



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
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Updates the namespaces when setLevelVersion is used
   */
  virtual void updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this FunctionTerm's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this FunctionTerm's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this FunctionTerm.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


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
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(XMLInputStream& stream);

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
 * Creates a new FunctionTerm_t using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * FunctionTerm_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * FunctionTerm_t.
 *
 * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
 * FunctionTerm_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
FunctionTerm_t *
FunctionTerm_create(unsigned int level,
                    unsigned int version,
                    unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this FunctionTerm_t object.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @return a (deep) copy of this FunctionTerm_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
FunctionTerm_t*
FunctionTerm_clone(const FunctionTerm_t* ft);


/**
 * Frees this FunctionTerm_t object.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
void
FunctionTerm_free(FunctionTerm_t* ft);


/**
 * Returns the value of the "resultLevel" attribute of this FunctionTerm_t.
 *
 * @param ft the FunctionTerm_t structure whose resultLevel is sought.
 *
 * @return the value of the "resultLevel" attribute of this FunctionTerm_t as a
 * unsigned integer.
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
unsigned int
FunctionTerm_getResultLevel(const FunctionTerm_t * ft);


/**
 * Predicate returning @c 1 (true) if this FunctionTerm_t's "resultLevel"
 * attribute is set.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @return @c 1 (true) if this FunctionTerm_t's "resultLevel" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_isSetResultLevel(const FunctionTerm_t * ft);


/**
 * Sets the value of the "resultLevel" attribute of this FunctionTerm_t.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @param resultLevel unsigned int value of the "resultLevel" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_setResultLevel(FunctionTerm_t * ft, unsigned int resultLevel);


/**
 * Unsets the value of the "resultLevel" attribute of this FunctionTerm_t.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_unsetResultLevel(FunctionTerm_t * ft);


/**
 * Returns the value of the "math" element of this FunctionTerm_t.
 *
 * @param ft the FunctionTerm_t structure whose math is sought.
 *
 * @return the value of the "math" element of this FunctionTerm_t as a pointer
 * to an ASTNode_t object.
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
const ASTNode_t*
FunctionTerm_getMath(const FunctionTerm_t * ft);


/**
 * Predicate returning @c 1 (true) if this FunctionTerm_t's "math" element is
 * set.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @return @c 1 (true) if this FunctionTerm_t's "math" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_isSetMath(const FunctionTerm_t * ft);


/**
 * Sets the value of the "math" element of this FunctionTerm_t.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @param math ASTNode_t * pointer to the "math" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_setMath(FunctionTerm_t * ft, const ASTNode_t* math);


/**
 * Unsets the value of the "math" element of this FunctionTerm_t.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_unsetMath(FunctionTerm_t * ft);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * FunctionTerm_t object have been set.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * FunctionTerm_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the FunctionTerm_t object are:
 * @li "resultLevel"
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_hasRequiredAttributes(const FunctionTerm_t * ft);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * FunctionTerm_t object have been set.
 *
 * @param ft the FunctionTerm_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * FunctionTerm_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the FunctionTerm_t object are:
 * @li "math"
 *
 * @memberof FunctionTerm_t
 */
LIBSBML_EXTERN
int
FunctionTerm_hasRequiredElements(const FunctionTerm_t * ft);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !FunctionTerm_H__ */


