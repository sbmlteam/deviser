/**
 * @file ListOfObjectives.h
 * @brief Definition of the ListOfObjectives class.
 * @author SBMLTeam
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
 * @class ListOfObjectives
 * @sbmlbrief{fbc} TODO:Definition of the ListOfObjectives class.
 */


#ifndef ListOfObjectives_H__
#define ListOfObjectives_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/fbc/common/fbcfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/fbc/extension/FbcExtension.h>
#include <sbml/packages/fbc/sbml/Objective.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfObjectives : public ListOf
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mActiveObjective;

  /** @endcond */

public:

  /**
   * Creates a new ListOfObjectives using the given SBML Level, Version and
   * &ldquo;fbc&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfObjectives.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfObjectives.
   *
   * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
   * ListOfObjectives.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfObjectives(unsigned int level = FbcExtension::getDefaultLevel(),
                   unsigned int version = FbcExtension::getDefaultVersion(),
                   unsigned int pkgVersion =
                     FbcExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfObjectives using the given FbcPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param fbcns the FbcPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfObjectives(FbcPkgNamespaces *fbcns);


  /**
   * Copy constructor for ListOfObjectives.
   *
   * @param orig the ListOfObjectives instance to copy.
   */
  ListOfObjectives(const ListOfObjectives& orig);


  /**
   * Assignment operator for ListOfObjectives.
   *
   * @param rhs the ListOfObjectives object whose values are to be used as the
   * basis of the assignment.
   */
  ListOfObjectives& operator=(const ListOfObjectives& rhs);


  /**
   * Creates and returns a deep copy of this ListOfObjectives object.
   *
   * @return a (deep) copy of this ListOfObjectives object.
   */
  virtual ListOfObjectives* clone() const;


  /**
   * Destructor for ListOfObjectives.
   */
  virtual ~ListOfObjectives();


  /**
   * Returns the value of the "activeObjective" attribute of this
   * ListOfObjectives.
   *
   * @return the value of the "activeObjective" attribute of this
   * ListOfObjectives as a string.
   */
  const std::string& getActiveObjective() const;


  /**
   * Predicate returning @c true if this ListOfObjectives's "activeObjective"
   * attribute is set.
   *
   * @return @c true if this ListOfObjectives's "activeObjective" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetActiveObjective() const;


  /**
   * Sets the value of the "activeObjective" attribute of this
   * ListOfObjectives.
   *
   * @param activeObjective std::string& value of the "activeObjective"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setActiveObjective(const std::string& activeObjective);


  /**
   * Unsets the value of the "activeObjective" attribute of this
   * ListOfObjectives.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetActiveObjective();


  /**
   * Get an Objective from the ListOfObjectives.
   *
   * @param n an unsigned int representing the index of the Objective to
   * retrieve.
   *
   * @return the nth Objective in this ListOfObjectives or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(const std::string& sid)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual Objective* get(unsigned int n);


  /**
   * Get an Objective from the ListOfObjectives.
   *
   * @param n an unsigned int representing the index of the Objective to
   * retrieve.
   *
   * @return the nth Objective in this ListOfObjectives or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(const std::string& sid)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const Objective* get(unsigned int n) const;


  /**
   * Get an Objective from the ListOfObjectives based on its identifier.
   *
   * @param sid a string representing the identifier of the Objective to
   * retrieve.
   *
   * @return the Objective in this ListOfObjectives with the given @p sid or
   * @c NULL if no such Objective exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(unsigned int n)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual Objective* get(const std::string& sid);


  /**
   * Get an Objective from the ListOfObjectives based on its identifier.
   *
   * @param sid a string representing the identifier of the Objective to
   * retrieve.
   *
   * @return the Objective in this ListOfObjectives with the given @p sid or
   * @c NULL if no such Objective exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(unsigned int n)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const Objective* get(const std::string& sid) const;


  /**
   * Removes the nth Objective from this ListOfObjectives and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the Objective to
   * remove.
   *
   * @return a pointer to the nth Objective in this ListOfObjectives.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   */
  virtual Objective* remove(unsigned int n);


  /**
   * Removes the Objective from this ListOfObjectives based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the Objective to
   * remove.
   *
   * @return the Objective in this ListOfObjectives based on the identifier or
   * NULL if no such Objective exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumObjectives()
   * @see remove(unsigned int n)
   */
  virtual Objective* remove(const std::string& sid);


  /**
   * Adds a copy of the given Objective to this ListOfObjectives.
   *
   * @param o the Objective object to add.
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
   * @see createObjective()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addObjective(const Objective* o);


  /**
   * Get the number of Objective objects in this ListOfObjectives.
   *
   * @return the number of Objective objects in this ListOfObjectives.
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumObjectives() const;


  /**
   * Creates a new Objective object, adds it to this ListOfObjectives object
   * and returns the Objective object created.
   *
   * @return a new Objective object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumObjectives()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  Objective* createObjective();


  /**
   * Returns the XML element name of this ListOfObjectives object.
   *
   * For ListOfObjectives, the XML element name is always
   * @c "listOfObjectives".
   *
   * @return the name of this element, i.e. @c "listOfObjectives".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ListOfObjectives object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_LIST_OF, SBMLTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSBML type code for the SBML objects contained in this
   * ListOfObjectives object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this
   * ListOfObjectives:
   * @sbmlconstant{SBML_FBC_OBJECTIVE, SBMLFbcTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ListOfObjectives object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ListOfObjectives have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new Objective in this ListOfObjectives
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
  void readL3V1V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  void readL3V1V2Attributes(const XMLAttributes& attributes);

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
  void writeL3V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  void writeL3V1V2Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Returns the value of the "activeObjective" attribute of this ListOf_t.
 *
 * @param lo the ListOf_t structure whose activeObjective is sought.
 *
 * @return the value of the "activeObjective" attribute of this ListOf_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
char *
ListOfObjectives_getActiveObjective(const ListOf_t * lo);


/**
 * Predicate returning @c 1 (true) if this ListOf_t's "activeObjective"
 * attribute is set.
 *
 * @param lo the ListOf_t structure.
 *
 * @return @c 1 (true) if this ListOf_t's "activeObjective" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
int
ListOfObjectives_isSetActiveObjective(const ListOf_t * lo);


/**
 * Sets the value of the "activeObjective" attribute of this ListOf_t.
 *
 * @param lo the ListOf_t structure.
 *
 * @param activeObjective const char * value of the "activeObjective" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
int
ListOfObjectives_setActiveObjective(ListOf_t * lo,
                                    const char * activeObjective);


/**
 * Unsets the value of the "activeObjective" attribute of this ListOf_t.
 *
 * @param lo the ListOf_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
int
ListOfObjectives_unsetActiveObjective(ListOf_t * lo);


/**
 * Get an Objective_t from the ListOf_t.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the Objective_t to
 * retrieve.
 *
 * @return the nth Objective_t in this ListOf_t or @c NULL if no such object
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
Objective_t*
ListOfObjectives_getObjective(ListOf_t* lo, unsigned int n);


/**
 * Get an Objective_t from the ListOf_t based on its identifier.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the Objective_t to
 * retrieve.
 *
 * @return the Objective_t in this ListOf_t with the given @p sid or @c NULL if
 * no such Objective_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
Objective_t*
ListOfObjectives_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth Objective_t from this ListOf_t and returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the Objective_t to
 * remove.
 *
 * @return a pointer to the nth Objective_t in this ListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
Objective_t*
ListOfObjectives_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the Objective_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the Objective_t to
 * remove.
 *
 * @return the Objective_t in this ListOf_t based on the identifier or NULL if
 * no such Objective_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof ListOfObjectives_t
 */
LIBSBML_EXTERN
Objective_t*
ListOfObjectives_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfObjectives_H__ */


