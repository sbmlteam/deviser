/**
 * @file Def.h
 * @brief Definition of the Def class.
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
 * This file is part of SOMETHING.
 * 

 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. Abcdefg
 * 2. Hijklmonp
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class Def
 * @sbmlbrief{copy} TODO:Definition of the Def class.
 */


#ifndef Def_H__
#define Def_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/copy/common/copyfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/copy/extension/CopyExtension.h>
#include <sbml/xml/XMLNode.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Def : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mLetter;
  XMLNode* mMess;

  /** @endcond */

public:

  /**
   * Creates a new Def using the given SBML Level, Version and
   * &ldquo;copy&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Def.
   *
   * @param version an unsigned int, the SBML Version to assign to this Def.
   *
   * @param pkgVersion an unsigned int, the SBML Copy Version to assign to this
   * Def.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Def(unsigned int level = CopyExtension::getDefaultLevel(),
      unsigned int version = CopyExtension::getDefaultVersion(),
      unsigned int pkgVersion = CopyExtension::getDefaultPackageVersion());


  /**
   * Creates a new Def using the given CopyPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param copyns the CopyPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Def(CopyPkgNamespaces *copyns);


  /**
   * Copy constructor for Def.
   *
   * @param orig the Def instance to copy.
   */
  Def(const Def& orig);


  /**
   * Assignment operator for Def.
   *
   * @param rhs the Def object whose values are to be used as the basis of the
   * assignment.
   */
  Def& operator=(const Def& rhs);


  /**
   * Creates and returns a deep copy of this Def object.
   *
   * @return a (deep) copy of this Def object.
   */
  virtual Def* clone() const;


  /**
   * Destructor for Def.
   */
  virtual ~Def();


  /**
   * Returns the value of the "letter" attribute of this Def.
   *
   * @return the value of the "letter" attribute of this Def as a string.
   */
  const std::string& getLetter() const;


  /**
   * Predicate returning @c true if this Def's "letter" attribute is set.
   *
   * @return @c true if this Def's "letter" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetLetter() const;


  /**
   * Sets the value of the "letter" attribute of this Def.
   *
   * @param letter std::string& value of the "letter" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p letter = @c NULL is equivalent to calling
   * unsetLetter().
   */
  int setLetter(const std::string& letter);


  /**
   * Unsets the value of the "letter" attribute of this Def.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLetter();


  /**
   * Returns the value of the "mess" element of this Def.
   *
   * @return the value of the "mess" element of this Def as a XMLNode*.
   */
  const XMLNode* getMess() const;


  /**
   * Returns the value of the "mess" element of this Def.
   *
   * @return the value of the "mess" element of this Def as a XMLNode*.
   */
  XMLNode* getMess();


  /**
   * Predicate returning @c true if this Def's "mess" element is set.
   *
   * @return @c true if this Def's "mess" element has been set, otherwise @c
   * false is returned.
   */
  bool isSetMess() const;


  /**
   * Sets the value of the "mess" element of this Def.
   *
   * @param mess XMLNode* value of the "mess" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMess(const XMLNode* mess);


  /**
   * Unsets the value of the "mess" element of this Def.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMess();


  /**
   * Returns the XML element name of this Def object.
   *
   * For Def, the XML element name is always @c "def".
   *
   * @return the name of this element, i.e. @c "def".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Def object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_COPY_ABC, SBMLCopyTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Def
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Def
   * have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this Def
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Def
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Def object are:
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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Def.
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
   * Gets the value of the "attributeName" attribute of this Def.
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
   * Gets the value of the "attributeName" attribute of this Def.
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
   * Gets the value of the "attributeName" attribute of this Def.
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
   * Gets the value of the "attributeName" attribute of this Def.
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
   * Gets the value of the "attributeName" attribute of this Def.
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
   * Predicate returning @c true if this Def's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Def's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Def.
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
   * Sets the value of the "attributeName" attribute of this Def.
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
   * Sets the value of the "attributeName" attribute of this Def.
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
   * Sets the value of the "attributeName" attribute of this Def.
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
   * Sets the value of the "attributeName" attribute of this Def.
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
   * Sets the value of the "attributeName" attribute of this Def.
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
   * Unsets the value of the "attributeName" attribute of this Def.
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
 * Creates a new Def_t using the given SBML Level, Version and
 * &ldquo;copy&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Def_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Def_t.
 *
 * @param pkgVersion an unsigned int, the SBML Copy Version to assign to this
 * Def_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
Def_t *
Def_create(unsigned int level, unsigned int version, unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Def_t object.
 *
 * @param d the Def_t structure.
 *
 * @return a (deep) copy of this Def_t object.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
Def_t*
Def_clone(const Def_t* d);


/**
 * Frees this Def_t object.
 *
 * @param d the Def_t structure.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
void
Def_free(Def_t* d);


/**
 * Returns the value of the "letter" attribute of this Def_t.
 *
 * @param d the Def_t structure whose letter is sought.
 *
 * @return the value of the "letter" attribute of this Def_t as a pointer to a
 * string.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
const char *
Def_getLetter(const Def_t * d);


/**
 * Predicate returning @c 1 (true) if this Def_t's "letter" attribute is set.
 *
 * @param d the Def_t structure.
 *
 * @return @c 1 (true) if this Def_t's "letter" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_isSetLetter(const Def_t * d);


/**
 * Sets the value of the "letter" attribute of this Def_t.
 *
 * @param d the Def_t structure.
 *
 * @param letter const char * value of the "letter" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * Calling this function with @p letter = @c NULL is equivalent to calling
 * Def_unsetLetter().
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_setLetter(Def_t * d, const char * letter);


/**
 * Unsets the value of the "letter" attribute of this Def_t.
 *
 * @param d the Def_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_unsetLetter(Def_t * d);


/**
 * Returns the value of the "mess" element of this Def_t.
 *
 * @param d the Def_t structure whose mess is sought.
 *
 * @return the value of the "mess" element of this Def_t as a XMLNode*.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
const XMLNode_t*
Def_getMess(const Def_t * d);


/**
 * Predicate returning @c 1 (true) if this Def_t's "mess" element is set.
 *
 * @param d the Def_t structure.
 *
 * @return @c 1 (true) if this Def_t's "mess" element has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_isSetMess(const Def_t * d);


/**
 * Sets the value of the "mess" element of this Def_t.
 *
 * @param d the Def_t structure.
 *
 * @param mess XMLNode_t* value of the "mess" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_setMess(Def_t * d, const XMLNode_t* mess);


/**
 * Unsets the value of the "mess" element of this Def_t.
 *
 * @param d the Def_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_unsetMess(Def_t * d);


/**
 * Predicate returning @c 1 if all the required attributes for this Def_t
 * object have been set.
 *
 * @param d the Def_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this Def_t have
 * been set, otherwise @c 0 is returned.
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_hasRequiredAttributes(const Def_t * d);


/**
 * Predicate returning @c 1 if all the required elements for this Def_t object
 * have been set.
 *
 * @param d the Def_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this Def_t have
 * been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the Def_t object are:
 *
 * @memberof Def_t
 */
LIBSBML_EXTERN
int
Def_hasRequiredElements(const Def_t * d);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Def_H__ */


