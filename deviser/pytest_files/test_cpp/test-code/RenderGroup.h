/**
 * @file RenderGroup.h
 * @brief Definition of the RenderGroup class.
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
 * @class RenderGroup
 * @sbmlbrief{render} TODO:Definition of the RenderGroup class.
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
 * @class doc_rendergroup_font-weight
 *
 * @par
 * The attribute "font-weight" on a RenderGroup object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Render specification, the following are the
 * allowable values for "font-weight":
 * <ul>
 * <li> @c "bold", TODO:add description
 *
 * <li> @c "normal", TODO:add description
 *
 * </ul>
 *
 * @class doc_rendergroup_font-style
 *
 * @par
 * The attribute "font-style" on a RenderGroup object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Render specification, the following are the
 * allowable values for "font-style":
 * <ul>
 * <li> @c "italic", TODO:add description
 *
 * <li> @c "normal", TODO:add description
 *
 * </ul>
 *
 * @class doc_rendergroup_text-anchor
 *
 * @par
 * The attribute "text-anchor" on a RenderGroup object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Render specification, the following are the
 * allowable values for "text-anchor":
 * <ul>
 * <li> @c "start", TODO:add description
 *
 * <li> @c "middle", TODO:add description
 *
 * <li> @c "end", TODO:add description
 *
 * </ul>
 *
 * @class doc_rendergroup_vtext-anchor
 *
 * @par
 * The attribute "vtext-anchor" on a RenderGroup object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Render specification, the following are the
 * allowable values for "vtext-anchor":
 * <ul>
 * <li> @c "top", TODO:add description
 *
 * <li> @c "middle", TODO:add description
 *
 * <li> @c "bottom", TODO:add description
 *
 * <li> @c "baseline", TODO:add description
 *
 * </ul>
 */


