/**
 * @file GradientStop.h
 * @brief Definition of the GradientStop class.
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
 * @class GradientStop
 * @sbmlbrief{render} TODO:Definition of the GradientStop class.
 */


#ifndef GradientStop_H__
#define GradientStop_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/render/common/renderfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/render/extension/RenderExtension.h>
#include <sbml/packages/render/sbml/RelAbsVector.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN GradientStop : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  RelAbsVector* mOffset;
  std::string mStopColor;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new GradientStop using the given SBML Level, Version and
   * &ldquo;render&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * GradientStop.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * GradientStop.
   *
   * @param pkgVersion an unsigned int, the SBML Render Version to assign to
   * this GradientStop.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  GradientStop(unsigned int level = RenderExtension::getDefaultLevel(),
               unsigned int version = RenderExtension::getDefaultVersion(),
               unsigned int pkgVersion =
                 RenderExtension::getDefaultPackageVersion());


  /**
   * Creates a new GradientStop using the given RenderPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param renderns the RenderPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  GradientStop(RenderPkgNamespaces *renderns);


  /**
   * Copy constructor for GradientStop.
   *
   * @param orig the GradientStop instance to copy.
   */
  GradientStop(const GradientStop& orig);


  /**
   * Assignment operator for GradientStop.
   *
   * @param rhs the GradientStop object whose values are to be used as the
   * basis of the assignment.
   */
  GradientStop& operator=(const GradientStop& rhs);


  /**
   * Creates and returns a deep copy of this GradientStop object.
   *
   * @return a (deep) copy of this GradientStop object.
   */
  virtual GradientStop* clone() const;


  /**
   * Destructor for GradientStop.
   */
  virtual ~GradientStop();


  /**
   * Returns the value of the "stop-color" attribute of this GradientStop.
   *
   * @return the value of the "stop-color" attribute of this GradientStop as a
   * string.
   */
  const std::string& getStopColor() const;


  /**
   * Predicate returning @c true if this GradientStop's "stop-color" attribute
   * is set.
   *
   * @return @c true if this GradientStop's "stop-color" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetStopColor() const;


  /**
   * Sets the value of the "stop-color" attribute of this GradientStop.
   *
   * @param stopColor std::string& value of the "stop-color" attribute to be
   * set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p stopColor = @c NULL or an empty string is
   * equivalent to calling unsetStopColor().
   */
  int setStopColor(const std::string& stopColor);


  /**
   * Unsets the value of the "stop-color" attribute of this GradientStop.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStopColor();


  /**
   * Returns the value of the "offset" element of this GradientStop.
   *
   * @return the value of the "offset" element of this GradientStop as a
   * RelAbsVector*.
   */
  const RelAbsVector* getOffset() const;


  /**
   * Returns the value of the "offset" element of this GradientStop.
   *
   * @return the value of the "offset" element of this GradientStop as a
   * RelAbsVector*.
   */
  RelAbsVector* getOffset();


  /**
   * Predicate returning @c true if this GradientStop's "offset" element is
   * set.
   *
   * @return @c true if this GradientStop's "offset" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetOffset() const;


  /**
   * Sets the value of the "offset" element of this GradientStop.
   *
   * @param offset RelAbsVector* value of the "offset" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOffset(const RelAbsVector* offset);


  /**
   * Creates a new RelAbsVector object, adds it to this GradientStop object and
   * returns the RelAbsVector object created.
   *
   * @return a new RelAbsVector object instance.
   */
  RelAbsVector* createOffset();


  /**
   * Unsets the value of the "offset" element of this GradientStop.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOffset();


  /**
   * Returns the XML element name of this GradientStop object.
   *
   * For GradientStop, the XML element name is always @c "stop".
   *
   * @return the name of this element, i.e. @c "stop".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the XML name of this GradientStop object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBML type code for this GradientStop object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_RENDER_GRADIENT_STOP, SBMLRenderTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * GradientStop object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * GradientStop have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the GradientStop object are:
   * @li "stop-color"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * GradientStop object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * GradientStop have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the GradientStop object are:
   * @li "offset"
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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this GradientStop.
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
   * Gets the value of the "attributeName" attribute of this GradientStop.
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
   * Gets the value of the "attributeName" attribute of this GradientStop.
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
   * Gets the value of the "attributeName" attribute of this GradientStop.
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
   * Gets the value of the "attributeName" attribute of this GradientStop.
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
   * Predicate returning @c true if this GradientStop's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this GradientStop's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this GradientStop.
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
   * Sets the value of the "attributeName" attribute of this GradientStop.
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
   * Sets the value of the "attributeName" attribute of this GradientStop.
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
   * Sets the value of the "attributeName" attribute of this GradientStop.
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
   * Sets the value of the "attributeName" attribute of this GradientStop.
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
   * Unsets the value of the "attributeName" attribute of this GradientStop.
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
   * Creates and returns an new "elementName" object in this GradientStop.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this GradientStop.
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
   * GradientStop.
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
   * Returns the number of "elementName" in this GradientStop.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this GradientStop.
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
 * Creates a new GradientStop_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * GradientStop_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * GradientStop_t.
 *
 * @param pkgVersion an unsigned int, the SBML Render Version to assign to this
 * GradientStop_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
GradientStop_t *
GradientStop_create(unsigned int level,
                    unsigned int version,
                    unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this GradientStop_t object.
 *
 * @param gs the GradientStop_t structure.
 *
 * @return a (deep) copy of this GradientStop_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
GradientStop_t*
GradientStop_clone(const GradientStop_t* gs);


/**
 * Frees this GradientStop_t object.
 *
 * @param gs the GradientStop_t structure.
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
void
GradientStop_free(GradientStop_t* gs);


/**
 * Returns the value of the "stop-color" attribute of this GradientStop_t.
 *
 * @param gs the GradientStop_t structure whose stop-color is sought.
 *
 * @return the value of the "stop-color" attribute of this GradientStop_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
char *
GradientStop_getStopColor(const GradientStop_t * gs);


/**
 * Predicate returning @c 1 (true) if this GradientStop_t's "stop-color"
 * attribute is set.
 *
 * @param gs the GradientStop_t structure.
 *
 * @return @c 1 (true) if this GradientStop_t's "stop-color" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_isSetStopColor(const GradientStop_t * gs);


/**
 * Sets the value of the "stop-color" attribute of this GradientStop_t.
 *
 * @param gs the GradientStop_t structure.
 *
 * @param stopColor const char * value of the "stop-color" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p stopColor = @c NULL or an empty string is
 * equivalent to calling GradientStop_unsetStopColor().
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_setStopColor(GradientStop_t * gs, const char * stopColor);


/**
 * Unsets the value of the "stop-color" attribute of this GradientStop_t.
 *
 * @param gs the GradientStop_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_unsetStopColor(GradientStop_t * gs);


/**
 * Returns the value of the "offset" element of this GradientStop_t.
 *
 * @param gs the GradientStop_t structure whose offset is sought.
 *
 * @return the value of the "offset" element of this GradientStop_t as a
 * RelAbsVector*.
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
const RelAbsVector_t*
GradientStop_getOffset(const GradientStop_t * gs);


/**
 * Predicate returning @c 1 (true) if this GradientStop_t's "offset" element is
 * set.
 *
 * @param gs the GradientStop_t structure.
 *
 * @return @c 1 (true) if this GradientStop_t's "offset" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_isSetOffset(const GradientStop_t * gs);


/**
 * Sets the value of the "offset" element of this GradientStop_t.
 *
 * @param gs the GradientStop_t structure.
 *
 * @param offset RelAbsVector_t* value of the "offset" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_setOffset(GradientStop_t * gs, const RelAbsVector_t* offset);


/**
 * Creates a new RelAbsVector_t object, adds it to this GradientStop_t object
 * and returns the RelAbsVector_t object created.
 *
 * @param gs the GradientStop_t structure to which the RelAbsVector_t should be
 * added.
 *
 * @return a new RelAbsVector_t object instance.
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
RelAbsVector_t*
GradientStop_createOffset(GradientStop_t* gs);


/**
 * Unsets the value of the "offset" element of this GradientStop_t.
 *
 * @param gs the GradientStop_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_unsetOffset(GradientStop_t * gs);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * GradientStop_t object have been set.
 *
 * @param gs the GradientStop_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * GradientStop_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the GradientStop_t object are:
 * @li "stop-color"
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_hasRequiredAttributes(const GradientStop_t * gs);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * GradientStop_t object have been set.
 *
 * @param gs the GradientStop_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * GradientStop_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the GradientStop_t object are:
 * @li "offset"
 *
 * @memberof GradientStop_t
 */
LIBSBML_EXTERN
int
GradientStop_hasRequiredElements(const GradientStop_t * gs);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !GradientStop_H__ */


