/**
 * @file ListOfOutputs.h
 * @brief Definition of the ListOfOutputs class.
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
 */


#ifndef ListOfOutputs_H__
#define ListOfOutputs_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/qual/extension/QualExtension.h>
#include <sbml/packages/qual/sbml/Output.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfOutputs : public ListOf
{

public:

  /**
   * Creates a new ListOfOutputs using the given SBML Level, Version and
   * &ldquo;qual&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfOutputs
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfOutputs
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
   * ListOfOutputs
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ListOfOutputs(unsigned int level = QualExtension::getDefaultLevel(),
                unsigned int version = QualExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                  QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfOutputs using the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ListOfOutputs(QualPkgNamespaces *qualns);


  /**
   * Copy constructor for ListOfOutputs.
   *
   * @param orig; the ListOfOutputs instance to copy.
   */
  ListOfOutputs(const ListOfOutputs& orig);


  /**
   * Assignment operator for ListOfOutputs.
   *
   * @param rhs; the ListOfOutputs object whose values are to be used as the
   * basis of the assignment
   */
  ListOfOutputs& operator=(const ListOfOutputs& rhs);


  /**
   * Creates and returns a deep copy of this ListOfOutputs object.
   *
   * @return a (deep) copy of this ListOfOutputs object.
   */
  virtual ListOfOutputs* clone() const;


  /**
   * Destructor for ListOfOutputs.
   */
  virtual ~ListOfOutputs();


  /**
   * Get an Output from the ListOfOutputs.
   *
   * @param n, an unsigned int representing the index of the Output to
   * retrieve.
   *
   * @return the nth Output in this ListOfOutputs.
   *
   * @see size()
   */
  virtual Output* get(unsigned int n);


  /**
   * Get an Output from the ListOfOutputs.
   *
   * @param n, an unsigned int representing the index of the Output to
   * retrieve.
   *
   * @return the nth Output in this ListOfOutputs.
   *
   * @see size()
   */
  virtual const Output* get(unsigned int n) const;


  /**
   * Get an Output from the ListOfOutputs based on its identifier.
   *
   * @param sid a string representing the identifier of the Output to retrieve.
   *
   * @return the Output in this ListOfOutputs with the given id or NULL if no
   * such Output exists.
   *
   * @see size()
   */
  virtual Output* get(const std::string& sid);


  /**
   * Get an Output from the ListOfOutputs based on its identifier.
   *
   * @param sid a string representing the identifier of the Output to retrieve.
   *
   * @return the Output in this ListOfOutputs with the given id or NULL if no
   * such Output exists.
   *
   * @see size()
   */
  virtual const Output* get(const std::string& sid) const;


  /**
   * Removes the nth Output from this ListOfOutputs and returns a pointer to
   * it.
   *
   * @param n, an unsigned int representing the index of the Output to remove.
   *
   * @return a pointer to the nth Output in this ListOfOutputs.
   *
   * @see size()
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual Output* remove(unsigned int n);


  /**
   * Removes the Output from this ListOfOutputs based on its identifier and
   * returns a pointer to it.
   *
   * @param sid, a string representing the identifier of the Output to remove.
   *
   * @return the Output in this ListOfOutputs based on the identifier or NULL
   * if no such Output exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual Output* remove(const std::string& sid);


  /**
   * Adds a copy of the given Output to this ListOfOutputs.
   *
   * @param o, the Output object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createOutput()
   */
  int addOutput(const Output* o);


  /**
   * Get the number of Output objects in this ListOfOutputs.
   *
   * @return the number of Output objects in this ListOfOutputs.
   */
  unsigned int getNumOutputs() const;


  /**
   * Creates a new Output object, adds it to this ListOfOutputs object and
   * returns the Output object created.
   *
   * @return a new Output object instance.
   *
   * @see addOutput(const Output* o)
   */
  Output* createOutput();


  /**
   * Get an Output from the ListOfOutputs based on the QualitativeSpecies to
   * which it refers.
   *
   * @param sid a string representing the qualitativeSpecies attribute of the
   * Output object to retrieve.
   *
   * @return the first Output in this ListOfOutputs based on the given
   * qualitativeSpecies attribute or NULL if no such Output exists.
   */
  const Output* getByQualitativeSpecies(const std::string& sid) const;


  /**
   * Get an Output from the ListOfOutputs based on the QualitativeSpecies to
   * which it refers.
   *
   * @param sid a string representing the qualitativeSpecies attribute of the
   * Output object to retrieve.
   *
   * @return the first Output in this ListOfOutputs based on the given
   * qualitativeSpecies attribute or NULL if no such Output exists.
   */
  Output* getByQualitativeSpecies(const std::string& sid);


  /**
   * Returns the XML element name of this ListOfOutputs object.
   *
   * For ListOfOutputs, the XML element name is always @c "listOfOutputs".
   *
   * @return the name of this element, i.e. @c "listOfOutputs".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ListOfOutputs object.
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
   * ListOfOutputs object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this ListOfOutputs:
   *
   * @sbmlconstant{SBML_QUAL_OUTPUT, SBMLQualTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode() const;


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new Output in this ListOfOutputs
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
 * Get an Output_t from the ListOf_t.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Output_t to
 * retrieve.
 *
 * @return the nth Output_t in this ListOf_t.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
const Output_t*
ListOfOutputs_getOutput(ListOf_t* lo, unsigned int n);


/**
 * Get an Output_t from the ListOf_t based on its identifier.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the Output_t to retrieve.
 *
 * @return the Output_t in this ListOf_t with the given id or NULL if no such
 * Output_t exists.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
const Output_t*
ListOfOutputs_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth Output_t from this ListOf_t and returns a pointer to it.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Output_t to remove.
 *
 * @return a pointer to the nth Output_t in this ListOf_t.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
Output_t*
ListOfOutputs_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the Output_t from this ListOf_t based on its identifier and returns
 * a pointer to it.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param sid, a string representing the identifier of the Output_t to remove.
 *
 * @return the Output_t in this ListOf_t based on the identifier or NULL if no
 * such Output_t exists.
 *
 * @memberof Output_t
 */
LIBSBML_EXTERN
Output_t*
ListOfOutputs_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfOutputs_H__ */


