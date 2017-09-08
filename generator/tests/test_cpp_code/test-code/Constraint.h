/**
 * @file Constraint.h
 * @brief Definition of the Constraint class.
 * @author DEVISER
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
 * @class Constraint
 * @sbmlbrief{core} TODO:Definition of the Constraint class.
 */


#ifndef Constraint_H__
#define Constraint_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/math/ASTNode.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Constraint : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* mMath;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* mMessage;

  /** @endcond */

public:

  /**
   * Creates a new Constraint using the given SBML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBML Level to assign to this Constraint.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Constraint.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Constraint(unsigned int level = SBML_DEFAULT_LEVEL,
             unsigned int version = SBML_DEFAULT_VERSION);


  /**
   * Creates a new Constraint using the given SBMLNamespaces object @p sbmlns.
   *
   * @param sbmlns the SBMLNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Constraint(SBMLNamespaces *sbmlns);


  /**
   * Copy constructor for Constraint.
   *
   * @param orig the Constraint instance to copy.
   */
  Constraint(const Constraint& orig);


  /**
   * Assignment operator for Constraint.
   *
   * @param rhs the Constraint object whose values are to be used as the basis
   * of the assignment.
   */
  Constraint& operator=(const Constraint& rhs);


  /**
   * Creates and returns a deep copy of this Constraint object.
   *
   * @return a (deep) copy of this Constraint object.
   */
  virtual Constraint* clone() const;


  /**
   * Destructor for Constraint.
   */
  virtual ~Constraint();


  /**
   * Returns the value of the "math" element of this Constraint.
   *
   * @return the value of the "math" element of this Constraint as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this Constraint.
   *
   * @return the value of the "math" element of this Constraint as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath();


  /**
   * Returns the value of the "message" element of this Constraint.
   *
   * @return the value of the "message" element of this Constraint as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getMessage() const;


  /**
   * Returns the value of the "message" element of this Constraint.
   *
   * @return the value of the "message" element of this Constraint as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getMessage();


  /**
   * Predicate returning @c true if this Constraint's "math" element is set.
   *
   * @return @c true if this Constraint's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Predicate returning @c true if this Constraint's "message" element is set.
   *
   * @return @c true if this Constraint's "message" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMessage() const;


  /**
   * Sets the value of the "math" element of this Constraint.
   *
   * @param math LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* value of the "math"
   * element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* math);


  /**
   * Sets the value of the "message" element of this Constraint.
   *
   * @param message LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* value of the
   * "message" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMessage(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* message);


  /**
   * Unsets the value of the "math" element of this Constraint.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * Unsets the value of the "message" element of this Constraint.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMessage();


  /**
   * Returns the XML element name of this Constraint object.
   *
   * For Constraint, the XML element name is always @c "".
   *
   * @return the name of this element, i.e. @c "".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Constraint object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{CORE_CONSTRAINT, SBMLCoreTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * Constraint object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * Constraint have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Constraint object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Constraint.
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
   * Gets the value of the "attributeName" attribute of this Constraint.
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
   * Gets the value of the "attributeName" attribute of this Constraint.
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
   * Gets the value of the "attributeName" attribute of this Constraint.
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
   * Gets the value of the "attributeName" attribute of this Constraint.
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
   * Gets the value of the "attributeName" attribute of this Constraint.
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
                           const char* value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this Constraint's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Constraint's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Constraint.
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
   * Sets the value of the "attributeName" attribute of this Constraint.
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
   * Sets the value of the "attributeName" attribute of this Constraint.
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
   * Sets the value of the "attributeName" attribute of this Constraint.
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
   * Sets the value of the "attributeName" attribute of this Constraint.
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
   * Sets the value of the "attributeName" attribute of this Constraint.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, const char*
    value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this Constraint.
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
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Constraint_t using the given SBML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SBML Level to assign to this Constraint_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Constraint_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
Constraint_t *
Constraint_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Constraint_t object.
 *
 * @param c the Constraint_t structure.
 *
 * @return a (deep) copy of this Constraint_t object.
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
Constraint_t*
Constraint_clone(const Constraint_t* c);


/**
 * Frees this Constraint_t object.
 *
 * @param c the Constraint_t structure.
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
void
Constraint_free(Constraint_t* c);


/**
 * Returns the value of the "math" element of this Constraint_t.
 *
 * @param c the Constraint_t structure whose math is sought.
 *
 * @return the value of the "math" element of this Constraint_t as a
 * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
Constraint_getMath(const Constraint_t * c);


/**
 * Returns the value of the "message" element of this Constraint_t.
 *
 * @param c the Constraint_t structure whose message is sought.
 *
 * @return the value of the "message" element of this Constraint_t as a
 * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
Constraint_getMessage(const Constraint_t * c);


/**
 * Predicate returning @c 1 (true) if this Constraint_t's "math" element is
 * set.
 *
 * @param c the Constraint_t structure.
 *
 * @return @c 1 (true) if this Constraint_t's "math" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_isSetMath(const Constraint_t * c);


/**
 * Predicate returning @c 1 (true) if this Constraint_t's "message" element is
 * set.
 *
 * @param c the Constraint_t structure.
 *
 * @return @c 1 (true) if this Constraint_t's "message" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_isSetMessage(const Constraint_t * c);


/**
 * Sets the value of the "math" element of this Constraint_t.
 *
 * @param c the Constraint_t structure.
 *
 * @param math LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* value of the "math"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_setMath(Constraint_t * c,
                   const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* math);


/**
 * Sets the value of the "message" element of this Constraint_t.
 *
 * @param c the Constraint_t structure.
 *
 * @param message LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t* value of the
 * "message" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_setMessage(Constraint_t * c,
                      const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
                        message);


/**
 * Unsets the value of the "math" element of this Constraint_t.
 *
 * @param c the Constraint_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_unsetMath(Constraint_t * c);


/**
 * Unsets the value of the "message" element of this Constraint_t.
 *
 * @param c the Constraint_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_unsetMessage(Constraint_t * c);


/**
 * Predicate returning @c 1 if all the required elements for this Constraint_t
 * object have been set.
 *
 * @param c the Constraint_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this Constraint_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the Constraint_t object are:
 *
 * @memberof Constraint_t
 */
LIBSBML_EXTERN
int
Constraint_hasRequiredElements(const Constraint_t * c);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Constraint_H__ */


