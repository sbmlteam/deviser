/**
 * @file Label.h
 * @brief Definition of the Label class.
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
 * @class Label
 * @sbmlbrief{sbgnml} TODO:Definition of the Label class.
 */


#ifndef Label_H__
#define Label_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SBase.h>
#include <sbgn/BBox.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN Label : public SBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mText;
  BBox* mBBox;

  /** @endcond */

public:

  /**
   * Creates a new Label using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this Label.
   *
   * @param version an unsigned int, the SBGN Version to assign to this Label.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Label(unsigned int level = SBGN_DEFAULT_LEVEL,
        unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new Label using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Label(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for Label.
   *
   * @param orig the Label instance to copy.
   */
  Label(const Label& orig);


  /**
   * Assignment operator for Label.
   *
   * @param rhs the Label object whose values are to be used as the basis of
   * the assignment.
   */
  Label& operator=(const Label& rhs);


  /**
   * Creates and returns a deep copy of this Label object.
   *
   * @return a (deep) copy of this Label object.
   */
  virtual Label* clone() const;


  /**
   * Destructor for Label.
   */
  virtual ~Label();


  /**
   * Returns the value of the "id" attribute of this Label.
   *
   * @return the value of the "id" attribute of this Label as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "text" attribute of this Label.
   *
   * @return the value of the "text" attribute of this Label as a string.
   */
  const std::string& getText() const;


  /**
   * Predicate returning @c true if this Label's "id" attribute is set.
   *
   * @return @c true if this Label's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this Label's "text" attribute is set.
   *
   * @return @c true if this Label's "text" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetText() const;


  /**
   * Sets the value of the "id" attribute of this Label.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "text" attribute of this Label.
   *
   * @param text std::string& value of the "text" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p text = @c NULL or an empty string is
   * equivalent to calling unsetText().
   */
  int setText(const std::string& text);


  /**
   * Unsets the value of the "id" attribute of this Label.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "text" attribute of this Label.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetText();


  /**
   * Returns the value of the "bbox" element of this Label.
   *
   * @return the value of the "bbox" element of this Label as a BBox*.
   */
  const BBox* getBBox() const;


  /**
   * Returns the value of the "bbox" element of this Label.
   *
   * @return the value of the "bbox" element of this Label as a BBox*.
   */
  BBox* getBBox();


  /**
   * Predicate returning @c true if this Label's "bbox" element is set.
   *
   * @return @c true if this Label's "bbox" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetBBox() const;


  /**
   * Sets the value of the "bbox" element of this Label.
   *
   * @param bbox BBox* value of the "bbox" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBBox(const BBox* bbox);


  /**
   * Creates a new BBox object, adds it to this Label object and returns the
   * BBox object created.
   *
   * @return a new BBox object instance.
   */
  BBox* createBBox();


  /**
   * Unsets the value of the "bbox" element of this Label.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBBox();


  /**
   * Returns the XML element name of this Label object.
   *
   * For Label, the XML element name is always @c "label".
   *
   * @return the name of this element, i.e. @c "label".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this Label object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_LABEL, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Label
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Label
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Label object are:
   * @li "text"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this Label
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Label
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Label object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Accepts the given SbgnVisitor
   */
  virtual bool accept(SbgnVisitor& v) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the parent SbgnDocument
   */
  virtual void setSbgnDocument(SbgnDocument* d);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Predicate returning @c true if this Label's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Label's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this Label.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates and returns an new "elementName" object in this Label.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this Label.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SbgnBase* element);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * Label.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SbgnBase* removeChildObject(const std::string& elementName,
                                      const std::string& id);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the number of "elementName" in this Label.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this Label.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SbgnBase* getObject(const std::string& elementName,
                              unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SbgnBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SbgnBase* getElementBySId(const std::string& id);


  /**
   * Returns a List of all child SbgnBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all SbgnBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(SbgnElementFilter * filter = NULL);


protected:


  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SbgnBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Label_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this Label_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this Label_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
Label_t *
Label_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Label_t object.
 *
 * @param l the Label_t structure.
 *
 * @return a (deep) copy of this Label_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
Label_t*
Label_clone(const Label_t* l);


/**
 * Frees this Label_t object.
 *
 * @param l the Label_t structure.
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
void
Label_free(Label_t* l);


/**
 * Returns the value of the "id" attribute of this Label_t.
 *
 * @param l the Label_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Label_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
char *
Label_getId(const Label_t * l);


/**
 * Returns the value of the "text" attribute of this Label_t.
 *
 * @param l the Label_t structure whose text is sought.
 *
 * @return the value of the "text" attribute of this Label_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
char *
Label_getText(const Label_t * l);


/**
 * Predicate returning @c 1 (true) if this Label_t's "id" attribute is set.
 *
 * @param l the Label_t structure.
 *
 * @return @c 1 (true) if this Label_t's "id" attribute has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_isSetId(const Label_t * l);


/**
 * Predicate returning @c 1 (true) if this Label_t's "text" attribute is set.
 *
 * @param l the Label_t structure.
 *
 * @return @c 1 (true) if this Label_t's "text" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_isSetText(const Label_t * l);


/**
 * Sets the value of the "id" attribute of this Label_t.
 *
 * @param l the Label_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_setId(Label_t * l, const char * id);


/**
 * Sets the value of the "text" attribute of this Label_t.
 *
 * @param l the Label_t structure.
 *
 * @param text const char * value of the "text" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p text = @c NULL or an empty string is
 * equivalent to calling Label_unsetText().
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_setText(Label_t * l, const char * text);


/**
 * Unsets the value of the "id" attribute of this Label_t.
 *
 * @param l the Label_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_unsetId(Label_t * l);


/**
 * Unsets the value of the "text" attribute of this Label_t.
 *
 * @param l the Label_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_unsetText(Label_t * l);


/**
 * Returns the value of the "bbox" element of this Label_t.
 *
 * @param l the Label_t structure whose bbox is sought.
 *
 * @return the value of the "bbox" element of this Label_t as a BBox*.
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
const BBox_t*
Label_getBBox(const Label_t * l);


/**
 * Predicate returning @c 1 (true) if this Label_t's "bbox" element is set.
 *
 * @param l the Label_t structure.
 *
 * @return @c 1 (true) if this Label_t's "bbox" element has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_isSetBBox(const Label_t * l);


/**
 * Sets the value of the "bbox" element of this Label_t.
 *
 * @param l the Label_t structure.
 *
 * @param bbox BBox_t* value of the "bbox" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_setBBox(Label_t * l, const BBox_t* bbox);


/**
 * Creates a new BBox_t object, adds it to this Label_t object and returns the
 * BBox_t object created.
 *
 * @param l the Label_t structure to which the BBox_t should be added.
 *
 * @return a new BBox_t object instance.
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
BBox_t*
Label_createBBox(Label_t* l);


/**
 * Unsets the value of the "bbox" element of this Label_t.
 *
 * @param l the Label_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_unsetBBox(Label_t * l);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Label_t object have been set.
 *
 * @param l the Label_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Label_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the Label_t object are:
 * @li "text"
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_hasRequiredAttributes(const Label_t * l);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * Label_t object have been set.
 *
 * @param l the Label_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * Label_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the Label_t object are:
 *
 * @memberof Label_t
 */
LIBSBGN_EXTERN
int
Label_hasRequiredElements(const Label_t * l);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Label_H__ */


