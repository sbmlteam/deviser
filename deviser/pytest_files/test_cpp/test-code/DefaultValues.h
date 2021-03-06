/**
 * @file DefaultValues.h
 * @brief Definition of the DefaultValues class.
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
 * @class DefaultValues
 * @sbmlbrief{render} TODO:Definition of the DefaultValues class.
 */


#ifndef DefaultValues_H__
#define DefaultValues_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/render/common/renderfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/render/extension/RenderExtension.h>
#include <sbml/packages/render/sbml/RelAbsVector.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN DefaultValues : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  double mStrokeWidth;
  bool mIsSetStrokeWidth;
  RelAbsVector* mFontSize;
  std::string mStartHead;

  /** @endcond */

public:

  /**
   * Creates a new DefaultValues using the given SBML Level, Version and
   * &ldquo;render&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * DefaultValues.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * DefaultValues.
   *
   * @param pkgVersion an unsigned int, the SBML Render Version to assign to
   * this DefaultValues.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DefaultValues(unsigned int level = RenderExtension::getDefaultLevel(),
                unsigned int version = RenderExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                  RenderExtension::getDefaultPackageVersion());


  /**
   * Creates a new DefaultValues using the given RenderPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param renderns the RenderPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DefaultValues(RenderPkgNamespaces *renderns);


  /**
   * Copy constructor for DefaultValues.
   *
   * @param orig the DefaultValues instance to copy.
   */
  DefaultValues(const DefaultValues& orig);


  /**
   * Assignment operator for DefaultValues.
   *
   * @param rhs the DefaultValues object whose values are to be used as the
   * basis of the assignment.
   */
  DefaultValues& operator=(const DefaultValues& rhs);


  /**
   * Creates and returns a deep copy of this DefaultValues object.
   *
   * @return a (deep) copy of this DefaultValues object.
   */
  virtual DefaultValues* clone() const;


  /**
   * Destructor for DefaultValues.
   */
  virtual ~DefaultValues();


  /**
   * Returns the value of the "stroke-width" attribute of this DefaultValues.
   *
   * @return the value of the "stroke-width" attribute of this DefaultValues as
   * a double.
   */
  double getStrokeWidth() const;


  /**
   * Returns the value of the "startHead" attribute of this DefaultValues.
   *
   * @return the value of the "startHead" attribute of this DefaultValues as a
   * string.
   */
  const std::string& getStartHead() const;


  /**
   * Predicate returning @c true if this DefaultValues's "stroke-width"
   * attribute is set.
   *
   * @return @c true if this DefaultValues's "stroke-width" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetStrokeWidth() const;


  /**
   * Predicate returning @c true if this DefaultValues's "startHead" attribute
   * is set.
   *
   * @return @c true if this DefaultValues's "startHead" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetStartHead() const;


  /**
   * Sets the value of the "stroke-width" attribute of this DefaultValues.
   *
   * @param strokeWidth double value of the "stroke-width" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStrokeWidth(double strokeWidth);


  /**
   * Sets the value of the "startHead" attribute of this DefaultValues.
   *
   * @param startHead std::string& value of the "startHead" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStartHead(const std::string& startHead);


  /**
   * Unsets the value of the "stroke-width" attribute of this DefaultValues.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStrokeWidth();


  /**
   * Unsets the value of the "startHead" attribute of this DefaultValues.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStartHead();


  /**
   * Returns the value of the "font-size" element of this DefaultValues.
   *
   * @return the value of the "font-size" element of this DefaultValues as a
   * RelAbsVector*.
   */
  const RelAbsVector* getFontSize() const;


  /**
   * Returns the value of the "font-size" element of this DefaultValues.
   *
   * @return the value of the "font-size" element of this DefaultValues as a
   * RelAbsVector*.
   */
  RelAbsVector* getFontSize();


  /**
   * Predicate returning @c true if this DefaultValues's "font-size" element is
   * set.
   *
   * @return @c true if this DefaultValues's "font-size" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetFontSize() const;


  /**
   * Sets the value of the "font-size" element of this DefaultValues.
   *
   * @param fontSize RelAbsVector* value of the "font-size" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setFontSize(const RelAbsVector* fontSize);


  /**
   * Creates a new RelAbsVector object, adds it to this DefaultValues object
   * and returns the RelAbsVector object created.
   *
   * @return a new RelAbsVector object instance.
   */
  RelAbsVector* createFontSize();


  /**
   * Unsets the value of the "font-size" element of this DefaultValues.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFontSize();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this DefaultValues object.
   *
   * For DefaultValues, the XML element name is always @c "defaultValues".
   *
   * @return the name of this element, i.e. @c "defaultValues".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this DefaultValues object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_RENDER_DEFAULTS, SBMLRenderTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * DefaultValues object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * DefaultValues have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this DefaultValues.
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
   * Gets the value of the "attributeName" attribute of this DefaultValues.
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
   * Gets the value of the "attributeName" attribute of this DefaultValues.
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
   * Gets the value of the "attributeName" attribute of this DefaultValues.
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
   * Gets the value of the "attributeName" attribute of this DefaultValues.
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
   * Predicate returning @c true if this DefaultValues's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this DefaultValues's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this DefaultValues.
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
   * Sets the value of the "attributeName" attribute of this DefaultValues.
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
   * Sets the value of the "attributeName" attribute of this DefaultValues.
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
   * Sets the value of the "attributeName" attribute of this DefaultValues.
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
   * Sets the value of the "attributeName" attribute of this DefaultValues.
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
   * Unsets the value of the "attributeName" attribute of this DefaultValues.
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
   * Creates and returns an new "elementName" object in this DefaultValues.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this DefaultValues.
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
   * DefaultValues.
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
   * Returns the number of "elementName" in this DefaultValues.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this DefaultValues.
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
   * @return a List pointer of pointers to all SBase child objects with any
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
 * Creates a new DefaultValues_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * DefaultValues_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * DefaultValues_t.
 *
 * @param pkgVersion an unsigned int, the SBML Render Version to assign to this
 * DefaultValues_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
DefaultValues_t *
DefaultValues_create(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this DefaultValues_t object.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @return a (deep) copy of this DefaultValues_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
DefaultValues_t*
DefaultValues_clone(const DefaultValues_t* dv);


/**
 * Frees this DefaultValues_t object.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
void
DefaultValues_free(DefaultValues_t* dv);


/**
 * Returns the value of the "stroke-width" attribute of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure whose stroke-width is sought.
 *
 * @return the value of the "stroke-width" attribute of this DefaultValues_t as
 * a double.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
double
DefaultValues_getStrokeWidth(const DefaultValues_t * dv);


/**
 * Returns the value of the "startHead" attribute of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure whose startHead is sought.
 *
 * @return the value of the "startHead" attribute of this DefaultValues_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
char *
DefaultValues_getStartHead(const DefaultValues_t * dv);


/**
 * Predicate returning @c 1 (true) if this DefaultValues_t's "stroke-width"
 * attribute is set.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @return @c 1 (true) if this DefaultValues_t's "stroke-width" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_isSetStrokeWidth(const DefaultValues_t * dv);


/**
 * Predicate returning @c 1 (true) if this DefaultValues_t's "startHead"
 * attribute is set.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @return @c 1 (true) if this DefaultValues_t's "startHead" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_isSetStartHead(const DefaultValues_t * dv);


/**
 * Sets the value of the "stroke-width" attribute of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @param strokeWidth double value of the "stroke-width" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_setStrokeWidth(DefaultValues_t * dv, double strokeWidth);


/**
 * Sets the value of the "startHead" attribute of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @param startHead const char * value of the "startHead" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_setStartHead(DefaultValues_t * dv, const char * startHead);


/**
 * Unsets the value of the "stroke-width" attribute of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_unsetStrokeWidth(DefaultValues_t * dv);


/**
 * Unsets the value of the "startHead" attribute of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_unsetStartHead(DefaultValues_t * dv);


/**
 * Returns the value of the "font-size" element of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure whose font-size is sought.
 *
 * @return the value of the "font-size" element of this DefaultValues_t as a
 * RelAbsVector*.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
const RelAbsVector_t*
DefaultValues_getFontSize(const DefaultValues_t * dv);


/**
 * Predicate returning @c 1 (true) if this DefaultValues_t's "font-size"
 * element is set.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @return @c 1 (true) if this DefaultValues_t's "font-size" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_isSetFontSize(const DefaultValues_t * dv);


/**
 * Sets the value of the "font-size" element of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @param fontSize RelAbsVector_t* value of the "font-size" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_setFontSize(DefaultValues_t * dv,
                          const RelAbsVector_t* fontSize);


/**
 * Creates a new RelAbsVector_t object, adds it to this DefaultValues_t object
 * and returns the RelAbsVector_t object created.
 *
 * @param dv the DefaultValues_t structure to which the RelAbsVector_t should
 * be added.
 *
 * @return a new RelAbsVector_t object instance.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
RelAbsVector_t*
DefaultValues_createFontSize(DefaultValues_t* dv);


/**
 * Unsets the value of the "font-size" element of this DefaultValues_t.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_unsetFontSize(DefaultValues_t * dv);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DefaultValues_t object have been set.
 *
 * @param dv the DefaultValues_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * DefaultValues_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof DefaultValues_t
 */
LIBSBML_EXTERN
int
DefaultValues_hasRequiredAttributes(const DefaultValues_t * dv);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !DefaultValues_H__ */