#ifndef RenderGroup_H__
#define RenderGroup_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/render/common/renderfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/render/sbml/GraphicalPrimitive2D.h>
#include <sbml/packages/render/extension/RenderExtension.h>
#include <sbml/packages/render/sbml/RelAbsVector.h>
#include <sbml/packages/render/sbml/ListOfDrawables.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN RenderGroup : public GraphicalPrimitive2D
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mStartHead;
  std::string mEndHead;
  std::string mFontFamily;
  FontWeight_t mFontWeight;
  FontStyle_t mFontStyle;
  HTextAnchor_t mTextAnchor;
  VTextAnchor_t mVtextAnchor;
  RelAbsVector* mFontSize;
  ListOfDrawables mTransformation2Ds;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new RenderGroup using the given SBML Level, Version and
   * &ldquo;render&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * RenderGroup.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * RenderGroup.
   *
   * @param pkgVersion an unsigned int, the SBML Render Version to assign to
   * this RenderGroup.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  RenderGroup(unsigned int level = RenderExtension::getDefaultLevel(),
              unsigned int version = RenderExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                RenderExtension::getDefaultPackageVersion());


  /**
   * Creates a new RenderGroup using the given RenderPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param renderns the RenderPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  RenderGroup(RenderPkgNamespaces *renderns);


  /**
   * Copy constructor for RenderGroup.
   *
   * @param orig the RenderGroup instance to copy.
   */
  RenderGroup(const RenderGroup& orig);


  /**
   * Assignment operator for RenderGroup.
   *
   * @param rhs the RenderGroup object whose values are to be used as the basis
   * of the assignment.
   */
  RenderGroup& operator=(const RenderGroup& rhs);


  /**
   * Creates and returns a deep copy of this RenderGroup object.
   *
   * @return a (deep) copy of this RenderGroup object.
   */
  virtual RenderGroup* clone() const;


  /**
   * Destructor for RenderGroup.
   */
  virtual ~RenderGroup();


  /**
   * Returns the value of the "startHead" attribute of this RenderGroup.
   *
   * @return the value of the "startHead" attribute of this RenderGroup as a
   * string.
   */
  const std::string& getStartHead() const;


  /**
   * Returns the value of the "endHead" attribute of this RenderGroup.
   *
   * @return the value of the "endHead" attribute of this RenderGroup as a
   * string.
   */
  const std::string& getEndHead() const;


  /**
   * Returns the value of the "font-family" attribute of this RenderGroup.
   *
   * @return the value of the "font-family" attribute of this RenderGroup as a
   * string.
   */
  const std::string& getFontFamily() const;


  /**
   * Returns the value of the "font-weight" attribute of this RenderGroup.
   *
   * @return the value of the "font-weight" attribute of this RenderGroup as a
   * FontWeight_t.
   *
   * @copydetails doc_rendergroup_font-weight
   * @if clike The value is drawn from the enumeration @ref FontWeight_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{FONT_WEIGHT_BOLD, FontWeight_t}
   * @li @sbmlconstant{FONT_WEIGHT_NORMAL, FontWeight_t}
   * @li @sbmlconstant{FONT_WEIGHT_NORMAL_INVALID, FontWeight_t}
   */
  FontWeight_t getFontWeight() const;


  /**
   * Returns the value of the "font-weight" attribute of this RenderGroup.
   *
   * @return the value of the "font-weight" attribute of this RenderGroup as a
   * string.
   *
   * @copydetails doc_rendergroup_font-weight
   * The possible values returned by this method are:
   * @li @c "bold"
   * @li @c "normal"
   * @li @c "invalid FontWeight value"
   */
  std::string getFontWeightAsString() const;


  /**
   * Returns the value of the "font-style" attribute of this RenderGroup.
   *
   * @return the value of the "font-style" attribute of this RenderGroup as a
   * FontStyle_t.
   *
   * @copydetails doc_rendergroup_font-style
   * @if clike The value is drawn from the enumeration @ref FontStyle_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{FONT_STYLE_ITALIC, FontStyle_t}
   * @li @sbmlconstant{FONT_STYLE_NORMAL, FontStyle_t}
   * @li @sbmlconstant{FONT_STYLE_NORMAL_INVALID, FontStyle_t}
   */
  FontStyle_t getFontStyle() const;


  /**
   * Returns the value of the "font-style" attribute of this RenderGroup.
   *
   * @return the value of the "font-style" attribute of this RenderGroup as a
   * string.
   *
   * @copydetails doc_rendergroup_font-style
   * The possible values returned by this method are:
   * @li @c "italic"
   * @li @c "normal"
   * @li @c "invalid FontStyle value"
   */
  std::string getFontStyleAsString() const;


  /**
   * Returns the value of the "text-anchor" attribute of this RenderGroup.
   *
   * @return the value of the "text-anchor" attribute of this RenderGroup as a
   * HTextAnchor_t.
   *
   * @copydetails doc_rendergroup_text-anchor
   * @if clike The value is drawn from the enumeration @ref HTextAnchor_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{H_TEXTANCHOR_START, HTextAnchor_t}
   * @li @sbmlconstant{H_TEXTANCHOR_MIDDLE, HTextAnchor_t}
   * @li @sbmlconstant{H_TEXTANCHOR_END, HTextAnchor_t}
   * @li @sbmlconstant{H_END_INVALID, HTextAnchor_t}
   */
  HTextAnchor_t getTextAnchor() const;


  /**
   * Returns the value of the "text-anchor" attribute of this RenderGroup.
   *
   * @return the value of the "text-anchor" attribute of this RenderGroup as a
   * string.
   *
   * @copydetails doc_rendergroup_text-anchor
   * The possible values returned by this method are:
   * @li @c "start"
   * @li @c "middle"
   * @li @c "end"
   * @li @c "invalid HTextAnchor value"
   */
  std::string getTextAnchorAsString() const;


  /**
   * Returns the value of the "vtext-anchor" attribute of this RenderGroup.
   *
   * @return the value of the "vtext-anchor" attribute of this RenderGroup as a
   * VTextAnchor_t.
   *
   * @copydetails doc_rendergroup_vtext-anchor
   * @if clike The value is drawn from the enumeration @ref VTextAnchor_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_TOP, VTextAnchor_t}
   * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_MIDDLE, VTextAnchor_t}
   * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_BOTTOM, VTextAnchor_t}
   * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_BASELINE, VTextAnchor_t}
   * @li @sbmlconstant{V_ANCHOR_BASELINE_INVALID, VTextAnchor_t}
   */
  VTextAnchor_t getVtextAnchor() const;


  /**
   * Returns the value of the "vtext-anchor" attribute of this RenderGroup.
   *
   * @return the value of the "vtext-anchor" attribute of this RenderGroup as a
   * string.
   *
   * @copydetails doc_rendergroup_vtext-anchor
   * The possible values returned by this method are:
   * @li @c "top"
   * @li @c "middle"
   * @li @c "bottom"
   * @li @c "baseline"
   * @li @c "invalid VTextAnchor value"
   */
  std::string getVtextAnchorAsString() const;


  /**
   * Predicate returning @c true if this RenderGroup's "startHead" attribute is
   * set.
   *
   * @return @c true if this RenderGroup's "startHead" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStartHead() const;


  /**
   * Predicate returning @c true if this RenderGroup's "endHead" attribute is
   * set.
   *
   * @return @c true if this RenderGroup's "endHead" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetEndHead() const;


  /**
   * Predicate returning @c true if this RenderGroup's "font-family" attribute
   * is set.
   *
   * @return @c true if this RenderGroup's "font-family" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetFontFamily() const;


  /**
   * Predicate returning @c true if this RenderGroup's "font-weight" attribute
   * is set.
   *
   * @return @c true if this RenderGroup's "font-weight" attribute has been
   * set, otherwise @c false is returned.
   *
   * @copydetails doc_rendergroup_font-weight
   */
  bool isSetFontWeight() const;


  /**
   * Predicate returning @c true if this RenderGroup's "font-style" attribute
   * is set.
   *
   * @return @c true if this RenderGroup's "font-style" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_rendergroup_font-style
   */
  bool isSetFontStyle() const;


  /**
   * Predicate returning @c true if this RenderGroup's "text-anchor" attribute
   * is set.
   *
   * @return @c true if this RenderGroup's "text-anchor" attribute has been
   * set, otherwise @c false is returned.
   *
   * @copydetails doc_rendergroup_text-anchor
   */
  bool isSetTextAnchor() const;


  /**
   * Predicate returning @c true if this RenderGroup's "vtext-anchor" attribute
   * is set.
   *
   * @return @c true if this RenderGroup's "vtext-anchor" attribute has been
   * set, otherwise @c false is returned.
   *
   * @copydetails doc_rendergroup_vtext-anchor
   */
  bool isSetVtextAnchor() const;


  /**
   * Sets the value of the "startHead" attribute of this RenderGroup.
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
   * Sets the value of the "endHead" attribute of this RenderGroup.
   *
   * @param endHead std::string& value of the "endHead" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setEndHead(const std::string& endHead);


  /**
   * Sets the value of the "font-family" attribute of this RenderGroup.
   *
   * @param fontFamily std::string& value of the "font-family" attribute to be
   * set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p fontFamily = @c NULL or an empty string is
   * equivalent to calling unsetFontFamily().
   */
  int setFontFamily(const std::string& fontFamily);


  /**
   * Sets the value of the "font-weight" attribute of this RenderGroup.
   *
   * @param fontWeight @if clike FontWeight_t@else int@endif value of the
   * "font-weight" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_font-weight
   */
  int setFontWeight(const FontWeight_t fontWeight);


  /**
   * Sets the value of the "font-weight" attribute of this RenderGroup.
   *
   * @param fontWeight std::string& of the "font-weight" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_font-weight
   */
  int setFontWeight(const std::string& fontWeight);


  /**
   * Sets the value of the "font-style" attribute of this RenderGroup.
   *
   * @param fontStyle @if clike FontStyle_t@else int@endif value of the
   * "font-style" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_font-style
   */
  int setFontStyle(const FontStyle_t fontStyle);


  /**
   * Sets the value of the "font-style" attribute of this RenderGroup.
   *
   * @param fontStyle std::string& of the "font-style" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_font-style
   */
  int setFontStyle(const std::string& fontStyle);


  /**
   * Sets the value of the "text-anchor" attribute of this RenderGroup.
   *
   * @param textAnchor @if clike HTextAnchor_t@else int@endif value of the
   * "text-anchor" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_text-anchor
   */
  int setTextAnchor(const HTextAnchor_t textAnchor);


  /**
   * Sets the value of the "text-anchor" attribute of this RenderGroup.
   *
   * @param textAnchor std::string& of the "text-anchor" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_text-anchor
   */
  int setTextAnchor(const std::string& textAnchor);


  /**
   * Sets the value of the "vtext-anchor" attribute of this RenderGroup.
   *
   * @param vtextAnchor @if clike VTextAnchor_t@else int@endif value of the
   * "vtext-anchor" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_vtext-anchor
   */
  int setVtextAnchor(const VTextAnchor_t vtextAnchor);


  /**
   * Sets the value of the "vtext-anchor" attribute of this RenderGroup.
   *
   * @param vtextAnchor std::string& of the "vtext-anchor" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_vtext-anchor
   */
  int setVtextAnchor(const std::string& vtextAnchor);


  /**
   * Unsets the value of the "startHead" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStartHead();


  /**
   * Unsets the value of the "endHead" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetEndHead();


  /**
   * Unsets the value of the "font-family" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFontFamily();


  /**
   * Unsets the value of the "font-weight" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_font-weight
   */
  int unsetFontWeight();


  /**
   * Unsets the value of the "font-style" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_font-style
   */
  int unsetFontStyle();


  /**
   * Unsets the value of the "text-anchor" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_text-anchor
   */
  int unsetTextAnchor();


  /**
   * Unsets the value of the "vtext-anchor" attribute of this RenderGroup.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_rendergroup_vtext-anchor
   */
  int unsetVtextAnchor();


  /**
   * Returns the value of the "font-size" element of this RenderGroup.
   *
   * @return the value of the "font-size" element of this RenderGroup as a
   * RelAbsVector*.
   */
  const RelAbsVector* getFontSize() const;


  /**
   * Returns the value of the "font-size" element of this RenderGroup.
   *
   * @return the value of the "font-size" element of this RenderGroup as a
   * RelAbsVector*.
   */
  RelAbsVector* getFontSize();


  /**
   * Predicate returning @c true if this RenderGroup's "font-size" element is
   * set.
   *
   * @return @c true if this RenderGroup's "font-size" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetFontSize() const;


  /**
   * Sets the value of the "font-size" element of this RenderGroup.
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
   * Creates a new RelAbsVector object, adds it to this RenderGroup object and
   * returns the RelAbsVector object created.
   *
   * @return a new RelAbsVector object instance.
   */
  RelAbsVector* createFontSize();


  /**
   * Unsets the value of the "font-size" element of this RenderGroup.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFontSize();


  /**
   * Returns the ListOfDrawables from this RenderGroup.
   *
   * @return the ListOfDrawables from this RenderGroup.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  const ListOfDrawables* getListOfElements() const;


  /**
   * Returns the ListOfDrawables from this RenderGroup.
   *
   * @return the ListOfDrawables from this RenderGroup.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  ListOfDrawables* getListOfElements();


  /**
   * Get a Transformation2D from the RenderGroup.
   *
   * @param n an unsigned int representing the index of the Transformation2D to
   * retrieve.
   *
   * @return the nth Transformation2D in the ListOfDrawables within this
   * RenderGroup or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  Transformation2D* getElement(unsigned int n);


  /**
   * Get a Transformation2D from the RenderGroup.
   *
   * @param n an unsigned int representing the index of the Transformation2D to
   * retrieve.
   *
   * @return the nth Transformation2D in the ListOfDrawables within this
   * RenderGroup or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  const Transformation2D* getElement(unsigned int n) const;


  /**
   * Adds a copy of the given Transformation2D to this RenderGroup.
   *
   * @param td the Transformation2D object to add.
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
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  int addElement(const Transformation2D* td);


  /**
   * Get the number of Transformation2D objects in this RenderGroup.
   *
   * @return the number of Transformation2D objects in this RenderGroup.
   *
   * @see addElement(const Transformation2D* object)
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  unsigned int getNumElements() const;


  /**
   * Creates a new Image object, adds it to this RenderGroup object and returns
   * the Image object created.
   *
   * @return a new Image object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  Image* createImage();


  /**
   * Creates a new Ellipse object, adds it to this RenderGroup object and
   * returns the Ellipse object created.
   *
   * @return a new Ellipse object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  Ellipse* createEllipse();


  /**
   * Creates a new Rectangle object, adds it to this RenderGroup object and
   * returns the Rectangle object created.
   *
   * @return a new Rectangle object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  Rectangle* createRectangle();


  /**
   * Creates a new Polygon object, adds it to this RenderGroup object and
   * returns the Polygon object created.
   *
   * @return a new Polygon object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  Polygon* createPolygon();


  /**
   * Creates a new RenderGroup object, adds it to this RenderGroup object and
   * returns the RenderGroup object created.
   *
   * @return a new RenderGroup object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  RenderGroup* createGroup();


  /**
   * Creates a new Text object, adds it to this RenderGroup object and returns
   * the Text object created.
   *
   * @return a new Text object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  Text* createText();


  /**
   * Creates a new RenderCurve object, adds it to this RenderGroup object and
   * returns the RenderCurve object created.
   *
   * @return a new RenderCurve object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   * @see removeElement(unsigned int n)
   */
  RenderCurve* createCurve();


  /**
   * Removes the nth Transformation2D from this RenderGroup and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the Transformation2D to
   * remove.
   *
   * @return a pointer to the nth Transformation2D in this RenderGroup.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addElement(const Transformation2D* object)
   * @see createElement()
   * @see getElement(const std::string& sid)
   * @see getElement(unsigned int n)
   * @see getNumElements()
   * @see removeElement(const std::string& sid)
   */
  Transformation2D* removeElement(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this RenderGroup object.
   *
   * For RenderGroup, the XML element name is always @c "g".
   *
   * @return the name of this element, i.e. @c "g".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the XML name of this RenderGroup object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBML type code for this RenderGroup object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_RENDER_GROUP, SBMLRenderTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * RenderGroup object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * RenderGroup have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * RenderGroup object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * RenderGroup have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the RenderGroup object are:
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
   * Gets the value of the "attributeName" attribute of this RenderGroup.
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
   * Gets the value of the "attributeName" attribute of this RenderGroup.
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
   * Gets the value of the "attributeName" attribute of this RenderGroup.
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
   * Gets the value of the "attributeName" attribute of this RenderGroup.
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
   * Gets the value of the "attributeName" attribute of this RenderGroup.
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
   * Predicate returning @c true if this RenderGroup's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this RenderGroup's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this RenderGroup.
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
   * Sets the value of the "attributeName" attribute of this RenderGroup.
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
   * Sets the value of the "attributeName" attribute of this RenderGroup.
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
   * Sets the value of the "attributeName" attribute of this RenderGroup.
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
   * Sets the value of the "attributeName" attribute of this RenderGroup.
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
   * Unsets the value of the "attributeName" attribute of this RenderGroup.
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
   * Creates and returns an new "elementName" object in this RenderGroup.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this RenderGroup.
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
   * RenderGroup.
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
   * Returns the number of "elementName" in this RenderGroup.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this RenderGroup.
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
 * Creates a new RenderGroup_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * RenderGroup_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * RenderGroup_t.
 *
 * @param pkgVersion an unsigned int, the SBML Render Version to assign to this
 * RenderGroup_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
RenderGroup_t *
RenderGroup_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this RenderGroup_t object.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return a (deep) copy of this RenderGroup_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
RenderGroup_t*
RenderGroup_clone(const RenderGroup_t* rg);


/**
 * Frees this RenderGroup_t object.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
void
RenderGroup_free(RenderGroup_t* rg);


/**
 * Returns the value of the "startHead" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose startHead is sought.
 *
 * @return the value of the "startHead" attribute of this RenderGroup_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getStartHead(const RenderGroup_t * rg);


/**
 * Returns the value of the "endHead" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose endHead is sought.
 *
 * @return the value of the "endHead" attribute of this RenderGroup_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getEndHead(const RenderGroup_t * rg);


/**
 * Returns the value of the "font-family" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose font-family is sought.
 *
 * @return the value of the "font-family" attribute of this RenderGroup_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getFontFamily(const RenderGroup_t * rg);


/**
 * Returns the value of the "font-weight" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose font-weight is sought.
 *
 * @return the value of the "font-weight" attribute of this RenderGroup_t as a
 * FontWeight_t.
 *
 * @copydetails doc_rendergroup_font-weight
 * @if clike The value is drawn from the enumeration @ref FontWeight_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{FONT_WEIGHT_BOLD, FontWeight_t}
 * @li @sbmlconstant{FONT_WEIGHT_NORMAL, FontWeight_t}
 * @li @sbmlconstant{FONT_WEIGHT_NORMAL_INVALID, FontWeight_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
FontWeight_t
RenderGroup_getFontWeight(const RenderGroup_t * rg);


/**
 * Returns the value of the "font-weight" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose font-weight is sought.
 *
 * @return the value of the "font-weight" attribute of this RenderGroup_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_rendergroup_font-weight
 * The possible values returned by this method are:
 * @li @c "bold"
 * @li @c "normal"
 * @li @c "invalid FontWeight value"
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getFontWeightAsString(const RenderGroup_t * rg);


/**
 * Returns the value of the "font-style" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose font-style is sought.
 *
 * @return the value of the "font-style" attribute of this RenderGroup_t as a
 * FontStyle_t.
 *
 * @copydetails doc_rendergroup_font-style
 * @if clike The value is drawn from the enumeration @ref FontStyle_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{FONT_STYLE_ITALIC, FontStyle_t}
 * @li @sbmlconstant{FONT_STYLE_NORMAL, FontStyle_t}
 * @li @sbmlconstant{FONT_STYLE_NORMAL_INVALID, FontStyle_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
FontStyle_t
RenderGroup_getFontStyle(const RenderGroup_t * rg);


/**
 * Returns the value of the "font-style" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose font-style is sought.
 *
 * @return the value of the "font-style" attribute of this RenderGroup_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_rendergroup_font-style
 * The possible values returned by this method are:
 * @li @c "italic"
 * @li @c "normal"
 * @li @c "invalid FontStyle value"
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getFontStyleAsString(const RenderGroup_t * rg);


/**
 * Returns the value of the "text-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose text-anchor is sought.
 *
 * @return the value of the "text-anchor" attribute of this RenderGroup_t as a
 * HTextAnchor_t.
 *
 * @copydetails doc_rendergroup_text-anchor
 * @if clike The value is drawn from the enumeration @ref HTextAnchor_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{H_TEXTANCHOR_START, HTextAnchor_t}
 * @li @sbmlconstant{H_TEXTANCHOR_MIDDLE, HTextAnchor_t}
 * @li @sbmlconstant{H_TEXTANCHOR_END, HTextAnchor_t}
 * @li @sbmlconstant{H_END_INVALID, HTextAnchor_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
HTextAnchor_t
RenderGroup_getTextAnchor(const RenderGroup_t * rg);


/**
 * Returns the value of the "text-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose text-anchor is sought.
 *
 * @return the value of the "text-anchor" attribute of this RenderGroup_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_rendergroup_text-anchor
 * The possible values returned by this method are:
 * @li @c "start"
 * @li @c "middle"
 * @li @c "end"
 * @li @c "invalid HTextAnchor value"
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getTextAnchorAsString(const RenderGroup_t * rg);


/**
 * Returns the value of the "vtext-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose vtext-anchor is sought.
 *
 * @return the value of the "vtext-anchor" attribute of this RenderGroup_t as a
 * VTextAnchor_t.
 *
 * @copydetails doc_rendergroup_vtext-anchor
 * @if clike The value is drawn from the enumeration @ref VTextAnchor_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_TOP, VTextAnchor_t}
 * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_MIDDLE, VTextAnchor_t}
 * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_BOTTOM, VTextAnchor_t}
 * @li @sbmlconstant{V_TEXTANCHOR_ANCHOR_BASELINE, VTextAnchor_t}
 * @li @sbmlconstant{V_ANCHOR_BASELINE_INVALID, VTextAnchor_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
VTextAnchor_t
RenderGroup_getVtextAnchor(const RenderGroup_t * rg);


/**
 * Returns the value of the "vtext-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose vtext-anchor is sought.
 *
 * @return the value of the "vtext-anchor" attribute of this RenderGroup_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_rendergroup_vtext-anchor
 * The possible values returned by this method are:
 * @li @c "top"
 * @li @c "middle"
 * @li @c "bottom"
 * @li @c "baseline"
 * @li @c "invalid VTextAnchor value"
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
char *
RenderGroup_getVtextAnchorAsString(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "startHead"
 * attribute is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "startHead" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetStartHead(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "endHead" attribute
 * is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "endHead" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetEndHead(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-family"
 * attribute is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "font-family" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontFamily(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-weight"
 * attribute is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "font-weight" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_rendergroup_font-weight
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontWeight(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-style"
 * attribute is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "font-style" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_rendergroup_font-style
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontStyle(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "text-anchor"
 * attribute is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "text-anchor" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_rendergroup_text-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetTextAnchor(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "vtext-anchor"
 * attribute is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "vtext-anchor" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_rendergroup_vtext-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetVtextAnchor(const RenderGroup_t * rg);


/**
 * Sets the value of the "startHead" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param startHead const char * value of the "startHead" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setStartHead(RenderGroup_t * rg, const char * startHead);


/**
 * Sets the value of the "endHead" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param endHead const char * value of the "endHead" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setEndHead(RenderGroup_t * rg, const char * endHead);


/**
 * Sets the value of the "font-family" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param fontFamily const char * value of the "font-family" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p fontFamily = @c NULL or an empty string is
 * equivalent to calling RenderGroup_unsetFontFamily().
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setFontFamily(RenderGroup_t * rg, const char * fontFamily);


/**
 * Sets the value of the "font-weight" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param fontWeight FontWeight_t value of the "font-weight" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_font-weight
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setFontWeight(RenderGroup_t * rg, FontWeight_t fontWeight);


/**
 * Sets the value of the "font-weight" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param fontWeight const char * of the "font-weight" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_font-weight
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setFontWeightAsString(RenderGroup_t * rg,
                                  const char * fontWeight);


/**
 * Sets the value of the "font-style" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param fontStyle FontStyle_t value of the "font-style" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_font-style
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setFontStyle(RenderGroup_t * rg, FontStyle_t fontStyle);


/**
 * Sets the value of the "font-style" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param fontStyle const char * of the "font-style" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_font-style
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setFontStyleAsString(RenderGroup_t * rg, const char * fontStyle);


/**
 * Sets the value of the "text-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param textAnchor HTextAnchor_t value of the "text-anchor" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_text-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setTextAnchor(RenderGroup_t * rg, HTextAnchor_t textAnchor);


/**
 * Sets the value of the "text-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param textAnchor const char * of the "text-anchor" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_text-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setTextAnchorAsString(RenderGroup_t * rg,
                                  const char * textAnchor);


/**
 * Sets the value of the "vtext-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param vtextAnchor VTextAnchor_t value of the "vtext-anchor" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_vtext-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setVtextAnchor(RenderGroup_t * rg, VTextAnchor_t vtextAnchor);


/**
 * Sets the value of the "vtext-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param vtextAnchor const char * of the "vtext-anchor" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_vtext-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setVtextAnchorAsString(RenderGroup_t * rg,
                                   const char * vtextAnchor);


/**
 * Unsets the value of the "startHead" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetStartHead(RenderGroup_t * rg);


/**
 * Unsets the value of the "endHead" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetEndHead(RenderGroup_t * rg);


/**
 * Unsets the value of the "font-family" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontFamily(RenderGroup_t * rg);


/**
 * Unsets the value of the "font-weight" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_font-weight
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontWeight(RenderGroup_t * rg);


/**
 * Unsets the value of the "font-style" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_font-style
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontStyle(RenderGroup_t * rg);


/**
 * Unsets the value of the "text-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_text-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetTextAnchor(RenderGroup_t * rg);


/**
 * Unsets the value of the "vtext-anchor" attribute of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_rendergroup_vtext-anchor
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetVtextAnchor(RenderGroup_t * rg);


/**
 * Returns the value of the "font-size" element of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose font-size is sought.
 *
 * @return the value of the "font-size" element of this RenderGroup_t as a
 * RelAbsVector*.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
const RelAbsVector_t*
RenderGroup_getFontSize(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-size" element
 * is set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) if this RenderGroup_t's "font-size" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontSize(const RenderGroup_t * rg);


/**
 * Sets the value of the "font-size" element of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @param fontSize RelAbsVector_t* value of the "font-size" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_setFontSize(RenderGroup_t * rg, const RelAbsVector_t* fontSize);


/**
 * Creates a new RelAbsVector_t object, adds it to this RenderGroup_t object
 * and returns the RelAbsVector_t object created.
 *
 * @param rg the RenderGroup_t structure to which the RelAbsVector_t should be
 * added.
 *
 * @return a new RelAbsVector_t object instance.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
RelAbsVector_t*
RenderGroup_createFontSize(RenderGroup_t* rg);


/**
 * Unsets the value of the "font-size" element of this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontSize(RenderGroup_t * rg);


/**
 * Returns a ListOf_t * containing Transformation2D_t objects from this
 * RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure whose ListOfDrawables is sought.
 *
 * @return the ListOfDrawables from this RenderGroup_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see RenderGroup_addElement()
 * @see RenderGroup_createElement()
 * @see RenderGroup_getElementById()
 * @see RenderGroup_getElement()
 * @see RenderGroup_getNumElements()
 * @see RenderGroup_removeElementById()
 * @see RenderGroup_removeElement()
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
ListOf_t*
RenderGroup_getListOfElements(RenderGroup_t* rg);


/**
 * Get a Transformation2D_t from the RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure to search.
 *
 * @param n an unsigned int representing the index of the Transformation2D_t to
 * retrieve.
 *
 * @return the nth Transformation2D_t in the ListOfDrawables within this
 * RenderGroup or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Transformation2D_t*
RenderGroup_getElement(RenderGroup_t* rg, unsigned int n);


/**
 * Adds a copy of the given Transformation2D_t to this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure to which the Transformation2D_t should
 * be added.
 *
 * @param td the Transformation2D_t object to add.
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
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_addElement(RenderGroup_t* rg, const Transformation2D_t* td);


/**
 * Get the number of Transformation2D_t objects in this RenderGroup_t.
 *
 * @param rg the RenderGroup_t structure to query.
 *
 * @return the number of Transformation2D_t objects in this RenderGroup_t.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
unsigned int
RenderGroup_getNumElements(RenderGroup_t* rg);


/**
 * Creates a new Image_t object, adds it to this RenderGroup_t object and
 * returns the Image_t object created.
 *
 * @param rg the RenderGroup_t structure to which the Image_t should be added.
 *
 * @return a new Image_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Image_t*
RenderGroup_createImage(RenderGroup_t* rg);


/**
 * Creates a new Ellipse_t object, adds it to this RenderGroup_t object and
 * returns the Ellipse_t object created.
 *
 * @param rg the RenderGroup_t structure to which the Ellipse_t should be
 * added.
 *
 * @return a new Ellipse_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Ellipse_t*
RenderGroup_createEllipse(RenderGroup_t* rg);


/**
 * Creates a new Rectangle_t object, adds it to this RenderGroup_t object and
 * returns the Rectangle_t object created.
 *
 * @param rg the RenderGroup_t structure to which the Rectangle_t should be
 * added.
 *
 * @return a new Rectangle_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Rectangle_t*
RenderGroup_createRectangle(RenderGroup_t* rg);


/**
 * Creates a new Polygon_t object, adds it to this RenderGroup_t object and
 * returns the Polygon_t object created.
 *
 * @param rg the RenderGroup_t structure to which the Polygon_t should be
 * added.
 *
 * @return a new Polygon_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Polygon_t*
RenderGroup_createPolygon(RenderGroup_t* rg);


/**
 * Creates a new RenderGroup_t object, adds it to this RenderGroup_t object and
 * returns the RenderGroup_t object created.
 *
 * @param rg the RenderGroup_t structure to which the RenderGroup_t should be
 * added.
 *
 * @return a new RenderGroup_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
RenderGroup_t*
RenderGroup_createGroup(RenderGroup_t* rg);


/**
 * Creates a new Text_t object, adds it to this RenderGroup_t object and
 * returns the Text_t object created.
 *
 * @param rg the RenderGroup_t structure to which the Text_t should be added.
 *
 * @return a new Text_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Text_t*
RenderGroup_createText(RenderGroup_t* rg);


/**
 * Creates a new RenderCurve_t object, adds it to this RenderGroup_t object and
 * returns the RenderCurve_t object created.
 *
 * @param rg the RenderGroup_t structure to which the RenderCurve_t should be
 * added.
 *
 * @return a new RenderCurve_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
RenderCurve_t*
RenderGroup_createCurve(RenderGroup_t* rg);


/**
 * Removes the nth Transformation2D_t from this RenderGroup_t and returns a
 * pointer to it.
 *
 * @param rg the RenderGroup_t structure to search.
 *
 * @param n an unsigned int representing the index of the Transformation2D_t to
 * remove.
 *
 * @return a pointer to the nth Transformation2D_t in this RenderGroup_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
Transformation2D_t*
RenderGroup_removeElement(RenderGroup_t* rg, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * RenderGroup_t object have been set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * RenderGroup_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_hasRequiredAttributes(const RenderGroup_t * rg);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * RenderGroup_t object have been set.
 *
 * @param rg the RenderGroup_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * RenderGroup_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the RenderGroup_t object are:
 *
 * @memberof RenderGroup_t
 */
LIBSBML_EXTERN
int
RenderGroup_hasRequiredElements(const RenderGroup_t * rg);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !RenderGroup_H__ */


