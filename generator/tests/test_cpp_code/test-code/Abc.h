/**
 * @file Abc.h
 * @brief Definition of the Abc class.
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
 * @class Abc
 * @sbmlbrief{copy} TODO:Definition of the Abc class.
 */


#ifndef Abc_H__
#define Abc_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/copy/common/copyfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/copy/extension/CopyExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Abc : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mLetter;

  /** @endcond */

public:

  /**
   * Creates a new Abc using the given SBML Level, Version and
   * &ldquo;copy&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Abc.
   *
   * @param version an unsigned int, the SBML Version to assign to this Abc.
   *
   * @param pkgVersion an unsigned int, the SBML Copy Version to assign to this
   * Abc.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Abc(unsigned int level = CopyExtension::getDefaultLevel(),
      unsigned int version = CopyExtension::getDefaultVersion(),
      unsigned int pkgVersion = CopyExtension::getDefaultPackageVersion());


  /**
   * Creates a new Abc using the given CopyPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param copyns the CopyPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Abc(CopyPkgNamespaces *copyns);


  /**
   * Copy constructor for Abc.
   *
   * @param orig the Abc instance to copy.
   */
  Abc(const Abc& orig);


  /**
   * Assignment operator for Abc.
   *
   * @param rhs the Abc object whose values are to be used as the basis of the
   * assignment.
   */
  Abc& operator=(const Abc& rhs);


  /**
   * Creates and returns a deep copy of this Abc object.
   *
   * @return a (deep) copy of this Abc object.
   */
  virtual Abc* clone() const;


  /**
   * Destructor for Abc.
   */
  virtual ~Abc();


  /**
   * Returns the value of the "letter" attribute of this Abc.
   *
   * @return the value of the "letter" attribute of this Abc as a string.
   */
  const std::string& getLetter() const;


  /**
   * Predicate returning @c true if this Abc's "letter" attribute is set.
   *
   * @return @c true if this Abc's "letter" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetLetter() const;


  /**
   * Sets the value of the "letter" attribute of this Abc.
   *
   * @param letter std::string& value of the "letter" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p letter = @c NULL or an empty string is
   * equivalent to calling unsetLetter().
   */
  int setLetter(const std::string& letter);


  /**
   * Unsets the value of the "letter" attribute of this Abc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLetter();


  /**
   * Returns the XML element name of this Abc object.
   *
   * For Abc, the XML element name is always @c "abc".
   *
   * @return the name of this element, i.e. @c "abc".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Abc object.
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
   * Predicate returning @c true if all the required attributes for this Abc
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Abc
   * have been set, otherwise @c false is returned.
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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Abc.
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
   * Gets the value of the "attributeName" attribute of this Abc.
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
   * Gets the value of the "attributeName" attribute of this Abc.
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
   * Gets the value of the "attributeName" attribute of this Abc.
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
   * Gets the value of the "attributeName" attribute of this Abc.
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
   * Gets the value of the "attributeName" attribute of this Abc.
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
   * Predicate returning @c true if this Abc's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Abc's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Abc.
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
   * Sets the value of the "attributeName" attribute of this Abc.
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
   * Sets the value of the "attributeName" attribute of this Abc.
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
   * Sets the value of the "attributeName" attribute of this Abc.
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
   * Sets the value of the "attributeName" attribute of this Abc.
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
   * Sets the value of the "attributeName" attribute of this Abc.
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
   * Unsets the value of the "attributeName" attribute of this Abc.
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
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


public:

  /**
   * For nested groups (Member objects that reference a ListOfMembers 
   * object), SBO terms, Notes, and Annotation from the
   * parent ListOfMembers applies to the child.  This function
   * copies any information from any of those three things to all 
   * child ListOfMembers, and if that information is not already 
   * set.  After calling
   * this function, it is sufficient to check any ListOfMembers
   * to see if its SBO term, Notes, or Annotation is set, without
   * further checking to see if that element was nested in another
   * Group.
   */
  virtual void copyInformationToNestedLists();


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Abc_t using the given SBML Level, Version and
 * &ldquo;copy&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Abc_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Abc_t.
 *
 * @param pkgVersion an unsigned int, the SBML Copy Version to assign to this
 * Abc_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
Abc_t *
Abc_create(unsigned int level, unsigned int version, unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Abc_t object.
 *
 * @param a the Abc_t structure.
 *
 * @return a (deep) copy of this Abc_t object.
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
Abc_t*
Abc_clone(const Abc_t* a);


/**
 * Frees this Abc_t object.
 *
 * @param a the Abc_t structure.
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
void
Abc_free(Abc_t* a);


/**
 * Returns the value of the "letter" attribute of this Abc_t.
 *
 * @param a the Abc_t structure whose letter is sought.
 *
 * @return the value of the "letter" attribute of this Abc_t as a pointer to a
 * string.
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
const char *
Abc_getLetter(const Abc_t * a);


/**
 * Predicate returning @c 1 (true) if this Abc_t's "letter" attribute is set.
 *
 * @param a the Abc_t structure.
 *
 * @return @c 1 (true) if this Abc_t's "letter" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
int
Abc_isSetLetter(const Abc_t * a);


/**
 * Sets the value of the "letter" attribute of this Abc_t.
 *
 * @param a the Abc_t structure.
 *
 * @param letter const char * value of the "letter" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p letter = @c NULL or an empty string is
 * equivalent to calling Abc_unsetLetter().
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
int
Abc_setLetter(Abc_t * a, const char * letter);


/**
 * Unsets the value of the "letter" attribute of this Abc_t.
 *
 * @param a the Abc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
int
Abc_unsetLetter(Abc_t * a);


/**
 * Predicate returning @c 1 if all the required attributes for this Abc_t
 * object have been set.
 *
 * @param a the Abc_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this Abc_t have
 * been set, otherwise @c 0 is returned.
 *
 * @memberof Abc_t
 */
LIBSBML_EXTERN
int
Abc_hasRequiredAttributes(const Abc_t * a);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Abc_H__ */


