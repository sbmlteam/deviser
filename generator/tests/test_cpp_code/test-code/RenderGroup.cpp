/**
 * @file RenderGroup.cpp
 * @brief Implementation of the RenderGroup class.
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
 */
#include <sbml/packages/render/sbml/RenderGroup.h>
#include <sbml/packages/render/validator/RenderSBMLError.h>
#include <sbml/util/ElementFilter.h>

#include <sbml/packages/render/sbml/Image.h>
#include <sbml/packages/render/sbml/Ellipse.h>
#include <sbml/packages/render/sbml/Rectangle.h>
#include <sbml/packages/render/sbml/Polygon.h>
#include <sbml/packages/render/sbml/RenderGroup.h>
#include <sbml/packages/render/sbml/Text.h>
#include <sbml/packages/render/sbml/RenderCurve.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new RenderGroup using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 */
RenderGroup::RenderGroup(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
  : GraphicalPrimitive2D(level, version)
  , mStartHead ("")
  , mEndHead ("")
  , mFontFamily ("")
  , mFontWeight (FONT_WEIGHT_INVALID)
  , mFontStyle (FONT_STYLE_INVALID)
  , mTextAnchor (H_TEXT_ANCHOR_INVALID)
  , mVtextAnchor (V_TEXT_ANCHOR_INVALID)
  , mFontSize (NULL)
  , mTransformation2Ds (level, version, pkgVersion)
  , mElementName("g")
{
  setSBMLNamespacesAndOwn(new RenderPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new RenderGroup using the given RenderPkgNamespaces object.
 */
RenderGroup::RenderGroup(RenderPkgNamespaces *renderns)
  : GraphicalPrimitive2D(renderns)
  , mStartHead ("")
  , mEndHead ("")
  , mFontFamily ("")
  , mFontWeight (FONT_WEIGHT_INVALID)
  , mFontStyle (FONT_STYLE_INVALID)
  , mTextAnchor (H_TEXT_ANCHOR_INVALID)
  , mVtextAnchor (V_TEXT_ANCHOR_INVALID)
  , mFontSize (NULL)
  , mTransformation2Ds (renderns)
  , mElementName("g")
{
  setElementNamespace(renderns->getURI());
  connectToChild();
  loadPlugins(renderns);
}


/*
 * Copy constructor for RenderGroup.
 */
RenderGroup::RenderGroup(const RenderGroup& orig)
  : GraphicalPrimitive2D( orig )
  , mStartHead ( orig.mStartHead )
  , mEndHead ( orig.mEndHead )
  , mFontFamily ( orig.mFontFamily )
  , mFontWeight ( orig.mFontWeight )
  , mFontStyle ( orig.mFontStyle )
  , mTextAnchor ( orig.mTextAnchor )
  , mVtextAnchor ( orig.mVtextAnchor )
  , mFontSize ( NULL )
  , mTransformation2Ds ( orig.mTransformation2Ds )
  , mElementName ( orig.mElementName )
{
  if (orig.mFontSize != NULL)
  {
    mFontSize = orig.mFontSize->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for RenderGroup.
 */
RenderGroup&
RenderGroup::operator=(const RenderGroup& rhs)
{
  if (&rhs != this)
  {
    GraphicalPrimitive2D::operator=(rhs);
    mStartHead = rhs.mStartHead;
    mEndHead = rhs.mEndHead;
    mFontFamily = rhs.mFontFamily;
    mFontWeight = rhs.mFontWeight;
    mFontStyle = rhs.mFontStyle;
    mTextAnchor = rhs.mTextAnchor;
    mVtextAnchor = rhs.mVtextAnchor;
    mTransformation2Ds = rhs.mTransformation2Ds;
    mElementName = rhs.mElementName;
    delete mFontSize;
    if (rhs.mFontSize != NULL)
    {
      mFontSize = rhs.mFontSize->clone();
    }
    else
    {
      mFontSize = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this RenderGroup object.
 */
RenderGroup*
RenderGroup::clone() const
{
  return new RenderGroup(*this);
}


/*
 * Destructor for RenderGroup.
 */
RenderGroup::~RenderGroup()
{
  delete mFontSize;
  mFontSize = NULL;
}


/*
 * Returns the value of the "startHead" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getStartHead() const
{
  return mStartHead;
}


/*
 * Returns the value of the "endHead" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getEndHead() const
{
  return mEndHead;
}


/*
 * Returns the value of the "font-family" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getFontFamily() const
{
  return mFontFamily;
}


/*
 * Returns the value of the "font-weight" attribute of this RenderGroup.
 */
FontWeight_t
RenderGroup::getFontWeight() const
{
  return mFontWeight;
}


/*
 * Returns the value of the "font-weight" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getFontWeightAsString() const
{
  static const std::string code_str = FontWeight_toString(mFontWeight);
  return code_str;
}


/*
 * Returns the value of the "font-style" attribute of this RenderGroup.
 */
FontStyle_t
RenderGroup::getFontStyle() const
{
  return mFontStyle;
}


/*
 * Returns the value of the "font-style" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getFontStyleAsString() const
{
  static const std::string code_str = FontStyle_toString(mFontStyle);
  return code_str;
}


/*
 * Returns the value of the "text-anchor" attribute of this RenderGroup.
 */
HTextAnchor_t
RenderGroup::getTextAnchor() const
{
  return mTextAnchor;
}


/*
 * Returns the value of the "text-anchor" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getTextAnchorAsString() const
{
  static const std::string code_str = HTextAnchor_toString(mTextAnchor);
  return code_str;
}


/*
 * Returns the value of the "vtext-anchor" attribute of this RenderGroup.
 */
VTextAnchor_t
RenderGroup::getVtextAnchor() const
{
  return mVtextAnchor;
}


/*
 * Returns the value of the "vtext-anchor" attribute of this RenderGroup.
 */
const std::string&
RenderGroup::getVtextAnchorAsString() const
{
  static const std::string code_str = VTextAnchor_toString(mVtextAnchor);
  return code_str;
}


/*
 * Predicate returning @c true if this RenderGroup's "startHead" attribute is
 * set.
 */
bool
RenderGroup::isSetStartHead() const
{
  return (mStartHead.empty() == false);
}


/*
 * Predicate returning @c true if this RenderGroup's "endHead" attribute is
 * set.
 */
bool
RenderGroup::isSetEndHead() const
{
  return (mEndHead.empty() == false);
}


/*
 * Predicate returning @c true if this RenderGroup's "font-family" attribute is
 * set.
 */
bool
RenderGroup::isSetFontFamily() const
{
  return (mFontFamily.empty() == false);
}


/*
 * Predicate returning @c true if this RenderGroup's "font-weight" attribute is
 * set.
 */
bool
RenderGroup::isSetFontWeight() const
{
  return (mFontWeight != FONT_WEIGHT_INVALID);
}


/*
 * Predicate returning @c true if this RenderGroup's "font-style" attribute is
 * set.
 */
bool
RenderGroup::isSetFontStyle() const
{
  return (mFontStyle != FONT_STYLE_INVALID);
}


/*
 * Predicate returning @c true if this RenderGroup's "text-anchor" attribute is
 * set.
 */
bool
RenderGroup::isSetTextAnchor() const
{
  return (mTextAnchor != H_TEXT_ANCHOR_INVALID);
}


/*
 * Predicate returning @c true if this RenderGroup's "vtext-anchor" attribute
 * is set.
 */
bool
RenderGroup::isSetVtextAnchor() const
{
  return (mVtextAnchor != V_TEXT_ANCHOR_INVALID);
}


/*
 * Sets the value of the "startHead" attribute of this RenderGroup.
 */
int
RenderGroup::setStartHead(const std::string& startHead)
{
  if (!(SyntaxChecker::isValidInternalSId(startHead)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mStartHead = startHead;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "endHead" attribute of this RenderGroup.
 */
int
RenderGroup::setEndHead(const std::string& endHead)
{
  if (!(SyntaxChecker::isValidInternalSId(endHead)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mEndHead = endHead;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "font-family" attribute of this RenderGroup.
 */
int
RenderGroup::setFontFamily(const std::string& fontFamily)
{
  mFontFamily = fontFamily;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "font-weight" attribute of this RenderGroup.
 */
int
RenderGroup::setFontWeight(const FontWeight_t fontWeight)
{
  if (FontWeight_isValid(fontWeight) == 0)
  {
    mFontWeight = FONT_WEIGHT_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mFontWeight = fontWeight;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "font-weight" attribute of this RenderGroup.
 */
int
RenderGroup::setFontWeight(const std::string& fontWeight)
{
  if (FontWeight_isValidString(fontWeight.c_str()) == 0)
  {
    mFontWeight = FONT_WEIGHT_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mFontWeight = FontWeight_fromString(fontWeight.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "font-style" attribute of this RenderGroup.
 */
int
RenderGroup::setFontStyle(const FontStyle_t fontStyle)
{
  if (FontStyle_isValid(fontStyle) == 0)
  {
    mFontStyle = FONT_STYLE_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mFontStyle = fontStyle;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "font-style" attribute of this RenderGroup.
 */
int
RenderGroup::setFontStyle(const std::string& fontStyle)
{
  if (FontStyle_isValidString(fontStyle.c_str()) == 0)
  {
    mFontStyle = FONT_STYLE_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mFontStyle = FontStyle_fromString(fontStyle.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "text-anchor" attribute of this RenderGroup.
 */
int
RenderGroup::setTextAnchor(const HTextAnchor_t textAnchor)
{
  if (HTextAnchor_isValid(textAnchor) == 0)
  {
    mTextAnchor = H_TEXT_ANCHOR_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTextAnchor = textAnchor;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "text-anchor" attribute of this RenderGroup.
 */
int
RenderGroup::setTextAnchor(const std::string& textAnchor)
{
  if (HTextAnchor_isValidString(textAnchor.c_str()) == 0)
  {
    mTextAnchor = H_TEXT_ANCHOR_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTextAnchor = HTextAnchor_fromString(textAnchor.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "vtext-anchor" attribute of this RenderGroup.
 */
int
RenderGroup::setVtextAnchor(const VTextAnchor_t vtextAnchor)
{
  if (VTextAnchor_isValid(vtextAnchor) == 0)
  {
    mVtextAnchor = V_TEXT_ANCHOR_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mVtextAnchor = vtextAnchor;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "vtext-anchor" attribute of this RenderGroup.
 */
int
RenderGroup::setVtextAnchor(const std::string& vtextAnchor)
{
  if (VTextAnchor_isValidString(vtextAnchor.c_str()) == 0)
  {
    mVtextAnchor = V_TEXT_ANCHOR_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mVtextAnchor = VTextAnchor_fromString(vtextAnchor.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "startHead" attribute of this RenderGroup.
 */
int
RenderGroup::unsetStartHead()
{
  mStartHead.erase();

  if (mStartHead.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "endHead" attribute of this RenderGroup.
 */
int
RenderGroup::unsetEndHead()
{
  mEndHead.erase();

  if (mEndHead.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "font-family" attribute of this RenderGroup.
 */
int
RenderGroup::unsetFontFamily()
{
  mFontFamily.erase();

  if (mFontFamily.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "font-weight" attribute of this RenderGroup.
 */
int
RenderGroup::unsetFontWeight()
{
  mFontWeight = FONT_WEIGHT_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "font-style" attribute of this RenderGroup.
 */
int
RenderGroup::unsetFontStyle()
{
  mFontStyle = FONT_STYLE_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "text-anchor" attribute of this RenderGroup.
 */
int
RenderGroup::unsetTextAnchor()
{
  mTextAnchor = H_TEXT_ANCHOR_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "vtext-anchor" attribute of this RenderGroup.
 */
int
RenderGroup::unsetVtextAnchor()
{
  mVtextAnchor = V_TEXT_ANCHOR_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the value of the "font-size" element of this RenderGroup.
 */
const RelAbsVector*
RenderGroup::getFontSize() const
{
  return mFontSize;
}


/*
 * Returns the value of the "font-size" element of this RenderGroup.
 */
RelAbsVector*
RenderGroup::getFontSize()
{
  return mFontSize;
}


/*
 * Predicate returning @c true if this RenderGroup's "font-size" element is
 * set.
 */
bool
RenderGroup::isSetFontSize() const
{
  return (mFontSize != NULL);
}


/*
 * Sets the value of the "font-size" element of this RenderGroup.
 */
int
RenderGroup::setFontSize(const RelAbsVector* fontSize)
{
  if (mFontSize == fontSize)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (fontSize == NULL)
  {
    delete mFontSize;
    mFontSize = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mFontSize;
    mFontSize = (fontSize != NULL) ? fontSize->clone() : NULL;
    if (mFontSize != NULL)
    {
      mFontSize->setElementName("fontSize");
      mFontSize->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new RelAbsVector object, adds it to this RenderGroup object and
 * returns the RelAbsVector object created.
 */
RelAbsVector*
RenderGroup::createFontSize()
{
  if (mFontSize != NULL)
  {
    delete mFontSize;
  }

  RENDER_CREATE_NS(renderns, getSBMLNamespaces());
  mFontSize = new RelAbsVector(renderns);

  mFontSize->setElementName("font-size");

  delete renderns;

  connectToChild();

  return mFontSize;
}


/*
 * Unsets the value of the "font-size" element of this RenderGroup.
 */
int
RenderGroup::unsetFontSize()
{
  delete mFontSize;
  mFontSize = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the ListOfDrawables from this RenderGroup.
 */
const ListOfDrawables*
RenderGroup::getListOfElements() const
{
  return &mTransformation2Ds;
}


/*
 * Returns the ListOfDrawables from this RenderGroup.
 */
ListOfDrawables*
RenderGroup::getListOfElements()
{
  return &mTransformation2Ds;
}


/*
 * Get a Transformation2D from the RenderGroup.
 */
Transformation2D*
RenderGroup::getElement(unsigned int n)
{
  return mTransformation2Ds.get(n);
}


/*
 * Get a Transformation2D from the RenderGroup.
 */
const Transformation2D*
RenderGroup::getElement(unsigned int n) const
{
  return mTransformation2Ds.get(n);
}


/*
 * Adds a copy of the given Transformation2D to this RenderGroup.
 */
int
RenderGroup::addElement(const Transformation2D* td)
{
  if (td == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (td->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != td->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != td->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(td)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mTransformation2Ds.append(td);
  }
}


/*
 * Get the number of Transformation2D objects in this RenderGroup.
 */
unsigned int
RenderGroup::getNumElements() const
{
  return mTransformation2Ds.size();
}


/*
 * Creates a new Image object, adds it to this RenderGroup object and returns
 * the Image object created.
 */
Image*
RenderGroup::createImage()
{
  Image* i = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    i = new Image(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (i != NULL)
  {
    mTransformation2Ds.appendAndOwn(i);
  }

  return i;
}


/*
 * Creates a new Ellipse object, adds it to this RenderGroup object and returns
 * the Ellipse object created.
 */
Ellipse*
RenderGroup::createEllipse()
{
  Ellipse* e = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    e = new Ellipse(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (e != NULL)
  {
    mTransformation2Ds.appendAndOwn(e);
  }

  return e;
}


/*
 * Creates a new Rectangle object, adds it to this RenderGroup object and
 * returns the Rectangle object created.
 */
Rectangle*
RenderGroup::createRectangle()
{
  Rectangle* r = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    r = new Rectangle(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (r != NULL)
  {
    mTransformation2Ds.appendAndOwn(r);
  }

  return r;
}


/*
 * Creates a new Polygon object, adds it to this RenderGroup object and returns
 * the Polygon object created.
 */
Polygon*
RenderGroup::createPolygon()
{
  Polygon* p = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    p = new Polygon(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (p != NULL)
  {
    mTransformation2Ds.appendAndOwn(p);
  }

  return p;
}


/*
 * Creates a new RenderGroup object, adds it to this RenderGroup object and
 * returns the RenderGroup object created.
 */
RenderGroup*
RenderGroup::createGroup()
{
  RenderGroup* rg = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    rg = new RenderGroup(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (rg != NULL)
  {
    mTransformation2Ds.appendAndOwn(rg);
  }

  return rg;
}


/*
 * Creates a new Text object, adds it to this RenderGroup object and returns
 * the Text object created.
 */
Text*
RenderGroup::createText()
{
  Text* t = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    t = new Text(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (t != NULL)
  {
    mTransformation2Ds.appendAndOwn(t);
  }

  return t;
}


/*
 * Creates a new RenderCurve object, adds it to this RenderGroup object and
 * returns the RenderCurve object created.
 */
RenderCurve*
RenderGroup::createCurve()
{
  RenderCurve* rc = NULL;

  try
  {
    RENDER_CREATE_NS(renderns, getSBMLNamespaces());
    rc = new RenderCurve(renderns);
    delete renderns;
  }
  catch (...)
  {
  }

  if (rc != NULL)
  {
    mTransformation2Ds.appendAndOwn(rc);
  }

  return rc;
}


/*
 * Removes the nth Transformation2D from this RenderGroup and returns a pointer
 * to it.
 */
Transformation2D*
RenderGroup::removeElement(unsigned int n)
{
  return mTransformation2Ds.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
RenderGroup::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetStartHead() && mStartHead == oldid)
  {
    setStartHead(newid);
  }

  if (isSetEndHead() && mEndHead == oldid)
  {
    setEndHead(newid);
  }
}


/*
 * Returns the XML element name of this RenderGroup object.
 */
const std::string&
RenderGroup::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this RenderGroup object.
 */
void
RenderGroup::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this RenderGroup object.
 */
int
RenderGroup::getTypeCode() const
{
  return SBML_RENDER_GROUP;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * RenderGroup object have been set.
 */
bool
RenderGroup::hasRequiredAttributes() const
{
  bool allPresent = GraphicalPrimitive2D::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * RenderGroup object have been set.
 */
bool
RenderGroup::hasRequiredElements() const
{
  bool allPresent = GraphicalPrimitive2D::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
RenderGroup::writeElements(XMLOutputStream& stream) const
{
  GraphicalPrimitive2D::writeElements(stream);

  if (isSetFontSize() == true)
  {
    mFontSize->write(stream);
  }

  for (unsigned int i = 0; i < getNumElements(); i++)
  {
    getElement(i)->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
RenderGroup::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mFontSize != NULL)
  {
    mFontSize->accept(v);
  }

  mTransformation2Ds.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
RenderGroup::setSBMLDocument(SBMLDocument* d)
{
  GraphicalPrimitive2D::setSBMLDocument(d);

  if (mFontSize != NULL)
  {
    mFontSize->setSBMLDocument(d);
  }

  mTransformation2Ds.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
RenderGroup::connectToChild()
{
  GraphicalPrimitive2D::connectToChild();

  if (mFontSize != NULL)
  {
    mFontSize->connectToParent(this);
  }

  mTransformation2Ds.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
RenderGroup::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix,
                                   bool flag)
{
  GraphicalPrimitive2D::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetFontSize())
  {
    mFontSize->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  mTransformation2Ds.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = GraphicalPrimitive2D::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = GraphicalPrimitive2D::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = GraphicalPrimitive2D::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = GraphicalPrimitive2D::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = GraphicalPrimitive2D::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "startHead")
  {
    value = getStartHead();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "endHead")
  {
    value = getEndHead();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "font-family")
  {
    value = getFontFamily();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "font-weight")
  {
    value = getFontWeightAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "font-style")
  {
    value = getFontStyleAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "text-anchor")
  {
    value = getTextAnchorAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "vtext-anchor")
  {
    value = getVtextAnchorAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::getAttribute(const std::string& attributeName,
                          const char* value) const
{
  int return_value = GraphicalPrimitive2D::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "startHead")
  {
    value = getStartHead().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "endHead")
  {
    value = getEndHead().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "font-family")
  {
    value = getFontFamily().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "font-weight")
  {
    value = getFontWeightAsString().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "font-style")
  {
    value = getFontStyleAsString().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "text-anchor")
  {
    value = getTextAnchorAsString().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "vtext-anchor")
  {
    value = getVtextAnchorAsString().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this RenderGroup's attribute "attributeName"
 * is set.
 */
bool
RenderGroup::isSetAttribute(const std::string& attributeName) const
{
  bool value = GraphicalPrimitive2D::isSetAttribute(attributeName);

  if (attributeName == "startHead")
  {
    value = isSetStartHead();
  }
  else if (attributeName == "endHead")
  {
    value = isSetEndHead();
  }
  else if (attributeName == "font-family")
  {
    value = isSetFontFamily();
  }
  else if (attributeName == "font-weight")
  {
    value = isSetFontWeight();
  }
  else if (attributeName == "font-style")
  {
    value = isSetFontStyle();
  }
  else if (attributeName == "text-anchor")
  {
    value = isSetTextAnchor();
  }
  else if (attributeName == "vtext-anchor")
  {
    value = isSetVtextAnchor();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = GraphicalPrimitive2D::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::setAttribute(const std::string& attributeName, int value)
{
  int return_value = GraphicalPrimitive2D::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::setAttribute(const std::string& attributeName, double value)
{
  int return_value = GraphicalPrimitive2D::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = GraphicalPrimitive2D::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = GraphicalPrimitive2D::setAttribute(attributeName, value);

  if (attributeName == "startHead")
  {
    return_value = setStartHead(value);
  }
  else if (attributeName == "endHead")
  {
    return_value = setEndHead(value);
  }
  else if (attributeName == "font-family")
  {
    return_value = setFontFamily(value);
  }
  else if (attributeName == "font-weight")
  {
    return_value = setFontWeight(value);
  }
  else if (attributeName == "font-style")
  {
    return_value = setFontStyle(value);
  }
  else if (attributeName == "text-anchor")
  {
    return_value = setTextAnchor(value);
  }
  else if (attributeName == "vtext-anchor")
  {
    return_value = setVtextAnchor(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = GraphicalPrimitive2D::setAttribute(attributeName, value);

  if (attributeName == "startHead")
  {
    return_value = setStartHead(value);
  }
  else if (attributeName == "endHead")
  {
    return_value = setEndHead(value);
  }
  else if (attributeName == "font-family")
  {
    return_value = setFontFamily(value);
  }
  else if (attributeName == "font-weight")
  {
    return_value = setFontWeight(value);
  }
  else if (attributeName == "font-style")
  {
    return_value = setFontStyle(value);
  }
  else if (attributeName == "text-anchor")
  {
    return_value = setTextAnchor(value);
  }
  else if (attributeName == "vtext-anchor")
  {
    return_value = setVtextAnchor(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this RenderGroup.
 */
int
RenderGroup::unsetAttribute(const std::string& attributeName)
{
  int value = GraphicalPrimitive2D::unsetAttribute(attributeName);

  if (attributeName == "startHead")
  {
    value = unsetStartHead();
  }
  else if (attributeName == "endHead")
  {
    value = unsetEndHead();
  }
  else if (attributeName == "font-family")
  {
    value = unsetFontFamily();
  }
  else if (attributeName == "font-weight")
  {
    value = unsetFontWeight();
  }
  else if (attributeName == "font-style")
  {
    value = unsetFontStyle();
  }
  else if (attributeName == "text-anchor")
  {
    value = unsetTextAnchor();
  }
  else if (attributeName == "vtext-anchor")
  {
    value = unsetVtextAnchor();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this RenderGroup.
 */
SBase*
RenderGroup::createChildObject(const std::string& elementName)
{
  GraphicalPrimitive2D* obj = NULL;

  if (elementName == "font-size")
  {
    return createFontSize();
  }
  else if (elementName == "image")
  {
    return createImage();
  }
  else if (elementName == "ellipse")
  {
    return createEllipse();
  }
  else if (elementName == "rectangle")
  {
    return createRectangle();
  }
  else if (elementName == "polygon")
  {
    return createPolygon();
  }
  else if (elementName == "g")
  {
    return createGroup();
  }
  else if (elementName == "text")
  {
    return createText();
  }
  else if (elementName == "curve")
  {
    return createCurve();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this RenderGroup.
 */
int
RenderGroup::addChildObject(const std::string& elementName,
                            const SBase* element)
{
  if (elementName == "font-size" && element->getTypeCode() ==
    SBML_RENDER_RELABSVECTOR)
  {
    return setFontSize((const RelAbsVector*)(element));
  }
  else if (elementName == "image" && element->getTypeCode() ==
    SBML_RENDER_IMAGE)
  {
    return addElement((const Transformation2D*)(element));
  }
  else if (elementName == "ellipse" && element->getTypeCode() ==
    SBML_RENDER_ELLIPSE)
  {
    return addElement((const Transformation2D*)(element));
  }
  else if (elementName == "rectangle" && element->getTypeCode() ==
    SBML_RENDER_RECTANGLE)
  {
    return addElement((const Transformation2D*)(element));
  }
  else if (elementName == "polygon" && element->getTypeCode() ==
    SBML_RENDER_POLYGON)
  {
    return addElement((const Transformation2D*)(element));
  }
  else if (elementName == "g" && element->getTypeCode() == SBML_RENDER_GROUP)
  {
    return addElement((const Transformation2D*)(element));
  }
  else if (elementName == "text" && element->getTypeCode() == SBML_RENDER_TEXT)
  {
    return addElement((const Transformation2D*)(element));
  }
  else if (elementName == "curve" && element->getTypeCode() ==
    SBML_RENDER_CURVE)
  {
    return addElement((const Transformation2D*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * RenderGroup.
 */
SBase*
RenderGroup::removeChildObject(const std::string& elementName,
                               const std::string& id)
{
  if (elementName == "font-size")
  {
    RelAbsVector * obj = getFontSize();
    if (unsetFontSize() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "image")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }
  else if (elementName == "ellipse")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }
  else if (elementName == "rectangle")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }
  else if (elementName == "polygon")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }
  else if (elementName == "g")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }
  else if (elementName == "text")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }
  else if (elementName == "curve")
  {
    for (unsigned int i = 0; i < getNumElements(); i++)
    {
      if (getElement(i)->getId() == id)
      {
        return removeElement(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this RenderGroup.
 */
unsigned int
RenderGroup::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "font-size")
  {
    if (isSetFontSize())
    {
      return 1;
    }
  }
  else if (elementName == "element")
  {
    return getNumElements();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this RenderGroup.
 */
SBase*
RenderGroup::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "font-size")
  {
    return getFontSize();
  }
  else if (elementName == "element")
  {
    return getElement(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
RenderGroup::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mFontSize != NULL)
  {
    if (mFontSize->getId() == id)
    {
      return mFontSize;
    }

    obj = mFontSize->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mTransformation2Ds.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
RenderGroup::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mFontSize != NULL)
  {
    if (mFontSize->getMetaId() == metaid)
    {
      return mFontSize;
    }

    obj = mFontSize->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mTransformation2Ds.getMetaId() == metaid)
  {
    return &mTransformation2Ds;
  }

  obj = mTransformation2Ds.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
RenderGroup::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mFontSize, filter);

  ADD_FILTERED_LIST(ret, sublist, mTransformation2Ds, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
RenderGroup::createObject(XMLInputStream& stream)
{
  SBase* obj = GraphicalPrimitive2D::createObject(stream);

  const std::string& name = stream.peek().getName();

  RENDER_CREATE_NS(renderns, getSBMLNamespaces());

  if (name == "font-size")
  {
    if (isSetFontSize())
    {
      getErrorLog()->logPackageError("render",
        RenderRenderGroupAllowedAttributes, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mFontSize;
    mFontSize = new RelAbsVector(renderns);
    mFontSize->setElementName(name);
    obj = mFontSize;
  }
  else
  {
    obj = mTransformation2Ds.createObject(stream);
  }

  delete renderns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
RenderGroup::addExpectedAttributes(ExpectedAttributes& attributes)
{
  GraphicalPrimitive2D::addExpectedAttributes(attributes);

  attributes.add("startHead");

  attributes.add("endHead");

  attributes.add("font-family");

  attributes.add("font-weight");

  attributes.add("font-style");

  attributes.add("text-anchor");

  attributes.add("vtext-anchor");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
RenderGroup::readAttributes(const XMLAttributes& attributes,
                            const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  GraphicalPrimitive2D::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("render", RenderRenderGroupAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("render", RenderRenderGroupAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // startHead SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("startHead", mStartHead);

  if (assigned == true)
  {
    if (mStartHead.empty() == true)
    {
      logEmptyString(mStartHead, level, version, "<RenderGroup>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mStartHead) == false)
    {
      std::string msg = "The startHead attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mStartHead + "', which does not conform to the syntax.";
      log->logPackageError("render",
        RenderRenderGroupStartHeadMustBeLineEnding, pkgVersion, level, version,
          msg, getLine(), getColumn());
    }
  }

  // 
  // endHead SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("endHead", mEndHead);

  if (assigned == true)
  {
    if (mEndHead.empty() == true)
    {
      logEmptyString(mEndHead, level, version, "<RenderGroup>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mEndHead) == false)
    {
      std::string msg = "The endHead attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mEndHead + "', which does not conform to the syntax.";
      log->logPackageError("render", RenderRenderGroupEndHeadMustBeLineEnding,
        pkgVersion, level, version, msg, getLine(), getColumn());
    }
  }

  // 
  // font-family string (use = "optional" )
  // 

  assigned = attributes.readInto("font-family", mFontFamily);

  if (assigned == true)
  {
    if (mFontFamily.empty() == true)
    {
      logEmptyString(mFontFamily, level, version, "<RenderGroup>");
    }
  }

  // 
  // font-weight enum (use = "optional" )
  // 

  std::string fontWeight;
  assigned = attributes.readInto("font-weight", fontWeight);

  if (assigned == true)
  {
    if (fontWeight.empty() == true)
    {
      logEmptyString(fontWeight, level, version, "<RenderGroup>");
    }
    else
    {
      mFontWeight = FontWeight_fromString(fontWeight.c_str());

      if (FontWeight_isValid(mFontWeight) == 0)
      {
        std::string msg = "The font-weight on the <RenderGroup> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + fontWeight + "', which is not a valid option.";

        log->logPackageError("render",
          RenderRenderGroupFontWeightMustBeFontWeightEnum, pkgVersion, level,
            version, msg);
      }
    }
  }

  // 
  // font-style enum (use = "optional" )
  // 

  std::string fontStyle;
  assigned = attributes.readInto("font-style", fontStyle);

  if (assigned == true)
  {
    if (fontStyle.empty() == true)
    {
      logEmptyString(fontStyle, level, version, "<RenderGroup>");
    }
    else
    {
      mFontStyle = FontStyle_fromString(fontStyle.c_str());

      if (FontStyle_isValid(mFontStyle) == 0)
      {
        std::string msg = "The font-style on the <RenderGroup> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + fontStyle + "', which is not a valid option.";

        log->logPackageError("render",
          RenderRenderGroupFontStyleMustBeFontStyleEnum, pkgVersion, level,
            version, msg);
      }
    }
  }

  // 
  // text-anchor enum (use = "optional" )
  // 

  std::string textAnchor;
  assigned = attributes.readInto("text-anchor", textAnchor);

  if (assigned == true)
  {
    if (textAnchor.empty() == true)
    {
      logEmptyString(textAnchor, level, version, "<RenderGroup>");
    }
    else
    {
      mTextAnchor = HTextAnchor_fromString(textAnchor.c_str());

      if (HTextAnchor_isValid(mTextAnchor) == 0)
      {
        std::string msg = "The text-anchor on the <RenderGroup> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + textAnchor + "', which is not a valid option.";

        log->logPackageError("render",
          RenderRenderGroupTextAnchorMustBeHTextAnchorEnum, pkgVersion, level,
            version, msg);
      }
    }
  }

  // 
  // vtext-anchor enum (use = "optional" )
  // 

  std::string vtextAnchor;
  assigned = attributes.readInto("vtext-anchor", vtextAnchor);

  if (assigned == true)
  {
    if (vtextAnchor.empty() == true)
    {
      logEmptyString(vtextAnchor, level, version, "<RenderGroup>");
    }
    else
    {
      mVtextAnchor = VTextAnchor_fromString(vtextAnchor.c_str());

      if (VTextAnchor_isValid(mVtextAnchor) == 0)
      {
        std::string msg = "The vtext-anchor on the <RenderGroup> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + vtextAnchor + "', which is not a valid option.";

        log->logPackageError("render",
          RenderRenderGroupVtextAnchorMustBeVTextAnchorEnum, pkgVersion, level,
            version, msg);
      }
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
RenderGroup::writeAttributes(XMLOutputStream& stream) const
{
  GraphicalPrimitive2D::writeAttributes(stream);

  if (isSetStartHead() == true)
  {
    stream.writeAttribute("startHead", getPrefix(), mStartHead);
  }

  if (isSetEndHead() == true)
  {
    stream.writeAttribute("endHead", getPrefix(), mEndHead);
  }

  if (isSetFontFamily() == true)
  {
    stream.writeAttribute("font-family", getPrefix(), mFontFamily);
  }

  if (isSetFontWeight() == true)
  {
    stream.writeAttribute("font-weight", getPrefix(),
      FontWeight_toString(mFontWeight));
  }

  if (isSetFontStyle() == true)
  {
    stream.writeAttribute("font-style", getPrefix(),
      FontStyle_toString(mFontStyle));
  }

  if (isSetTextAnchor() == true)
  {
    stream.writeAttribute("text-anchor", getPrefix(),
      HTextAnchor_toString(mTextAnchor));
  }

  if (isSetVtextAnchor() == true)
  {
    stream.writeAttribute("vtext-anchor", getPrefix(),
      VTextAnchor_toString(mVtextAnchor));
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new RenderGroup_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 */
LIBSBML_EXTERN
RenderGroup_t *
RenderGroup_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
{
  return new RenderGroup(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this RenderGroup_t object.
 */
LIBSBML_EXTERN
RenderGroup_t*
RenderGroup_clone(const RenderGroup_t* rg)
{
  if (rg != NULL)
  {
    return static_cast<RenderGroup_t*>(rg->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this RenderGroup_t object.
 */
LIBSBML_EXTERN
void
RenderGroup_free(RenderGroup_t* rg)
{
  if (rg != NULL)
  {
    delete rg;
  }
}


/*
 * Returns the value of the "startHead" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
char *
RenderGroup_getStartHead(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return NULL;
  }

  return rg->getStartHead().empty() ? NULL :
    safe_strdup(rg->getStartHead().c_str());
}


/*
 * Returns the value of the "endHead" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
char *
RenderGroup_getEndHead(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return NULL;
  }

  return rg->getEndHead().empty() ? NULL :
    safe_strdup(rg->getEndHead().c_str());
}


/*
 * Returns the value of the "font-family" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
char *
RenderGroup_getFontFamily(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return NULL;
  }

  return rg->getFontFamily().empty() ? NULL :
    safe_strdup(rg->getFontFamily().c_str());
}


/*
 * Returns the value of the "font-weight" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
FontWeight_t
RenderGroup_getFontWeight(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return FONT_WEIGHT_INVALID;
  }

  return rg->getFontWeight();
}


/*
 * Returns the value of the "font-weight" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
const char *
RenderGroup_getFontWeightAsString(const RenderGroup_t * rg)
{
  return FontWeight_toString(rg->getFontWeight());
}


/*
 * Returns the value of the "font-style" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
FontStyle_t
RenderGroup_getFontStyle(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return FONT_STYLE_INVALID;
  }

  return rg->getFontStyle();
}


/*
 * Returns the value of the "font-style" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
const char *
RenderGroup_getFontStyleAsString(const RenderGroup_t * rg)
{
  return FontStyle_toString(rg->getFontStyle());
}


/*
 * Returns the value of the "text-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
HTextAnchor_t
RenderGroup_getTextAnchor(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return H_TEXT_ANCHOR_INVALID;
  }

  return rg->getTextAnchor();
}


/*
 * Returns the value of the "text-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
const char *
RenderGroup_getTextAnchorAsString(const RenderGroup_t * rg)
{
  return HTextAnchor_toString(rg->getTextAnchor());
}


/*
 * Returns the value of the "vtext-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
VTextAnchor_t
RenderGroup_getVtextAnchor(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return V_TEXT_ANCHOR_INVALID;
  }

  return rg->getVtextAnchor();
}


/*
 * Returns the value of the "vtext-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
const char *
RenderGroup_getVtextAnchorAsString(const RenderGroup_t * rg)
{
  return VTextAnchor_toString(rg->getVtextAnchor());
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "startHead"
 * attribute is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetStartHead(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetStartHead()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "endHead" attribute
 * is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetEndHead(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetEndHead()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-family"
 * attribute is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontFamily(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetFontFamily()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-weight"
 * attribute is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontWeight(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetFontWeight()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-style"
 * attribute is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontStyle(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetFontStyle()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "text-anchor"
 * attribute is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetTextAnchor(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetTextAnchor()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "vtext-anchor"
 * attribute is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetVtextAnchor(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetVtextAnchor()) : 0;
}


/*
 * Sets the value of the "startHead" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setStartHead(RenderGroup_t * rg, const char * startHead)
{
  return (rg != NULL) ? rg->setStartHead(startHead) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "endHead" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setEndHead(RenderGroup_t * rg, const char * endHead)
{
  return (rg != NULL) ? rg->setEndHead(endHead) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "font-family" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setFontFamily(RenderGroup_t * rg, const char * fontFamily)
{
  return (rg != NULL) ? rg->setFontFamily(fontFamily) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "font-weight" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setFontWeight(RenderGroup_t * rg, FontWeight_t fontWeight)
{
  return (rg != NULL) ? rg->setFontWeight(fontWeight) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "font-weight" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setFontWeightAsString(RenderGroup_t * rg, const char * fontWeight)
{
  return (rg != NULL) ? rg->setFontWeight(fontWeight): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "font-style" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setFontStyle(RenderGroup_t * rg, FontStyle_t fontStyle)
{
  return (rg != NULL) ? rg->setFontStyle(fontStyle) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "font-style" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setFontStyleAsString(RenderGroup_t * rg, const char * fontStyle)
{
  return (rg != NULL) ? rg->setFontStyle(fontStyle): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "text-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setTextAnchor(RenderGroup_t * rg, HTextAnchor_t textAnchor)
{
  return (rg != NULL) ? rg->setTextAnchor(textAnchor) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "text-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setTextAnchorAsString(RenderGroup_t * rg, const char * textAnchor)
{
  return (rg != NULL) ? rg->setTextAnchor(textAnchor): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "vtext-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setVtextAnchor(RenderGroup_t * rg, VTextAnchor_t vtextAnchor)
{
  return (rg != NULL) ? rg->setVtextAnchor(vtextAnchor) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "vtext-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setVtextAnchorAsString(RenderGroup_t * rg,
                                   const char * vtextAnchor)
{
  return (rg != NULL) ? rg->setVtextAnchor(vtextAnchor):
    LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "startHead" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetStartHead(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetStartHead() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "endHead" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetEndHead(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetEndHead() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "font-family" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontFamily(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetFontFamily() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "font-weight" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontWeight(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetFontWeight() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "font-style" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontStyle(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetFontStyle() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "text-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetTextAnchor(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetTextAnchor() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "vtext-anchor" attribute of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetVtextAnchor(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetVtextAnchor() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "font-size" element of this RenderGroup_t.
 */
LIBSBML_EXTERN
const RelAbsVector_t*
RenderGroup_getFontSize(const RenderGroup_t * rg)
{
  if (rg == NULL)
  {
    return NULL;
  }

  return (RelAbsVector_t*)(rg->getFontSize());
}


/*
 * Predicate returning @c 1 (true) if this RenderGroup_t's "font-size" element
 * is set.
 */
LIBSBML_EXTERN
int
RenderGroup_isSetFontSize(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->isSetFontSize()) : 0;
}


/*
 * Sets the value of the "font-size" element of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_setFontSize(RenderGroup_t * rg, const RelAbsVector_t* fontSize)
{
  return (rg != NULL) ? rg->setFontSize(fontSize) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new RelAbsVector_t object, adds it to this RenderGroup_t object
 * and returns the RelAbsVector_t object created.
 */
LIBSBML_EXTERN
RelAbsVector_t*
RenderGroup_createFontSize(RenderGroup_t* rg)
{
  if (rg == NULL)
  {
    return NULL;
  }

  return (RelAbsVector_t*)(rg->createFontSize());
}


/*
 * Unsets the value of the "font-size" element of this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_unsetFontSize(RenderGroup_t * rg)
{
  return (rg != NULL) ? rg->unsetFontSize() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing Transformation2D_t objects from this
 * RenderGroup_t.
 */
LIBSBML_EXTERN
ListOf_t*
RenderGroup_getListOfElements(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->getListOfElements() : NULL;
}


/*
 * Get a Transformation2D_t from the RenderGroup_t.
 */
LIBSBML_EXTERN
Transformation2D_t*
RenderGroup_getElement(RenderGroup_t* rg, unsigned int n)
{
  return (rg != NULL) ? rg->getElement(n) : NULL;
}


/*
 * Adds a copy of the given Transformation2D_t to this RenderGroup_t.
 */
LIBSBML_EXTERN
int
RenderGroup_addElement(RenderGroup_t* rg, const Transformation2D_t* td)
{
  return (rg != NULL) ? rg->addElement(td) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Transformation2D_t objects in this RenderGroup_t.
 */
LIBSBML_EXTERN
unsigned int
RenderGroup_getNumElements(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->getNumElements() : SBML_INT_MAX;
}


/*
 * Creates a new Image_t object, adds it to this RenderGroup_t object and
 * returns the Image_t object created.
 */
LIBSBML_EXTERN
Image_t*
RenderGroup_createImage(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createImage() : NULL;
}


/*
 * Creates a new Ellipse_t object, adds it to this RenderGroup_t object and
 * returns the Ellipse_t object created.
 */
LIBSBML_EXTERN
Ellipse_t*
RenderGroup_createEllipse(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createEllipse() : NULL;
}


/*
 * Creates a new Rectangle_t object, adds it to this RenderGroup_t object and
 * returns the Rectangle_t object created.
 */
LIBSBML_EXTERN
Rectangle_t*
RenderGroup_createRectangle(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createRectangle() : NULL;
}


/*
 * Creates a new Polygon_t object, adds it to this RenderGroup_t object and
 * returns the Polygon_t object created.
 */
LIBSBML_EXTERN
Polygon_t*
RenderGroup_createPolygon(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createPolygon() : NULL;
}


/*
 * Creates a new RenderGroup_t object, adds it to this RenderGroup_t object and
 * returns the RenderGroup_t object created.
 */
LIBSBML_EXTERN
RenderGroup_t*
RenderGroup_createGroup(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createGroup() : NULL;
}


/*
 * Creates a new Text_t object, adds it to this RenderGroup_t object and
 * returns the Text_t object created.
 */
LIBSBML_EXTERN
Text_t*
RenderGroup_createText(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createText() : NULL;
}


/*
 * Creates a new RenderCurve_t object, adds it to this RenderGroup_t object and
 * returns the RenderCurve_t object created.
 */
LIBSBML_EXTERN
RenderCurve_t*
RenderGroup_createCurve(RenderGroup_t* rg)
{
  return (rg != NULL) ? rg->createCurve() : NULL;
}


/*
 * Removes the nth Transformation2D_t from this RenderGroup_t and returns a
 * pointer to it.
 */
LIBSBML_EXTERN
Transformation2D_t*
RenderGroup_removeElement(RenderGroup_t* rg, unsigned int n)
{
  return (rg != NULL) ? rg->removeElement(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * RenderGroup_t object have been set.
 */
LIBSBML_EXTERN
int
RenderGroup_hasRequiredAttributes(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * RenderGroup_t object have been set.
 */
LIBSBML_EXTERN
int
RenderGroup_hasRequiredElements(const RenderGroup_t * rg)
{
  return (rg != NULL) ? static_cast<int>(rg->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


