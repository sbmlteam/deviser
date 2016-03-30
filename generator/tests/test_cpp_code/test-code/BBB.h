/**
 * @file BBB.h
 * @brief Definition of the BBB class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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
 * @class BBB
 * @sbmlbrief{vers} TODO:Definition of the BBB class.
 */


#ifndef BBB_H__
#define BBB_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/vers/common/versfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/vers/extension/VersExtension.h>
#include <sbml/packages/vers/sbml/ListOfAnothers.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN BBB : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  ListOfAnothers mAnothers;

  /** @endcond */

public:

  /**
   * Creates a new BBB using the given SBML Level, Version and
   * &ldquo;vers&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this BBB
   *
   * @param version an unsigned int, the SBML Version to assign to this BBB
   *
   * @param pkgVersion an unsigned int, the SBML Vers Version to assign to this
   * BBB
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  BBB(unsigned int level = VersExtension::getDefaultLevel(),
      unsigned int version = VersExtension::getDefaultVersion(),
      unsigned int pkgVersion = VersExtension::getDefaultPackageVersion());


  /**
   * Creates a new BBB using the given VersPkgNamespaces object.
   *
   * @param versns the VersPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  BBB(VersPkgNamespaces *versns);


  /**
   * Copy constructor for BBB.
   *
   * @param orig; the BBB instance to copy.
   */
  BBB(const BBB& orig);


  /**
   * Assignment operator for BBB.
   *
   * @param rhs; the BBB object whose values are to be used as the basis of the
   * assignment
   */
  BBB& operator=(const BBB& rhs);


  /**
   * Creates and returns a deep copy of this BBB object.
   *
   * @return a (deep) copy of this BBB object.
   */
  virtual BBB* clone() const;


  /**
   * Destructor for BBB.
   */
  virtual ~BBB();


  /**
   * Returns the value of the "id" attribute of this BBB.
   *
   * @return the value of the "id" attribute of this BBB as a string.
   */
  const std::string& getId() const;


  /**
   * Predicate returning @c true if this BBB's "id" attribute is set.
   *
   * @return @c true if this BBB's "id" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this BBB.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Unsets the value of the "id" attribute of this BBB.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Returns the ListOfAnothers from this BBB.
   *
   * @return the ListOfAnothers from this BBB.
   */
  const ListOfAnothers* getListOfAnothers() const;


  /**
   * Returns the ListOfAnothers from this BBB.
   *
   * @return the ListOfAnothers from this BBB.
   */
  ListOfAnothers* getListOfAnothers();


  /**
   * Get an Another from the BBB.
   *
   * @param n, an unsigned int representing the index of the Another to
   * retrieve.
   *
   * @return the nth Another in the ListOfAnothers within this BBB.
   *
   * @see getNumAnothers()
   */
  Another* getAnother(unsigned int n);


  /**
   * Get an Another from the BBB.
   *
   * @param n, an unsigned int representing the index of the Another to
   * retrieve.
   *
   * @return the nth Another in the ListOfAnothers within this BBB.
   *
   * @see getNumAnothers()
   */
  const Another* getAnother(unsigned int n) const;


  /**
   * Get an Another from the BBB based on its identifier.
   *
   * @param sid a string representing the identifier of the Another to
   * retrieve.
   *
   * @return the Another in the ListOfAnothers within this BBB with the given
   * id or NULL if no such Another exists.
   *
   * @see getAnother(unsigned int n)
   * @see getNumAnothers()
   */
  Another* getAnother(const std::string& sid);


  /**
   * Get an Another from the BBB based on its identifier.
   *
   * @param sid a string representing the identifier of the Another to
   * retrieve.
   *
   * @return the Another in the ListOfAnothers within this BBB with the given
   * id or NULL if no such Another exists.
   *
   * @see getAnother(unsigned int n)
   * @see getNumAnothers()
   */
  const Another* getAnother(const std::string& sid) const;


  /**
   * Adds a copy of the given Another to this BBB.
   *
   * @param a, the Another object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createAnother()
   */
  int addAnother(const Another* a);


  /**
   * Get the number of Another objects in this BBB.
   *
   * @return the number of Another objects in this BBB.
   */
  unsigned int getNumAnothers() const;


  /**
   * Creates a new Another object, adds it to this BBB object and returns the
   * Another object created.
   *
   * @return a new Another object instance.
   *
   * @see addAnother(const Another* a)
   */
  Another* createAnother();


  /**
   * Removes the nth Another from this BBB and returns a pointer to it.
   *
   * @param n, an unsigned int representing the index of the Another to remove.
   *
   * @return a pointer to the nth Another in this BBB.
   *
   * @see getNumAnothers
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Another* removeAnother(unsigned int n);


  /**
   * Removes the Another from this BBB based on its identifier and returns a
   * pointer to it.
   *
   * @param sid, a string representing the identifier of the Another to remove.
   *
   * @return the Another in this BBB based on the identifier or NULL if no such
   * Another exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Another* removeAnother(const std::string& sid);


  /**
   * Returns the XML element name of this BBB object.
   *
   * For BBB, the XML element name is always @c "bBB".
   *
   * @return the name of this element, i.e. @c "bBB".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this BBB object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{CLASS_B, SBMLVersTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this BBB
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this BBB
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the BBB object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this BBB
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this BBB
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the BBB object are:
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


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * filter, an ElementFilter that may impose restrictions on the objects to be
   * retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



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
   * Reads the expected attributes into the member data variables
   */
  virtual void readV1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readV2Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeV1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeV2Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new BBB_t using the given SBML Level, Version and
 * &ldquo;vers&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this BBB_t
 *
 * @param version an unsigned int, the SBML Version to assign to this BBB_t
 *
 * @param pkgVersion an unsigned int, the SBML Vers Version to assign to this
 * BBB_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
