/**
 * @file TSBListOfComments.h
 * @brief Definition of the TSBListOfComments class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
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
 * @class TSBListOfComments
 * @sbmlbrief{tsb} TODO:Definition of the TSBListOfComments class.
 */


#ifndef TSBListOfComments_H__
#define TSBListOfComments_H__


#include <tsb/common/extern.h>
#include <tsb/common/tsbfwd.h>


#ifdef __cplusplus


#include <string>


#include <tsb/TSBListOf.h>
#include <tsb/TSBComment.h>


LIBTSB_CPP_NAMESPACE_BEGIN


class LIBTSB_EXTERN TSBListOfComments : public TSBListOf
{

public:

  /**
   * Creates a new TSBListOfComments using the given TSB Level and @ p version
   * values.
   *
   * @param level an unsigned int, the TSB Level to assign to this
   * TSBListOfComments.
   *
   * @param version an unsigned int, the TSB Version to assign to this
   * TSBListOfComments.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  TSBListOfComments(unsigned int level = TSB_DEFAULT_LEVEL,
                    unsigned int version = TSB_DEFAULT_VERSION);


  /**
   * Creates a new TSBListOfComments using the given TSBNamespaces object @p
   * tsbns.
   *
   * @param tsbns the TSBNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  TSBListOfComments(TSBNamespaces *tsbns);


  /**
   * Copy constructor for TSBListOfComments.
   *
   * @param orig the TSBListOfComments instance to copy.
   */
  TSBListOfComments(const TSBListOfComments& orig);


  /**
   * Assignment operator for TSBListOfComments.
   *
   * @param rhs the TSBListOfComments object whose values are to be used as the
   * basis of the assignment.
   */
  TSBListOfComments& operator=(const TSBListOfComments& rhs);


  /**
   * Creates and returns a deep copy of this TSBListOfComments object.
   *
   * @return a (deep) copy of this TSBListOfComments object.
   */
  virtual TSBListOfComments* clone() const;


  /**
   * Destructor for TSBListOfComments.
   */
  virtual ~TSBListOfComments();


  /**
   * Get a TSBComment from the TSBListOfComments.
   *
   * @param n an unsigned int representing the index of the TSBComment to
   * retrieve.
   *
   * @return the nth TSBComment in this TSBListOfComments or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(const std::string& sid)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual TSBComment* get(unsigned int n);


  /**
   * Get a TSBComment from the TSBListOfComments.
   *
   * @param n an unsigned int representing the index of the TSBComment to
   * retrieve.
   *
   * @return the nth TSBComment in this TSBListOfComments or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(const std::string& sid)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const TSBComment* get(unsigned int n) const;


  /**
   * Get a TSBComment from the TSBListOfComments based on its identifier.
   *
   * @param sid a string representing the identifier of the TSBComment to
   * retrieve.
   *
   * @return the TSBComment in this TSBListOfComments with the given @p sid or
   * @c NULL if no such TSBComment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(unsigned int n)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual TSBComment* get(const std::string& sid);


  /**
   * Get a TSBComment from the TSBListOfComments based on its identifier.
   *
   * @param sid a string representing the identifier of the TSBComment to
   * retrieve.
   *
   * @return the TSBComment in this TSBListOfComments with the given @p sid or
   * @c NULL if no such TSBComment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(unsigned int n)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const TSBComment* get(const std::string& sid) const;


  /**
   * Removes the nth TSBComment from this TSBListOfComments and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the TSBComment to
   * remove.
   *
   * @return a pointer to the nth TSBComment in this TSBListOfComments.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   */
  virtual TSBComment* remove(unsigned int n);


  /**
   * Removes the TSBComment from this TSBListOfComments based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the TSBComment to
   * remove.
   *
   * @return the TSBComment in this TSBListOfComments based on the identifier
   * or NULL if no such TSBComment exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumComments()
   * @see remove(unsigned int n)
   */
  virtual TSBComment* remove(const std::string& sid);


  /**
   * Adds a copy of the given TSBComment to this TSBListOfComments.
   *
   * @param tsbc the TSBComment object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createComment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addComment(const TSBComment* tsbc);


  /**
   * Get the number of TSBComment objects in this TSBListOfComments.
   *
   * @return the number of TSBComment objects in this TSBListOfComments.
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumComments() const;


  /**
   * Creates a new TSBComment object, adds it to this TSBListOfComments object
   * and returns the TSBComment object created.
   *
   * @return a new TSBComment object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumComments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  TSBComment* createComment();


  /**
   * Returns the XML element name of this TSBListOfComments object.
   *
   * For TSBListOfComments, the XML element name is always @c "listOfComments".
   *
   * @return the name of this element, i.e. @c "listOfComments".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libTSB type code for this TSBListOfComments object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the TSB type code for this object:
   * @tsbconstant{TSB_LIST_OF, TSBTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libTSB type code for the TSB objects contained in this
   * TSBListOfComments object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the TSB typecode for the objects contained in this
   * TSBListOfComments:
   * @tsbconstant{TSB_COMMENT, TSBTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenlibTSBInternal */

  /**
   * Creates a new TSBComment in this TSBListOfComments
   */
  virtual TSBBase* createObject(XMLInputStream& stream);

  /** @endcond */


};



LIBTSB_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBTSB_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a TSBComment_t from the TSBListOf_t.
 *
 * @param tsblo the TSBListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the TSBComment_t to
 * retrieve.
 *
 * @return the nth TSBComment_t in this TSBListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof TSBListOfComments_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_getComment(TSBListOf_t* tsblo, unsigned int n);


/**
 * Get a TSBComment_t from the TSBListOf_t based on its identifier.
 *
 * @param tsblo the TSBListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the TSBComment_t to
 * retrieve.
 *
 * @return the TSBComment_t in this TSBListOf_t with the given @p sid or
 * @c NULL if no such TSBComment_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof TSBListOfComments_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_getById(TSBListOf_t* tsblo, const char *sid);


/**
 * Removes the nth TSBComment_t from this TSBListOf_t and returns a pointer to
 * it.
 *
 * @param tsblo the TSBListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the TSBComment_t to
 * remove.
 *
 * @return a pointer to the nth TSBComment_t in this TSBListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof TSBListOfComments_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_remove(TSBListOf_t* tsblo, unsigned int n);


/**
 * Removes the TSBComment_t from this TSBListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param tsblo the TSBListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the TSBComment_t to
 * remove.
 *
 * @return the TSBComment_t in this TSBListOf_t based on the identifier or NULL
 * if no such TSBComment_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof TSBListOfComments_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_removeById(TSBListOf_t* tsblo, const char* sid);




END_C_DECLS




LIBTSB_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !TSBListOfComments_H__ */


