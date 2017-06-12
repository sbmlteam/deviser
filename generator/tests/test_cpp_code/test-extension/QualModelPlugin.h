/**
 * @file QualModelPlugin.h
 * @brief Definition of the QualModelPlugin class.
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
 * @class QualModelPlugin
 * @sbmlbrief{qual} Extension of Model.
 */


#ifndef QualModelPlugin_H__
#define QualModelPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/qual/sbml/ListOfQualitativeSpecies.h>
#include <sbml/packages/qual/sbml/QualitativeSpecies.h>
#include <sbml/packages/qual/sbml/ListOfTransitions.h>
#include <sbml/packages/qual/sbml/Transition.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN QualModelPlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfQualitativeSpecies mQualitativeSpecies;
  ListOfTransitions mTransitions;

  /** @endcond */

public:

  /**
   * Creates a new QualModelPlugin using the given uri, prefix and package
   * namespace.
   *
   * @param uri a string, representing the uri of the package.
   *
   * @param prefix a string, the prefix to be used.
   *
   * @param qualns a pointer to the QualPkgNamespaces object to be used.
   */
  QualModelPlugin(const std::string& uri,
                  const std::string& prefix,
                  QualPkgNamespaces* qualns);


  /**
   * Copy constructor for QualModelPlugin.
   *
   * @param orig the QualModelPlugin instance to copy.
   */
  QualModelPlugin(const QualModelPlugin& orig);


  /**
   * Assignment operator for QualModelPlugin.
   *
   * @param rhs the QualModelPlugin object whose values are to be used as the
   * basis of the assignment.
   */
  QualModelPlugin& operator=(const QualModelPlugin& rhs);


  /**
   * Creates and returns a deep copy of this QualModelPlugin object.
   *
   * @return a (deep) copy of this QualModelPlugin object.
   */
  virtual QualModelPlugin* clone() const;


  /**
   * Destructor for QualModelPlugin.
   */
  virtual ~QualModelPlugin();


  /**
   * Returns the ListOfQualitativeSpecies from this QualModelPlugin.
   *
   * @return the ListOfQualitativeSpecies from this QualModelPlugin.
   */
  const ListOfQualitativeSpecies* getListOfQualitativeSpecies() const;


  /**
   * Returns the ListOfQualitativeSpecies from this QualModelPlugin.
   *
   * @return the ListOfQualitativeSpecies from this QualModelPlugin.
   */
  ListOfQualitativeSpecies* getListOfQualitativeSpecies();


  /**
   * Get a QualitativeSpecies from the QualModelPlugin.
   *
   * @param n an unsigned int representing the index of the QualitativeSpecies
   * to retrieve.
   *
   * @return the nth QualitativeSpecies in the ListOfQualitativeSpecies within
   * this QualModelPlugin.
   *
   * @see getNumQualitativeSpecies()
   */
  QualitativeSpecies* getQualitativeSpecies(unsigned int n);


  /**
   * Get a QualitativeSpecies from the QualModelPlugin.
   *
   * @param n an unsigned int representing the index of the QualitativeSpecies
   * to retrieve.
   *
   * @return the nth QualitativeSpecies in the ListOfQualitativeSpecies within
   * this QualModelPlugin.
   *
   * @see getNumQualitativeSpecies()
   */
  const QualitativeSpecies* getQualitativeSpecies(unsigned int n) const;


  /**
   * Get a QualitativeSpecies from the QualModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the QualitativeSpecies
   * to retrieve.
   *
   * @return the QualitativeSpecies in the ListOfQualitativeSpecies within this
   * QualModelPlugin with the given id or NULL if no such QualitativeSpecies
   * exists.
   *
   * @see getQualitativeSpecies(unsigned int n)
   * @see getNumQualitativeSpecies()
   */
  QualitativeSpecies* getQualitativeSpecies(const std::string& sid);


  /**
   * Get a QualitativeSpecies from the QualModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the QualitativeSpecies
   * to retrieve.
   *
   * @return the QualitativeSpecies in the ListOfQualitativeSpecies within this
   * QualModelPlugin with the given id or NULL if no such QualitativeSpecies
   * exists.
   *
   * @see getQualitativeSpecies(unsigned int n)
   * @see getNumQualitativeSpecies()
   */
  const QualitativeSpecies* getQualitativeSpecies(const std::string& sid)
    const;


  /**
   * Get a QualitativeSpecies from the QualModelPlugin based on the Compartment
   * to which it refers.
   *
   * @param sid a string representing the compartment attribute of the
   * QualitativeSpecies object to retrieve.
   *
   * @return the first QualitativeSpecies in this QualModelPlugin based on the
   * given compartment attribute or NULL if no such QualitativeSpecies exists.
   */
  const QualitativeSpecies* getQualitativeSpeciesByCompartment(const
    std::string& sid) const;


  /**
   * Get a QualitativeSpecies from the QualModelPlugin based on the Compartment
   * to which it refers.
   *
   * @param sid a string representing the compartment attribute of the
   * QualitativeSpecies object to retrieve.
   *
   * @return the first QualitativeSpecies in this QualModelPlugin based on the
   * given compartment attribute or NULL if no such QualitativeSpecies exists.
   */
  QualitativeSpecies* getQualitativeSpeciesByCompartment(const std::string&
    sid);


  /**
   * Adds a copy of the given QualitativeSpecies to this QualModelPlugin.
   *
   * @param qs the QualitativeSpecies object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createQualitativeSpecies()
   */
  int addQualitativeSpecies(const QualitativeSpecies* qs);


  /**
   * Get the number of QualitativeSpecies objects in this QualModelPlugin.
   *
   * @return the number of QualitativeSpecies objects in this QualModelPlugin.
   */
  unsigned int getNumQualitativeSpecies() const;


  /**
   * Creates a new QualitativeSpecies object, adds it to this QualModelPlugin
   * object and returns the QualitativeSpecies object created.
   *
   * @return a new QualitativeSpecies object instance.
   *
   * @see addQualitativeSpecies(const QualitativeSpecies* qs)
   */
  QualitativeSpecies* createQualitativeSpecies();


  /**
   * Removes the nth QualitativeSpecies from this QualModelPlugin and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the QualitativeSpecies
   * to remove.
   *
   * @return a pointer to the nth QualitativeSpecies in this QualModelPlugin.
   *
   * @see getNumQualitativeSpecies
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  QualitativeSpecies* removeQualitativeSpecies(unsigned int n);


  /**
   * Removes the QualitativeSpecies from this QualModelPlugin based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the QualitativeSpecies
   * to remove.
   *
   * @return the QualitativeSpecies in this QualModelPlugin based on the
   * identifier or NULL if no such QualitativeSpecies exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  QualitativeSpecies* removeQualitativeSpecies(const std::string& sid);


  /**
   * Returns the ListOfTransitions from this QualModelPlugin.
   *
   * @return the ListOfTransitions from this QualModelPlugin.
   */
  const ListOfTransitions* getListOfTransitions() const;


  /**
   * Returns the ListOfTransitions from this QualModelPlugin.
   *
   * @return the ListOfTransitions from this QualModelPlugin.
   */
  ListOfTransitions* getListOfTransitions();


  /**
   * Get a Transition from the QualModelPlugin.
   *
   * @param n an unsigned int representing the index of the Transition to
   * retrieve.
   *
   * @return the nth Transition in the ListOfTransitions within this
   * QualModelPlugin.
   *
   * @see getNumTransitions()
   */
  Transition* getTransition(unsigned int n);


  /**
   * Get a Transition from the QualModelPlugin.
   *
   * @param n an unsigned int representing the index of the Transition to
   * retrieve.
   *
   * @return the nth Transition in the ListOfTransitions within this
   * QualModelPlugin.
   *
   * @see getNumTransitions()
   */
  const Transition* getTransition(unsigned int n) const;


  /**
   * Get a Transition from the QualModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the Transition to
   * retrieve.
   *
   * @return the Transition in the ListOfTransitions within this
   * QualModelPlugin with the given id or NULL if no such Transition exists.
   *
   * @see getTransition(unsigned int n)
   * @see getNumTransitions()
   */
  Transition* getTransition(const std::string& sid);


  /**
   * Get a Transition from the QualModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the Transition to
   * retrieve.
   *
   * @return the Transition in the ListOfTransitions within this
   * QualModelPlugin with the given id or NULL if no such Transition exists.
   *
   * @see getTransition(unsigned int n)
   * @see getNumTransitions()
   */
  const Transition* getTransition(const std::string& sid) const;


  /**
   * Adds a copy of the given Transition to this QualModelPlugin.
   *
   * @param t the Transition object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createTransition()
   */
  int addTransition(const Transition* t);


  /**
   * Get the number of Transition objects in this QualModelPlugin.
   *
   * @return the number of Transition objects in this QualModelPlugin.
   */
  unsigned int getNumTransitions() const;


  /**
   * Creates a new Transition object, adds it to this QualModelPlugin object
   * and returns the Transition object created.
   *
   * @return a new Transition object instance.
   *
   * @see addTransition(const Transition* t)
   */
  Transition* createTransition();


  /**
   * Removes the nth Transition from this QualModelPlugin and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the Transition to
   * remove.
   *
   * @return a pointer to the nth Transition in this QualModelPlugin.
   *
   * @see getNumTransitions
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Transition* removeTransition(unsigned int n);


  /**
   * Removes the Transition from this QualModelPlugin based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the Transition to
   * remove.
   *
   * @return the Transition in this QualModelPlugin based on the identifier or
   * NULL if no such Transition exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Transition* removeTransition(const std::string& sid);


  /**
   * Predicate returning @c true if all the required elements for this
   * QualModelPlugin object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * QualModelPlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the QualModelPlugin object are:
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
   * Connects to parent element
   */
  virtual void connectToParent(SBase* base);

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
   * Gets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Predicate returning @c true if this QualModelPlugin's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this QualModelPlugin's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this QualModelPlugin.
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
   * Unsets the value of the "attributeName" attribute of this QualModelPlugin.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates and returns an new "elementName" object in this QualModelPlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this QualModelPlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SBasePlugin* element);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * QualModelPlugin.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SBase* removeChildObject(const std::string& elementName,
                                   const std::string& id);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the number of "elementName" in this QualModelPlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this QualModelPlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int teh index of teh object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SBase* getObject(const std::string& elementName, unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Append items from model (used in comp flattening)
   *
   * @param model a pointer to a model object.
   *
   */
  int appendFrom(const Model* model);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Returns a ListOf_t* containing QualitativeSpecies_t objects from this
 * QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure whose "ListOfQualitativeSpecies"
 * is sought.
 *
 * @return the "ListOfQualitativeSpecies" from this QualModelPlugin_t as a
 * ListOf_t *.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
QualModelPlugin_getListOfQualitativeSpecies(QualModelPlugin_t* qmp);


/**
 * Get a QualitativeSpecies_t from the QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the QualitativeSpecies_t
 * to retrieve.
 *
 * @return the nth QualitativeSpecies_t in the ListOfQualitativeSpecies within
 * this QualModelPlugin.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
const QualitativeSpecies_t*
QualModelPlugin_getQualitativeSpecies(QualModelPlugin_t* qmp, unsigned int n);


/**
 * Get a QualitativeSpecies_t from the QualModelPlugin_t based on its
 * identifier.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the QualitativeSpecies_t
 * to retrieve.
 *
 * @return the QualitativeSpecies_t in the ListOfQualitativeSpecies within this
 * QualModelPlugin with the given id or NULL if no such QualitativeSpecies_t
 * exists.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
const QualitativeSpecies_t*
QualModelPlugin_getQualitativeSpeciesById(QualModelPlugin_t* qmp,
                                          const char *sid);


/**
 * Get a QualitativeSpecies_t from the QualModelPlugin_t based on the
 * Compartment to which it refers.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param sid a string representing the compartment attribute of the
 * QualitativeSpecies_t object to retrieve.
 *
 * @return the first QualitativeSpecies_t in this QualModelPlugin_t based on
 * the given compartment attribute or NULL if no such QualitativeSpecies_t
 * exists.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
const QualitativeSpecies_t*
QualModelPlugin_getQualitativeSpeciesByCompartment(QualModelPlugin_t* qmp,
                                                   const char *sid);


/**
 * Adds a copy of the given QualitativeSpecies_t to this QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure to which the QualitativeSpecies_t
 * should be added.
 *
 * @param qs the QualitativeSpecies_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
int
QualModelPlugin_addQualitativeSpecies(QualModelPlugin_t* qmp,
                                      const QualitativeSpecies_t* qs);


/**
 * Get the number of QualitativeSpecies_t objects in this QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure to query.
 *
 * @return the number of QualitativeSpecies_t objects in this
 * QualModelPlugin_t.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
unsigned int
QualModelPlugin_getNumQualitativeSpecies(QualModelPlugin_t* qmp);


/**
 * Creates a new QualitativeSpecies_t object, adds it to this QualModelPlugin_t
 * object and returns the QualitativeSpecies_t object created.
 *
 * @param qmp the QualModelPlugin_t structure to which the QualitativeSpecies_t
 * should be added.
 *
 * @return a new QualitativeSpecies_t object instance.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
QualitativeSpecies_t*
QualModelPlugin_createQualitativeSpecies(QualModelPlugin_t* qmp);


/**
 * Removes the nth QualitativeSpecies_t from this QualModelPlugin_t and returns
 * a pointer to it.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the QualitativeSpecies_t
 * to remove.
 *
 * @return a pointer to the nth QualitativeSpecies_t in this QualModelPlugin_t.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
QualitativeSpecies_t*
QualModelPlugin_removeQualitativeSpecies(QualModelPlugin_t* qmp,
                                         unsigned int n);


/**
 * Removes the QualitativeSpecies_t from this QualModelPlugin_t based on its
 * identifier and returns a pointer to it.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the QualitativeSpecies_t
 * to remove.
 *
 * @return the QualitativeSpecies_t in this QualModelPlugin_t based on the
 * identifier or NULL if no such QualitativeSpecies_t exists.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
QualitativeSpecies_t*
QualModelPlugin_removeQualitativeSpeciesById(QualModelPlugin_t* qmp,
                                             const char* sid);


/**
 * Returns a ListOf_t* containing Transition_t objects from this
 * QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure whose "ListOfTransitions" is
 * sought.
 *
 * @return the "ListOfTransitions" from this QualModelPlugin_t as a ListOf_t *.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
QualModelPlugin_getListOfTransitions(QualModelPlugin_t* qmp);


/**
 * Get a Transition_t from the QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the Transition_t to
 * retrieve.
 *
 * @return the nth Transition_t in the ListOfTransitions within this
 * QualModelPlugin.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
const Transition_t*
QualModelPlugin_getTransition(QualModelPlugin_t* qmp, unsigned int n);


/**
 * Get a Transition_t from the QualModelPlugin_t based on its identifier.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the Transition_t to
 * retrieve.
 *
 * @return the Transition_t in the ListOfTransitions within this
 * QualModelPlugin with the given id or NULL if no such Transition_t exists.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
const Transition_t*
QualModelPlugin_getTransitionById(QualModelPlugin_t* qmp, const char *sid);


/**
 * Adds a copy of the given Transition_t to this QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure to which the Transition_t should
 * be added.
 *
 * @param t the Transition_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
int
QualModelPlugin_addTransition(QualModelPlugin_t* qmp, const Transition_t* t);


/**
 * Get the number of Transition_t objects in this QualModelPlugin_t.
 *
 * @param qmp the QualModelPlugin_t structure to query.
 *
 * @return the number of Transition_t objects in this QualModelPlugin_t.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
unsigned int
QualModelPlugin_getNumTransitions(QualModelPlugin_t* qmp);


/**
 * Creates a new Transition_t object, adds it to this QualModelPlugin_t object
 * and returns the Transition_t object created.
 *
 * @param qmp the QualModelPlugin_t structure to which the Transition_t should
 * be added.
 *
 * @return a new Transition_t object instance.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
Transition_t*
QualModelPlugin_createTransition(QualModelPlugin_t* qmp);


/**
 * Removes the nth Transition_t from this QualModelPlugin_t and returns a
 * pointer to it.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the Transition_t to
 * remove.
 *
 * @return a pointer to the nth Transition_t in this QualModelPlugin_t.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
Transition_t*
QualModelPlugin_removeTransition(QualModelPlugin_t* qmp, unsigned int n);


/**
 * Removes the Transition_t from this QualModelPlugin_t based on its identifier
 * and returns a pointer to it.
 *
 * @param qmp the QualModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the Transition_t to
 * remove.
 *
 * @return the Transition_t in this QualModelPlugin_t based on the identifier
 * or NULL if no such Transition_t exists.
 *
 * @memberof QualModelPlugin_t
 */
LIBSBML_EXTERN
Transition_t*
QualModelPlugin_removeTransitionById(QualModelPlugin_t* qmp, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !QualModelPlugin_H__ */


