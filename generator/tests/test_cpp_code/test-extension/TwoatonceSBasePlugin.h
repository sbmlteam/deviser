/**
 * @file TwoatonceSBasePlugin.h
 * @brief Definition of the TwoatonceSBasePlugin class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
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
 * @class TwoatonceSBasePlugin
 * @sbmlbrief{twoatonce} Extension of SBase.
 */


#ifndef TwoatonceSBasePlugin_H__
#define TwoatonceSBasePlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/twoatonce/sbml/NormalClass.h>
#include <sbml/packages/twoatonce/sbml/ClassWithRequiredID.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN TwoatonceSBasePlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  NormalClass* mNormalClass;
  ClassWithRequiredID* mClassWithRequiredID;

  /** @endcond */

public:

  /**
   * Creates a new TwoatonceSBasePlugin using the given URI, prefix and package
   * namespace.
   *
   * @param uri a string, representing the URI of the SBML Level&nbsp;3 package
   * implemented by this libSBML package extension.
   *
   * @param prefix a string, the XML namespace prefix being used for this
   * package.
   *
   * @param twoatoncens a pointer to the namesspaces object
   * (TwoatoncePkgNamespaces) for this package.
   *
   * @copydetails doc_what_are_xmlnamespaces
   *
   * @copydetails doc_what_are_sbmlnamespaces
   */
  TwoatonceSBasePlugin(const std::string& uri,
                       const std::string& prefix,
                       TwoatoncePkgNamespaces* twoatoncens);


  /**
   * Copy constructor for TwoatonceSBasePlugin.
   *
   * @param orig the TwoatonceSBasePlugin instance to copy.
   */
  TwoatonceSBasePlugin(const TwoatonceSBasePlugin& orig);


  /**
   * Assignment operator for TwoatonceSBasePlugin.
   *
   * @param rhs the TwoatonceSBasePlugin object whose values are to be used as
   * the basis of the assignment.
   */
  TwoatonceSBasePlugin& operator=(const TwoatonceSBasePlugin& rhs);


  /**
   * Creates and returns a deep copy of this TwoatonceSBasePlugin object.
   *
   * @return a (deep) copy of this TwoatonceSBasePlugin object.
   */
  virtual TwoatonceSBasePlugin* clone() const;


  /**
   * Destructor for TwoatonceSBasePlugin.
   */
  virtual ~TwoatonceSBasePlugin();


  /**
   * Returns the value of the "normalClass" element of this
   * TwoatonceSBasePlugin.
   *
   * @return the value of the "normalClass" element of this
   * TwoatonceSBasePlugin as a NormalClass*.
   */
  const NormalClass* getNormalClass() const;


  /**
   * Returns the value of the "normalClass" element of this
   * TwoatonceSBasePlugin.
   *
   * @return the value of the "normalClass" element of this
   * TwoatonceSBasePlugin as a NormalClass*.
   */
  NormalClass* getNormalClass();


  /**
   * Returns the value of the "classWithRequiredID" element of this
   * TwoatonceSBasePlugin.
   *
   * @return the value of the "classWithRequiredID" element of this
   * TwoatonceSBasePlugin as a ClassWithRequiredID*.
   */
  const ClassWithRequiredID* getClassWithRequiredID() const;


  /**
   * Returns the value of the "classWithRequiredID" element of this
   * TwoatonceSBasePlugin.
   *
   * @return the value of the "classWithRequiredID" element of this
   * TwoatonceSBasePlugin as a ClassWithRequiredID*.
   */
  ClassWithRequiredID* getClassWithRequiredID();


  /**
   * Predicate returning @c true if this TwoatonceSBasePlugin's "normalClass"
   * element is set.
   *
   * @return @c true if this TwoatonceSBasePlugin's "normalClass" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetNormalClass() const;


  /**
   * Predicate returning @c true if this TwoatonceSBasePlugin's
   * "classWithRequiredID" element is set.
   *
   * @return @c true if this TwoatonceSBasePlugin's "classWithRequiredID"
   * element has been set, otherwise @c false is returned.
   */
  bool isSetClassWithRequiredID() const;


  /**
   * Sets the value of the "normalClass" element of this TwoatonceSBasePlugin.
   *
   * @param normalClass NormalClass* value of the "normalClass" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNormalClass(const NormalClass* normalClass);


  /**
   * Sets the value of the "classWithRequiredID" element of this
   * TwoatonceSBasePlugin.
   *
   * @param classWithRequiredID ClassWithRequiredID* value of the
   * "classWithRequiredID" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setClassWithRequiredID(const ClassWithRequiredID* classWithRequiredID);


  /**
   * Creates a new NormalClass object, adds it to this TwoatonceSBasePlugin
   * object and returns the NormalClass object created.
   *
   * @return a new NormalClass object instance.
   */
  NormalClass* createNormalClass();


  /**
   * Creates a new ClassWithRequiredID object, adds it to this
   * TwoatonceSBasePlugin object and returns the ClassWithRequiredID object
   * created.
   *
   * @return a new ClassWithRequiredID object instance.
   */
  ClassWithRequiredID* createClassWithRequiredID();


  /**
   * Unsets the value of the "normalClass" element of this
   * TwoatonceSBasePlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNormalClass();


  /**
   * Unsets the value of the "classWithRequiredID" element of this
   * TwoatonceSBasePlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClassWithRequiredID();



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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Updates the namespaces when setLevelVersion is used
   */
  virtual void updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Gets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Gets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Gets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Gets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Predicate returning @c true if this TwoatonceSBasePlugin's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this TwoatonceSBasePlugin's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Sets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Sets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Sets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Sets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Unsets the value of the "attributeName" attribute of this
   * TwoatonceSBasePlugin.
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
   * Creates and returns an new "elementName" object in this
   * TwoatonceSBasePlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this TwoatonceSBasePlugin.
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
                             const SBase* element);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * TwoatonceSBasePlugin.
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
   * Returns the number of "elementName" in this TwoatonceSBasePlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this TwoatonceSBasePlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
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
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
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
 * Returns the value of the "normalClass" element of this
 * TwoatonceSBasePlugin_t.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure whose normalClass is
 * sought.
 *
 * @return the value of the "normalClass" element of this
 * TwoatonceSBasePlugin_t as a NormalClass*.
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
const NormalClass_t*
TwoatonceSBasePlugin_getNormalClass(const TwoatonceSBasePlugin_t * tsbp);


