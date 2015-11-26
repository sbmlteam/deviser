/**
 * @file FbcAnd.h
 * @brief Definition of the FbcAnd class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
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
 * @class FbcAnd
 * @sbmlbrief{fbc} TODO:Definition of the FbcAnd class.
 */


#ifndef FbcAnd_H__
#define FbcAnd_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/fbc/common/fbcfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/fbc/sbml/Association.h>
#include <sbml/packages/fbc/extension/FbcExtension.h>
#include <sbml/packages/fbc/sbml/ListOfAssociations.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN FbcAnd : public Association
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfAssociations mAssociations;

  /** @endcond */

public:

  /**
   * Creates a new FbcAnd using the given SBML Level, Version and
   * &ldquo;fbc&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this FbcAnd
   *
   * @param version an unsigned int, the SBML Version to assign to this FbcAnd
   *
   * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
   * FbcAnd
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  FbcAnd(unsigned int level = FbcExtension::getDefaultLevel(),
         unsigned int version = FbcExtension::getDefaultVersion(),
         unsigned int pkgVersion = FbcExtension::getDefaultPackageVersion());


  /**
   * Creates a new FbcAnd using the given FbcPkgNamespaces object.
   *
   * @param fbcns the FbcPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  FbcAnd(FbcPkgNamespaces *fbcns);


  /**
   * Copy constructor for FbcAnd.
   *
   * @param orig; the FbcAnd instance to copy.
   */
  FbcAnd(const FbcAnd& orig);


  /**
   * Assignment operator for FbcAnd.
   *
   * @param rhs; the FbcAnd object whose values are to be used as the basis of
   * the assignment
   */
  FbcAnd& operator=(const FbcAnd& rhs);


  /**
   * Creates and returns a deep copy of this FbcAnd object.
   *
   * @return a (deep) copy of this FbcAnd object.
   */
  virtual FbcAnd* clone() const;


  /**
   * Destructor for FbcAnd.
   */
  virtual ~FbcAnd();


  /**
   * Returns the ListOfAssociations from this FbcAnd.
   *
   * @return the ListOfAssociations from this FbcAnd.
   */
  const ListOfAssociations* getListOfAssociations() const;


  /**
   * Returns the ListOfAssociations from this FbcAnd.
   *
   * @return the ListOfAssociations from this FbcAnd.
   */
  ListOfAssociations* getListOfAssociations();


  /**
   * Get an Association from the FbcAnd.
   *
   * @param n, an unsigned int representing the index of the Association to
   * retrieve.
   *
   * @return the nth Association in the ListOfAssociations within this FbcAnd.
   *
   * @see getNumAssociations()
   */
  Association* getAssociation(unsigned int n);


  /**
   * Get an Association from the FbcAnd.
   *
   * @param n, an unsigned int representing the index of the Association to
   * retrieve.
   *
   * @return the nth Association in the ListOfAssociations within this FbcAnd.
   *
   * @see getNumAssociations()
   */
  const Association* getAssociation(unsigned int n) const;


  /**
   * Adds a copy of the given Association to this FbcAnd.
   *
   * @param a, the Association object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createAssociation()
   */
  int addAssociation(const Association* a);


  /**
   * Get the number of Association objects in this FbcAnd.
   *
   * @return the number of Association objects in this FbcAnd.
   */
  unsigned int getNumAssociations() const;


  /**
   * Creates a new FbcAnd object, adds it to this FbcAnd object and returns the
   * FbcAnd object created.
   *
   * @return a new FbcAnd object instance.
   *
   * @see addAssociation(const Association* a)
   */
  FbcAnd* createAnd();


  /**
   * Creates a new FbcOr object, adds it to this FbcAnd object and returns the
   * FbcOr object created.
   *
   * @return a new FbcOr object instance.
   *
   * @see addAssociation(const Association* a)
   */
  FbcOr* createOr();


  /**
   * Creates a new GeneProductRef object, adds it to this FbcAnd object and
   * returns the GeneProductRef object created.
   *
   * @return a new GeneProductRef object instance.
   *
   * @see addAssociation(const Association* a)
   */
  GeneProductRef* createGeneProductRef();


  /**
   * Removes the nth Association from this FbcAnd and returns a pointer to it.
   *
   * @param n, an unsigned int representing the index of the Association to
   * remove.
   *
   * @return a pointer to the nth Association in this FbcAnd.
   *
   * @see getNumAssociations
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Association* removeAssociation(unsigned int n);


  /**
   * Returns the XML element name of this FbcAnd object.
   *
   * For FbcAnd, the XML element name is always @c "and".
   *
   * @return the name of this element, i.e. @c "and".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this FbcAnd object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_FBC_AND, SBMLFbcTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this FbcAnd
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * FbcAnd have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the FbcAnd object are:
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this FbcAnd
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this FbcAnd
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the FbcAnd object are:
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
 * Creates a new FbcAnd_t using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this FbcAnd_t
 *
 * @param version an unsigned int, the SBML Version to assign to this FbcAnd_t
 *
 * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
 * FbcAnd_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
FbcAnd_t *
FbcAnd_create(unsigned int level = FbcExtension::getDefaultLevel(),
              unsigned int version = FbcExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                FbcExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this FbcAnd_t object.
 *
 * @param fa; the FbcAnd_t structure
 *
 * @return a (deep) copy of this FbcAnd_t object.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
FbcAnd_t*
FbcAnd_clone(const FbcAnd_t* fa);


/**
 * Frees this FbcAnd_t object.
 *
 * @param fa; the FbcAnd_t structure
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
void
FbcAnd_free(FbcAnd_t* fa);


/**
 * Returns a ListOf_t* containing Association_t objects from this FbcAnd_t.
 *
 * @param fa the FbcAnd_t structure whose "ListOfAssociations" is sought.
 *
 * @return the "ListOfAssociations" from this FbcAnd_t as a ListOf_t *.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
ListOf_t*
FbcAnd_getListOfAssociations(FbcAnd_t* fa);


/**
 * Get an Association_t from the FbcAnd_t.
 *
 * @param fa, the FbcAnd_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Association_t to
 * retrieve.
 *
 * @return the nth Association_t in the ListOfAssociations within this FbcAnd.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
const Association_t*
FbcAnd_getAssociation(FbcAnd_t* fa, unsigned int n);


/**
 * Adds a copy of the given Association_t to this FbcAnd_t.
 *
 * @param fa, the FbcAnd_t structure to which the Association_t should be
 * added.
 *
 * @param a, the Association_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
int
FbcAnd_addAssociation(FbcAnd_t* fa, const Association_t* a);


/**
 * Get the number of Association_t objects in this FbcAnd_t.
 *
 * @param fa, the FbcAnd_t structure to query.
 *
 * @return the number of Association_t objects in this FbcAnd_t.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
unsigned int
FbcAnd_getNumAssociations(FbcAnd_t* fa);


/**
 * Creates a new FbcAnd_t object, adds it to this FbcAnd_t object and returns
 * the FbcAnd_t object created.
 *
 * @param fa, the FbcAnd_t structure to which the FbcAnd_t should be added.
 *
 * @return a new FbcAnd_t object instance.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
FbcAnd_t*
FbcAnd_createAnd(FbcAnd_t* fa);


/**
 * Creates a new FbcOr_t object, adds it to this FbcAnd_t object and returns
 * the FbcOr_t object created.
 *
 * @param fa, the FbcAnd_t structure to which the FbcOr_t should be added.
 *
 * @return a new FbcOr_t object instance.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
FbcOr_t*
FbcAnd_createOr(FbcAnd_t* fa);


/**
 * Creates a new GeneProductRef_t object, adds it to this FbcAnd_t object and
 * returns the GeneProductRef_t object created.
 *
 * @param fa, the FbcAnd_t structure to which the GeneProductRef_t should be
 * added.
 *
 * @return a new GeneProductRef_t object instance.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
GeneProductRef_t*
FbcAnd_createGeneProductRef(FbcAnd_t* fa);


/**
 * Removes the nth Association_t from this FbcAnd_t and returns a pointer to
 * it.
 *
 * @param fa, the FbcAnd_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Association_t to
 * remove.
 *
 * @return a pointer to the nth Association_t in this FbcAnd_t.
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
Association_t*
FbcAnd_removeAssociation(FbcAnd_t* fa, unsigned int n);


/**
 * Predicate returning @c 1 if all the required attributes for this FbcAnd_t
 * object have been set.
 *
 * @param fa the FbcAnd_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this FbcAnd_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the FbcAnd_t object are:
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
int
FbcAnd_hasRequiredAttributes(const FbcAnd_t * fa);


/**
 * Predicate returning @c 1 if all the required elements for this FbcAnd_t
 * object have been set.
 *
 * @param fa the FbcAnd_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this FbcAnd_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the FbcAnd_t object are:
 *
 * @memberof FbcAnd_t
 */
LIBSBML_EXTERN
int
FbcAnd_hasRequiredElements(const FbcAnd_t * fa);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !FbcAnd_H__ */