BBB_t *
BBB_create(unsigned int level = VersExtension::getDefaultLevel(),
           unsigned int version = VersExtension::getDefaultVersion(),
           unsigned int pkgVersion =
             VersExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this BBB_t object.
 *
 * @param bbb; the BBB_t structure
 *
 * @return a (deep) copy of this BBB_t object.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
BBB_t*
BBB_clone(const BBB_t* bbb);


/**
 * Frees this BBB_t object.
 *
 * @param bbb; the BBB_t structure
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
void
BBB_free(BBB_t* bbb);


/**
 * Returns the value of the "id" attribute of this BBB_t.
 *
 * @param bbb the BBB_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this BBB_t as a pointer to a
 * string.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
const char *
BBB_getId(const BBB_t * bbb);


/**
 * Predicate returning @c 1 if this BBB_t's "id" attribute is set.
 *
 * @param bbb the BBB_t structure.
 *
 * @return @c 1 if this BBB_t's "id" attribute has been set, otherwise @c 0 is
 * returned.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
int
BBB_isSetId(const BBB_t * bbb);


/**
 * Sets the value of the "id" attribute of this BBB_t.
 *
 * @param bbb the BBB_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
int
BBB_setId(BBB_t * bbb, const char * id);


/**
 * Unsets the value of the "id" attribute of this BBB_t.
 *
 * @param bbb the BBB_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
int
BBB_unsetId(BBB_t * bbb);


/**
 * Returns a ListOf_t* containing Another_t objects from this BBB_t.
 *
 * @param bbb the BBB_t structure whose "ListOfAnothers" is sought.
 *
 * @return the "ListOfAnothers" from this BBB_t as a ListOf_t *.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
ListOf_t*
BBB_getListOfAnothers(BBB_t* bbb);


/**
 * Get an Another_t from the BBB_t.
 *
 * @param bbb, the BBB_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Another_t to
 * retrieve.
 *
 * @return the nth Another_t in the ListOfAnothers within this BBB.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
const Another_t*
BBB_getAnother(BBB_t* bbb, unsigned int n);


/**
 * Get an Another_t from the BBB_t based on its identifier.
 *
 * @param bbb, the BBB_t structure to search.
 *
 * @param sid a string representing the identifier of the Another_t to
 * retrieve.
 *
 * @return the Another_t in the ListOfAnothers within this BBB with the given
 * id or NULL if no such Another_t exists.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
const Another_t*
BBB_getAnotherById(BBB_t* bbb, const char *sid);


/**
 * Adds a copy of the given Another_t to this BBB_t.
 *
 * @param bbb, the BBB_t structure to which the Another_t should be added.
 *
 * @param a, the Another_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
int
BBB_addAnother(BBB_t* bbb, const Another_t* a);


/**
 * Get the number of Another_t objects in this BBB_t.
 *
 * @param bbb, the BBB_t structure to query.
 *
 * @return the number of Another_t objects in this BBB_t.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
unsigned int
BBB_getNumAnothers(BBB_t* bbb);


/**
 * Creates a new Another_t object, adds it to this BBB_t object and returns the
 * Another_t object created.
 *
 * @param bbb, the BBB_t structure to which the Another_t should be added.
 *
 * @return a new Another_t object instance.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
Another_t*
BBB_createAnother(BBB_t* bbb);


/**
 * Removes the nth Another_t from this BBB_t and returns a pointer to it.
 *
 * @param bbb, the BBB_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Another_t to remove.
 *
 * @return a pointer to the nth Another_t in this BBB_t.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
Another_t*
BBB_removeAnother(BBB_t* bbb, unsigned int n);


/**
 * Removes the Another_t from this BBB_t based on its identifier and returns a
 * pointer to it.
 *
 * @param bbb, the BBB_t structure to search.
 *
 * @param sid, a string representing the identifier of the Another_t to remove.
 *
 * @return the Another_t in this BBB_t based on the identifier or NULL if no
 * such Another_t exists.
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
Another_t*
BBB_removeAnotherById(BBB_t* bbb, const char* sid);


/**
 * Predicate returning @c 1 if all the required attributes for this BBB_t
 * object have been set.
 *
 * @param bbb the BBB_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this BBB_t have
 * been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the BBB_t object are:
 * @li "id"
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
int
BBB_hasRequiredAttributes(const BBB_t * bbb);


/**
 * Predicate returning @c 1 if all the required elements for this BBB_t object
 * have been set.
 *
 * @param bbb the BBB_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this BBB_t have
 * been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the BBB_t object are:
 *
 * @memberof BBB_t
 */
LIBSBML_EXTERN
int
BBB_hasRequiredElements(const BBB_t * bbb);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !BBB_H__ */


