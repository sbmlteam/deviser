/**
 * @file Point.h
 * @brief Definition of the Point class.
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
 * @class Point
 * @sbmlbrief{sbgnml} TODO:Definition of the Point class.
 */


#ifndef Point_H__
#define Point_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class SbgnListOfPoints;

class LIBSBGN_EXTERN Point : public SBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  double mX;
  bool mIsSetX;
  double mY;
  bool mIsSetY;
  SbgnListOfPoints * mPoints;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new Point using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this Point.
   *
   * @param version an unsigned int, the SBGN Version to assign to this Point.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Point(unsigned int level = SBGN_DEFAULT_LEVEL,
        unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new Point using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Point(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for Point.
   *
   * @param orig the Point instance to copy.
   */
  Point(const Point& orig);


  /**
   * Assignment operator for Point.
   *
   * @param rhs the Point object whose values are to be used as the basis of
   * the assignment.
   */
  Point& operator=(const Point& rhs);


  /**
   * Creates and returns a deep copy of this Point object.
   *
   * @return a (deep) copy of this Point object.
   */
  virtual Point* clone() const;


  /**
   * Destructor for Point.
   */
  virtual ~Point();


  /**
   * Returns the value of the "x" attribute of this Point.
   *
   * @return the value of the "x" attribute of this Point as a double.
   */
  double getX() const;


  /**
   * Returns the value of the "y" attribute of this Point.
   *
   * @return the value of the "y" attribute of this Point as a double.
   */
  double getY() const;


  /**
   * Predicate returning @c true if this Point's "x" attribute is set.
   *
   * @return @c true if this Point's "x" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetX() const;


  /**
   * Predicate returning @c true if this Point's "y" attribute is set.
   *
   * @return @c true if this Point's "y" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetY() const;


  /**
   * Sets the value of the "x" attribute of this Point.
   *
   * @param x double value of the "x" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setX(double x);


  /**
   * Sets the value of the "y" attribute of this Point.
   *
   * @param y double value of the "y" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setY(double y);


  /**
   * Unsets the value of the "x" attribute of this Point.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetX();


  /**
   * Unsets the value of the "y" attribute of this Point.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetY();


  /**
   * Returns the SbgnListOfPoints * from this Point.
   *
   * @return the SbgnListOfPoints * from this Point.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const Point* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  const SbgnListOfPoints * getListOfPoints() const;


  /**
   * Returns the SbgnListOfPoints * from this Point.
   *
   * @return the SbgnListOfPoints * from this Point.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const Point* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  SbgnListOfPoints * getListOfPoints();


  /**
   * Get a Point from the Point.
   *
   * @param n an unsigned int representing the index of the Point to retrieve.
   *
   * @return the nth Point in the SbgnListOfPoints * within this Point or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const Point* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  Point* getPoint(unsigned int n);


  /**
   * Get a Point from the Point.
   *
   * @param n an unsigned int representing the index of the Point to retrieve.
   *
   * @return the nth Point in the SbgnListOfPoints * within this Point or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const Point* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  const Point* getPoint(unsigned int n) const;


  /**
   * Adds a copy of the given Point to this Point.
   *
   * @param p1 the Point object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  int addPoint(const Point* p1);


  /**
   * Get the number of Point objects in this Point.
   *
   * @return the number of Point objects in this Point.
   *
   * @see addPoint(const Point* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  unsigned int getNumPoints() const;


  /**
   * Creates a new Point object, adds it to this Point object and returns the
   * Point object created.
   *
   * @return a new Point object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const Point* object)
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  Point* createPoint();


  /**
   * Removes the nth Point from this Point and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Point to remove.
   *
   * @return a pointer to the nth Point in this Point.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addPoint(const Point* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   */
  Point* removePoint(unsigned int n);


  /**
   * Returns the XML element name of this Point object.
   *
   * For Point, the XML element name is always @c "point".
   *
   * @return the name of this element, i.e. @c "point".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the XML name of this Point object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBGN type code for this Point object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_POINT, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Point
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Point
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Point object are:
   * @li "x"
   * @li "y"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this Point
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Point
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Point object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

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
   * Gets the value of the "attributeName" attribute of this Point.
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
   * Gets the value of the "attributeName" attribute of this Point.
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
   * Gets the value of the "attributeName" attribute of this Point.
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
   * Gets the value of the "attributeName" attribute of this Point.
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
   * Gets the value of the "attributeName" attribute of this Point.
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
   * Predicate returning @c true if this Point's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Point's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Point.
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
   * Sets the value of the "attributeName" attribute of this Point.
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
   * Sets the value of the "attributeName" attribute of this Point.
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
   * Sets the value of the "attributeName" attribute of this Point.
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
   * Sets the value of the "attributeName" attribute of this Point.
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
   * Unsets the value of the "attributeName" attribute of this Point.
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
   * Creates and returns an new "elementName" object in this Point.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this Point.
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
   * Point.
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
   * Returns the number of "elementName" in this Point.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this Point.
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
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Point_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this Point_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this Point_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
Point_t *
Point_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Point_t object.
 *
 * @param p the Point_t structure.
 *
 * @return a (deep) copy of this Point_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
Point_t*
Point_clone(const Point_t* p);


/**
 * Frees this Point_t object.
 *
 * @param p the Point_t structure.
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
void
Point_free(Point_t* p);


/**
 * Returns the value of the "x" attribute of this Point_t.
 *
 * @param p the Point_t structure whose x is sought.
 *
 * @return the value of the "x" attribute of this Point_t as a double.
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
double
Point_getX(const Point_t * p);


/**
 * Returns the value of the "y" attribute of this Point_t.
 *
 * @param p the Point_t structure whose y is sought.
 *
 * @return the value of the "y" attribute of this Point_t as a double.
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
double
Point_getY(const Point_t * p);


/**
 * Predicate returning @c 1 (true) if this Point_t's "x" attribute is set.
 *
 * @param p the Point_t structure.
 *
 * @return @c 1 (true) if this Point_t's "x" attribute has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_isSetX(const Point_t * p);


/**
 * Predicate returning @c 1 (true) if this Point_t's "y" attribute is set.
 *
 * @param p the Point_t structure.
 *
 * @return @c 1 (true) if this Point_t's "y" attribute has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_isSetY(const Point_t * p);


/**
 * Sets the value of the "x" attribute of this Point_t.
 *
 * @param p the Point_t structure.
 *
 * @param x double value of the "x" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_setX(Point_t * p, double x);


/**
 * Sets the value of the "y" attribute of this Point_t.
 *
 * @param p the Point_t structure.
 *
 * @param y double value of the "y" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_setY(Point_t * p, double y);


/**
 * Unsets the value of the "x" attribute of this Point_t.
 *
 * @param p the Point_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_unsetX(Point_t * p);


/**
 * Unsets the value of the "y" attribute of this Point_t.
 *
 * @param p the Point_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_unsetY(Point_t * p);


/**
 * Returns a ListOf_t * containing Point_t objects from this Point_t.
 *
 * @param p the Point_t structure whose SbgnListOfPoints * is sought.
 *
 * @return the SbgnListOfPoints * from this Point_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Point_addPoint()
 * @see Point_createPoint()
 * @see Point_getPointById()
 * @see Point_getPoint()
 * @see Point_getNumPoints()
 * @see Point_removePointById()
 * @see Point_removePoint()
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Point_getListOfPoints(Point_t* p);


/**
 * Get a Point_t from the Point_t.
 *
 * @param p the Point_t structure to search.
 *
 * @param n an unsigned int representing the index of the Point_t to retrieve.
 *
 * @return the nth Point_t in the SbgnListOfPoints * within this Point or
 * @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
Point_t*
Point_getPoint(Point_t* p, unsigned int n);


/**
 * Adds a copy of the given Point_t to this Point_t.
 *
 * @param p the Point_t structure to which the Point_t should be added.
 *
 * @param p1 the Point_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_addPoint(Point_t* p, const Point_t* p1);


/**
 * Get the number of Point_t objects in this Point_t.
 *
 * @param p the Point_t structure to query.
 *
 * @return the number of Point_t objects in this Point_t.
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
unsigned int
Point_getNumPoints(Point_t* p);


/**
 * Creates a new Point_t object, adds it to this Point_t object and returns the
 * Point_t object created.
 *
 * @param p the Point_t structure to which the Point_t should be added.
 *
 * @return a new Point_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
Point_t*
Point_createPoint(Point_t* p);


/**
 * Removes the nth Point_t from this Point_t and returns a pointer to it.
 *
 * @param p the Point_t structure to search.
 *
 * @param n an unsigned int representing the index of the Point_t to remove.
 *
 * @return a pointer to the nth Point_t in this Point_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
Point_t*
Point_removePoint(Point_t* p, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Point_t object have been set.
 *
 * @param p the Point_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Point_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the Point_t object are:
 * @li "x"
 * @li "y"
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_hasRequiredAttributes(const Point_t * p);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * Point_t object have been set.
 *
 * @param p the Point_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * Point_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the Point_t object are:
 *
 * @memberof Point_t
 */
LIBSBGN_EXTERN
int
Point_hasRequiredElements(const Point_t * p);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Point_H__ */


