/**
 * @file GraphicalPrimitive2D.h
 * @brief Definition of the GraphicalPrimitive2D class.
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
 * @class GraphicalPrimitive2D
 * @sbmlbrief{render} TODO:Definition of the GraphicalPrimitive2D class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_graphicalprimitive2d_fill-rule
 *
 * @par
 * The attribute "fill-rule" on a GraphicalPrimitive2D object is used to
 * TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Render specification, the following are the
 * allowable values for "fill-rule":
 * <ul>
 * <li> @c "nonzero", TODO:add description
 *
 * <li> @c "evenodd", TODO:add description
 *
 * </ul>
 */


#ifndef GraphicalPrimitive2D_H__
#define GraphicalPrimitive2D_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/render/common/renderfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/render/sbml/GraphicalPrimitive1D.h>
#include <sbml/packages/render/extension/RenderExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class Ellipse;
class Rectangle;
class Polygon;
class RenderGroup;

class LIBSBML_EXTERN GraphicalPrimitive2D : public GraphicalPrimitive1D
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mFill;
  FillRule_t mFillRule;

  /** @endcond */

public:

  /**
   * Creates a new GraphicalPrimitive2D using the given SBML Level, Version and
   * &ldquo;render&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * GraphicalPrimitive2D.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * GraphicalPrimitive2D.
   *
   * @param pkgVersion an unsigned int, the SBML Render Version to assign to
   * this GraphicalPrimitive2D.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  GraphicalPrimitive2D(unsigned int level = RenderExtension::getDefaultLevel(),
                       unsigned int version =
                         RenderExtension::getDefaultVersion(),
                       unsigned int pkgVersion =
                         RenderExtension::getDefaultPackageVersion());


  /**
   * Creates a new GraphicalPrimitive2D using the given RenderPkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param renderns the RenderPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  GraphicalPrimitive2D(RenderPkgNamespaces *renderns);


  /**
   * Copy constructor for GraphicalPrimitive2D.
   *
   * @param orig the GraphicalPrimitive2D instance to copy.
   */
  GraphicalPrimitive2D(const GraphicalPrimitive2D& orig);


  /**
   * Assignment operator for GraphicalPrimitive2D.
   *
   * @param rhs the GraphicalPrimitive2D object whose values are to be used as
   * the basis of the assignment.
   */
  GraphicalPrimitive2D& operator=(const GraphicalPrimitive2D& rhs);


  /**
   * Creates and returns a deep copy of this GraphicalPrimitive2D object.
   *
   * @return a (deep) copy of this GraphicalPrimitive2D object.
   */
  virtual GraphicalPrimitive2D* clone() const;


  /**
   * Destructor for GraphicalPrimitive2D.
   */
  virtual ~GraphicalPrimitive2D();


  /**
   * Returns the value of the "fill" attribute of this GraphicalPrimitive2D.
   *
   * @return the value of the "fill" attribute of this GraphicalPrimitive2D as
   * a string.
   */
  const std::string& getFill() const;


  /**
   * Returns the value of the "fill-rule" attribute of this
   * GraphicalPrimitive2D.
   *
   * @return the value of the "fill-rule" attribute of this
   * GraphicalPrimitive2D as a FillRule_t.
   *
   * @copydetails doc_graphicalprimitive2d_fill-rule
   * @if clike The value is drawn from the enumeration @ref FillRule_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{FILL_RULE_NONZERO, FillRule_t}
   * @li @sbmlconstant{FILL_RULE_EVENODD, FillRule_t}
   * @li @sbmlconstant{GRAPHICAL_PRIMITIVE2_D_FILL-RULE_INVALID, FillRule_t}
   */
  FillRule_t getFillRule() const;


  /**
   * Returns the value of the "fill-rule" attribute of this
   * GraphicalPrimitive2D.
   *
   * @return the value of the "fill-rule" attribute of this
   * GraphicalPrimitive2D as a string.
   *
   * @copydetails doc_graphicalprimitive2d_fill-rule
   * The possible values returned by this method are:
   * @li @c "nonzero"
   * @li @c "evenodd"
   * @li @c "invalid GraphicalPrimitive2DFill-rule"
   */
  std::string getFillRuleAsString() const;


  /**
   * Predicate returning @c true if this GraphicalPrimitive2D's "fill"
   * attribute is set.
   *
   * @return @c true if this GraphicalPrimitive2D's "fill" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetFill() const;


  /**
   * Predicate returning @c true if this GraphicalPrimitive2D's "fill-rule"
   * attribute is set.
   *
   * @return @c true if this GraphicalPrimitive2D's "fill-rule" attribute has
   * been set, otherwise @c false is returned.
   *
   * @copydetails doc_graphicalprimitive2d_fill-rule
   */
  bool isSetFillRule() const;


  /**
   * Sets the value of the "fill" attribute of this GraphicalPrimitive2D.
   *
   * @param fill std::string& value of the "fill" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p fill = @c NULL or an empty string is
   * equivalent to calling unsetFill().
   */
  int setFill(const std::string& fill);


  /**
   * Sets the value of the "fill-rule" attribute of this GraphicalPrimitive2D.
   *
   * @param fillRule @if clike FillRule_t@else int@endif value of the
   * "fill-rule" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_graphicalprimitive2d_fill-rule
   */
  int setFillRule(const FillRule_t fillRule);


  /**
   * Sets the value of the "fill-rule" attribute of this GraphicalPrimitive2D.
   *
   * @param fill-rule std::string& of the "fill-rule" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_graphicalprimitive2d_fill-rule
   */
  int setFillRule(const std::string& fillRule);


  /**
   * Unsets the value of the "fill" attribute of this GraphicalPrimitive2D.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFill();


  /**
   * Unsets the value of the "fill-rule" attribute of this
   * GraphicalPrimitive2D.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_graphicalprimitive2d_fill-rule
   */
  int unsetFillRule();


  /**
   * Predicate returning @c true if this abstract "GraphicalPrimitive2D" is of
   * type Ellipse
   *
   * @return @c true if this abstract "GraphicalPrimitive2D" is of type
   * Ellipse, @c false otherwise
   */
  virtual bool isEllipse() const;


  /**
   * Predicate returning @c true if this abstract "GraphicalPrimitive2D" is of
   * type Rectangle
   *
   * @return @c true if this abstract "GraphicalPrimitive2D" is of type
   * Rectangle, @c false otherwise
   */
  virtual bool isRectangle() const;


  /**
   * Predicate returning @c true if this abstract "GraphicalPrimitive2D" is of
   * type Polygon
   *
   * @return @c true if this abstract "GraphicalPrimitive2D" is of type
   * Polygon, @c false otherwise
   */
  virtual bool isPolygon() const;


  /**
   * Predicate returning @c true if this abstract "GraphicalPrimitive2D" is of
   * type RenderGroup
   *
   * @return @c true if this abstract "GraphicalPrimitive2D" is of type
   * RenderGroup, @c false otherwise
   */
  virtual bool isRenderGroup() const;


  /**
   * Returns the XML element name of this GraphicalPrimitive2D object.
   *
   * For GraphicalPrimitive2D, the XML element name is always
   * @c "graphicalPrimitive2D".
   *
   * @return the name of this element, i.e. @c "graphicalPrimitive2D".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this GraphicalPrimitive2D object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_RENDER_GRAPHICALPRIMITIVE2D, SBMLRenderTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * GraphicalPrimitive2D object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * GraphicalPrimitive2D have been set, otherwise @c false is returned.
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
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * Predicate returning @c true if this GraphicalPrimitive2D's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this GraphicalPrimitive2D's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
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
   * GraphicalPrimitive2D.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


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
 * Creates a new GraphicalPrimitive2D_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * GraphicalPrimitive2D_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * GraphicalPrimitive2D_t.
 *
 * @param pkgVersion an unsigned int, the SBML Render Version to assign to this
 * GraphicalPrimitive2D_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
GraphicalPrimitive2D_t *
GraphicalPrimitive2D_create(unsigned int level,
                            unsigned int version,
                            unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this GraphicalPrimitive2D_t object.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return a (deep) copy of this GraphicalPrimitive2D_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
GraphicalPrimitive2D_t*
GraphicalPrimitive2D_clone(const GraphicalPrimitive2D_t* gpd);


/**
 * Frees this GraphicalPrimitive2D_t object.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
void
GraphicalPrimitive2D_free(GraphicalPrimitive2D_t* gpd);


/**
 * Returns the value of the "fill" attribute of this GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure whose fill is sought.
 *
 * @return the value of the "fill" attribute of this GraphicalPrimitive2D_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
char *
GraphicalPrimitive2D_getFill(const GraphicalPrimitive2D_t * gpd);


/**
 * Returns the value of the "fill-rule" attribute of this
 * GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure whose fill-rule is sought.
 *
 * @return the value of the "fill-rule" attribute of this
 * GraphicalPrimitive2D_t as a FillRule_t.
 *
 * @copydetails doc_graphicalprimitive2d_fill-rule
 * @if clike The value is drawn from the enumeration @ref FillRule_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{FILL_RULE_NONZERO, FillRule_t}
 * @li @sbmlconstant{FILL_RULE_EVENODD, FillRule_t}
 * @li @sbmlconstant{GRAPHICAL_PRIMITIVE2_D_FILL-RULE_INVALID, FillRule_t}
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
FillRule_t
GraphicalPrimitive2D_getFillRule(const GraphicalPrimitive2D_t * gpd);


/**
 * Returns the value of the "fill-rule" attribute of this
 * GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure whose fill-rule is sought.
 *
 * @return the value of the "fill-rule" attribute of this
 * GraphicalPrimitive2D_t as a const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_graphicalprimitive2d_fill-rule
 * The possible values returned by this method are:
 * @li @c "nonzero"
 * @li @c "evenodd"
 * @li @c "invalid GraphicalPrimitive2DFill-rule"
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
char *
GraphicalPrimitive2D_getFillRuleAsString(const GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 (true) if this GraphicalPrimitive2D_t's "fill"
 * attribute is set.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 (true) if this GraphicalPrimitive2D_t's "fill" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_isSetFill(const GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 (true) if this GraphicalPrimitive2D_t's "fill-rule"
 * attribute is set.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 (true) if this GraphicalPrimitive2D_t's "fill-rule" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_graphicalprimitive2d_fill-rule
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_isSetFillRule(const GraphicalPrimitive2D_t * gpd);


/**
 * Sets the value of the "fill" attribute of this GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @param fill const char * value of the "fill" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p fill = @c NULL or an empty string is
 * equivalent to calling GraphicalPrimitive2D_unsetFill().
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_setFill(GraphicalPrimitive2D_t * gpd, const char * fill);


/**
 * Sets the value of the "fill-rule" attribute of this GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @param fillRule FillRule_t value of the "fill-rule" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_graphicalprimitive2d_fill-rule
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_setFillRule(GraphicalPrimitive2D_t * gpd,
                                 FillRule_t fillRule);


/**
 * Sets the value of the "fill-rule" attribute of this GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @param fill-rule const char * of the "fill-rule" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_graphicalprimitive2d_fill-rule
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_setFillRuleAsString(GraphicalPrimitive2D_t * gpd,
                                         const char * fillRule);


/**
 * Unsets the value of the "fill" attribute of this GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_unsetFill(GraphicalPrimitive2D_t * gpd);


/**
 * Unsets the value of the "fill-rule" attribute of this
 * GraphicalPrimitive2D_t.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_graphicalprimitive2d_fill-rule
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_unsetFillRule(GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 if this GraphicalPrimitive2D_t is of type Ellipse_t
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 if this GraphicalPrimitive2D_t is of type Ellipse_t, @c 0
 * otherwise
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_isEllipse(const GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 if this GraphicalPrimitive2D_t is of type
 * Rectangle_t
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 if this GraphicalPrimitive2D_t is of type Rectangle_t, @c 0
 * otherwise
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_isRectangle(const GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 if this GraphicalPrimitive2D_t is of type Polygon_t
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 if this GraphicalPrimitive2D_t is of type Polygon_t, @c 0
 * otherwise
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_isPolygon(const GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 if this GraphicalPrimitive2D_t is of type
 * RenderGroup_t
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 if this GraphicalPrimitive2D_t is of type RenderGroup_t, @c 0
 * otherwise
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_isRenderGroup(const GraphicalPrimitive2D_t * gpd);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * GraphicalPrimitive2D_t object have been set.
 *
 * @param gpd the GraphicalPrimitive2D_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * GraphicalPrimitive2D_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof GraphicalPrimitive2D_t
 */
LIBSBML_EXTERN
int
GraphicalPrimitive2D_hasRequiredAttributes(const GraphicalPrimitive2D_t * gpd);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !GraphicalPrimitive2D_H__ */