/**
 * Returns the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure whose classWithRequiredID
 * is sought.
 *
 * @return the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t as a ClassWithRequiredID*.
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
const ClassWithRequiredID_t*
TwoatonceSBasePlugin_getClassWithRequiredID(const TwoatonceSBasePlugin_t *
  tsbp);


/**
 * Predicate returning @c 1 (true) if this TwoatonceSBasePlugin_t's
 * "normalClass" element is set.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure.
 *
 * @return @c 1 (true) if this TwoatonceSBasePlugin_t's "normalClass" element
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_isSetNormalClass(const TwoatonceSBasePlugin_t * tsbp);


/**
 * Predicate returning @c 1 (true) if this TwoatonceSBasePlugin_t's
 * "classWithRequiredID" element is set.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure.
 *
 * @return @c 1 (true) if this TwoatonceSBasePlugin_t's "classWithRequiredID"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_isSetClassWithRequiredID(const TwoatonceSBasePlugin_t *
  tsbp);


/**
 * Sets the value of the "normalClass" element of this TwoatonceSBasePlugin_t.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure.
 *
 * @param normalClass NormalClass_t* value of the "normalClass" element to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_setNormalClass(TwoatonceSBasePlugin_t * tsbp,
                                    const NormalClass_t* normalClass);


/**
 * Sets the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure.
 *
 * @param classWithRequiredID ClassWithRequiredID_t* value of the
 * "classWithRequiredID" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_setClassWithRequiredID(TwoatonceSBasePlugin_t * tsbp,
                                            const ClassWithRequiredID_t*
                                              classWithRequiredID);


/**
 * Creates a new NormalClass_t object, adds it to this TwoatonceSBasePlugin_t
 * object and returns the NormalClass_t object created.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure to which the NormalClass_t
 * should be added.
 *
 * @return a new NormalClass_t object instance.
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
NormalClass_t*
TwoatonceSBasePlugin_createNormalClass(TwoatonceSBasePlugin_t* tsbp);


/**
 * Creates a new ClassWithRequiredID_t object, adds it to this
 * TwoatonceSBasePlugin_t object and returns the ClassWithRequiredID_t object
 * created.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure to which the
 * ClassWithRequiredID_t should be added.
 *
 * @return a new ClassWithRequiredID_t object instance.
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
ClassWithRequiredID_t*
TwoatonceSBasePlugin_createClassWithRequiredID(TwoatonceSBasePlugin_t* tsbp);


/**
 * Unsets the value of the "normalClass" element of this
 * TwoatonceSBasePlugin_t.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_unsetNormalClass(TwoatonceSBasePlugin_t * tsbp);


/**
 * Unsets the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t.
 *
 * @param tsbp the TwoatonceSBasePlugin_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TwoatonceSBasePlugin_t
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_unsetClassWithRequiredID(TwoatonceSBasePlugin_t * tsbp);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !TwoatonceSBasePlugin_H__ */


