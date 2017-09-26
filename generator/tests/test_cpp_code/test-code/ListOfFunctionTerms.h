/**
 * @file ListOfFunctionTerms.h
 * @brief Definition of the ListOfFunctionTerms class.
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
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class ListOfFunctionTerms
 * @sbmlbrief{qual} TODO:Definition of the ListOfFunctionTerms class.
 */


#ifndef ListOfFunctionTerms_H__
#define ListOfFunctionTerms_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/qual/extension/QualExtension.h>
#include <sbml/packages/qual/sbml/DefaultTerm.h>
#include <sbml/packages/qual/sbml/FunctionTerm.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfFunctionTerms : public ListOf
{
protected:

  /** @cond doxygenLibsbmlInternal */

  DefaultTerm* mDefaultTerm;

  /** @endcond */

public:

  /**
   * Creates a new ListOfFunctionTerms using the given SBML Level, Version and
   * &ldquo;qual&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfFunctionTerms.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfFunctionTerms.
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
   * ListOfFunctionTerms.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfFunctionTerms(unsigned int level = QualExtension::getDefaultLevel(),
                      unsigned int version =
                        QualExtension::getDefaultVersion(),
                      unsigned int pkgVersion =
                        QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfFunctionTerms using the given QualPkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param qualns the QualPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfFunctionTerms(QualPkgNamespaces *qualns);


  /**
   * Copy constructor for ListOfFunctionTerms.
   *
   * @param orig the ListOfFunctionTerms instance to copy.
   */
  ListOfFunctionTerms(const ListOfFunctionTerms& orig);


  /**
   * Assignment operator for ListOfFunctionTerms.
   *
   * @param rhs the ListOfFunctionTerms object whose values are to be used as
   * the basis of the assignment.
   */
  ListOfFunctionTerms& operator=(const ListOfFunctionTerms& rhs);


  /**
   * Creates and returns a deep copy of this ListOfFunctionTerms object.
   *
   * @return a (deep) copy of this ListOfFunctionTerms object.
   */
  virtual ListOfFunctionTerms* clone() const;


  /**
   * Destructor for ListOfFunctionTerms.
   */
  virtual ~ListOfFunctionTerms();


  /**
   * Returns the value of the "defaultTerm" element of this
   * ListOfFunctionTerms.
   *
   * @return the value of the "defaultTerm" element of this ListOfFunctionTerms
   * as a DefaultTerm*.
   */
  const DefaultTerm* getDefaultTerm() const;


  /**
   * Returns the value of the "defaultTerm" element of this
   * ListOfFunctionTerms.
   *
   * @return the value of the "defaultTerm" element of this ListOfFunctionTerms
   * as a DefaultTerm*.
   */
  DefaultTerm* getDefaultTerm();


  /**
   * Predicate returning @c true if this ListOfFunctionTerms's "defaultTerm"
   * element is set.
   *
   * @return @c true if this ListOfFunctionTerms's "defaultTerm" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetDefaultTerm() const;


  /**
   * Sets the value of the "defaultTerm" element of this ListOfFunctionTerms.
   *
   * @param defaultTerm DefaultTerm* value of the "defaultTerm" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDefaultTerm(const DefaultTerm* defaultTerm);


  /**
   * Creates a new DefaultTerm object, adds it to this ListOfFunctionTerms
   * object and returns the DefaultTerm object created.
   *
   * @return a new DefaultTerm object instance.
   */
  DefaultTerm* createDefaultTerm();


  /**
   * Unsets the value of the "defaultTerm" element of this ListOfFunctionTerms.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDefaultTerm();


  /**
   * Get a FunctionTerm from the ListOfFunctionTerms.
   *
   * @param n an unsigned int representing the index of the FunctionTerm to
   * retrieve.
   *
   * @return the nth FunctionTerm in this ListOfFunctionTerms.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(const std::string& sid)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual FunctionTerm* get(unsigned int n);


  /**
   * Get a FunctionTerm from the ListOfFunctionTerms.
   *
   * @param n an unsigned int representing the index of the FunctionTerm to
   * retrieve.
   *
   * @return the nth FunctionTerm in this ListOfFunctionTerms.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(const std::string& sid)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const FunctionTerm* get(unsigned int n) const;


  /**
   * Get a FunctionTerm from the ListOfFunctionTerms based on its identifier.
   *
   * @param sid a string representing the identifier of the FunctionTerm to
   * retrieve.
   *
   * @return the FunctionTerm in this ListOfFunctionTerms with the given id or
   * NULL if no such FunctionTerm exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(unsigned int n)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual FunctionTerm* get(const std::string& sid);


  /**
   * Get a FunctionTerm from the ListOfFunctionTerms based on its identifier.
   *
   * @param sid a string representing the identifier of the FunctionTerm to
   * retrieve.
   *
   * @return the FunctionTerm in this ListOfFunctionTerms with the given id or
   * NULL if no such FunctionTerm exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(unsigned int n)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const FunctionTerm* get(const std::string& sid) const;


  /**
   * Removes the nth FunctionTerm from this ListOfFunctionTerms and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the FunctionTerm to
   * remove.
   *
   * @return a pointer to the nth FunctionTerm in this ListOfFunctionTerms.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   */
  virtual FunctionTerm* remove(unsigned int n);


  /**
   * Removes the FunctionTerm from this ListOfFunctionTerms based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the FunctionTerm to
   * remove.
   *
   * @return the FunctionTerm in this ListOfFunctionTerms based on the
   * identifier or NULL if no such FunctionTerm exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFunctionTerms()
   * @see remove(unsigned int n)
   */
  virtual FunctionTerm* remove(const std::string& sid);


  /**
   * Adds a copy of the given FunctionTerm to this ListOfFunctionTerms.
   *
   * @param ft the FunctionTerm object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createFunctionTerm()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addFunctionTerm(const FunctionTerm* ft);


  /**
   * Get the number of FunctionTerm objects in this ListOfFunctionTerms.
   *
   * @return the number of FunctionTerm objects in this ListOfFunctionTerms.
   *
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see createFunctionTerm()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumFunctionTerms() const;


  /**
   * Creates a new FunctionTerm object, adds it to this ListOfFunctionTerms
   * object and returns the FunctionTerm object created.
   *
   * @return a new FunctionTerm object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFunctionTerm(const FunctionTerm* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFunctionTerms()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  FunctionTerm* createFunctionTerm();


  /**
   * Returns the XML element name of this ListOfFunctionTerms object.
   *
   * For ListOfFunctionTerms, the XML element name is always @c
   * "listOfFunctionTerms".
   *
   * @return the name of this element, i.e. @c "listOfFunctionTerms".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ListOfFunctionTerms object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_LIST_OF, SBMLTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSBML type code for the SBML objects contained in this
   * ListOfFunctionTerms object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this
   * ListOfFunctionTerms:
   *
   * @sbmlconstant{SBML_QUAL_FUNCTION_TERM, SBMLQualTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * ListOfFunctionTerms object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * ListOfFunctionTerms have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the ListOfFunctionTerms object are:
   * @li "defaultTerm"
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
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid. If no
   * such object is found this method returns @c NULL.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter, an ElementFilter that may impose restrictions on the
   * objects to be retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new FunctionTerm in this ListOfFunctionTerms
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the namespace for the Qual package
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a FunctionTerm_t from the ListOf_t.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the FunctionTerm_t to
 * retrieve.
 *
 * @return the nth FunctionTerm_t in this ListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ListOfFunctionTerms_t
 */
LIBSBML_EXTERN
FunctionTerm_t*
ListOfFunctionTerms_getFunctionTerm(ListOf_t* lo, unsigned int n);


/**
 * Get a FunctionTerm_t from the ListOf_t based on its identifier.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the FunctionTerm_t to
 * retrieve.
 *
 * @return the FunctionTerm_t in this ListOf_t with the given id or NULL if no
 * such FunctionTerm_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ListOfFunctionTerms_t
 */
LIBSBML_EXTERN
FunctionTerm_t*
ListOfFunctionTerms_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth FunctionTerm_t from this ListOf_t and returns a pointer to
 * it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the FunctionTerm_t to
 * remove.
 *
 * @return a pointer to the nth FunctionTerm_t in this ListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ListOfFunctionTerms_t
 */
LIBSBML_EXTERN
FunctionTerm_t*
ListOfFunctionTerms_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the FunctionTerm_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the FunctionTerm_t to
 * remove.
 *
 * @return the FunctionTerm_t in this ListOf_t based on the identifier or NULL
 * if no such FunctionTerm_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ListOfFunctionTerms_t
 */
LIBSBML_EXTERN
FunctionTerm_t*
ListOfFunctionTerms_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfFunctionTerms_H__ */


