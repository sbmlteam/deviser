/**
 * @file TSBBase.h
 * @brief Definition of the TSBBase class.
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
 * @class TSBBase
 * @sbmlbrief{} TODO:Definition of the TSBBase class.
 */


#ifndef TSBBase_h
#define TSBBase_h


#include <tsb/common/extern.h>
#include <tsb/common/libtsb-namespace.h>
#include <tsb/common/tsbfwd.h>
#include <tsb/TSBTypeCodes.h>
#include <tsb/TSBNamespaces.h>
#include <tsb/TSBConstructorException.h>
#include <tsb/util/ExpectedAttributes.h>
#include <xml/XMLNode.h>

#ifdef __cplusplus


#include <string>
#include <stdexcept>
#include <algorithm>

#include <tsb/TSBErrorLog.h>
#include <tsb/TSBVisitor.h>

class Model;

class List;

class XMLAttributes;
class XMLInputStream;
class XMLNamespaces;
class XMLOutputStream;
class XMLToken;

LIBTSB_CPP_NAMESPACE_BEGIN

class TSBDocument;


class LIBTSB_EXTERN TSBBase
{
public:

  /**
   * Destroys this object.
   */
  virtual ~TSBBase ();


  /**
   * Assignment operator for TSBBase.
   *
   * @param rhs The object whose values are used as the basis of the
   * assignment.
   */
  TSBBase& operator=(const TSBBase& rhs);


  /** @cond doxygenLibtsbInternal */
  /**
   * Accepts the given TSBVisitor for this TSBBase object.
   *
   * @param v the TSBVisitor instance to be used
   *
   * @return the result of calling <code>v.visit()</code>.
   */
  virtual bool accept (TSBVisitor& v) const = 0;
  /** @endcond */


  /**
   * Creates and returns a deep copy of this TSBBase object.
   *
   * @return the (deep) copy of this TSBBase object.
   */
  virtual TSBBase* clone () const = 0;


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual TSBBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual const TSBBase* getElementBySId(const std::string& metaid) const;


  /**
   * Returns the first child element it can find with a specific "metaid"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param metaid string representing the "metaid" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given meta-identifier.
   */
  virtual TSBBase* getElementByMetaId(const std::string& metaid);

  /**
   * Returns the first child element it can find with a specific "metaid"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param metaid string representing the "metaid" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given meta-identifier.
   */
  virtual const TSBBase* getElementByMetaId(const std::string& metaid) const;

  /**
   * Returns a List of all child TSBBase objects, including those nested to
   * an arbitrary depth.
   *
   * @return a pointer to a List of pointers to all children objects.
   */
  virtual List* getAllElements();


  /**
   * Returns the value of the "metaid" attribute of this object.
   *
   * @copydetails doc_what_is_metaid
   *  
   * @return the meta-identifier of this TSB object.
   *
   * @see isSetMetaId()
   * @see setMetaId(const std::string& metaid)
   */
  const std::string& getMetaId () const;


  /**
   * Returns the value of the "metaid" attribute of this object.
   *
   * @copydetails doc_what_is_metaid
   *  
   * @return the meta-identifier of this TSB object, as a string.
   *
   * @see isSetMetaId()
   * @see setMetaId(const std::string& metaid)
   */
  std::string& getMetaId ();

  
  /*
   * @return the id of this TSB object.
   *
   * @note The fact that the value of attribute "id" is defined on the
   * TSBBase parent class object is a convenience provided by libTSB, and
   * <b>does not strictly follow TSB specifications</b>.  This libTSB
   * implementation of TSBBase allows client applications to use more
   * generalized code in some situations (for instance, when manipulating
   * objects that are all known to have identifiers), but beware that not
   * all TSB object classes provide an "id" attribute.  LibTSB will allow
   * the identifier to be set, but it will not read nor write "id"
   * attributes for objects that do not possess them according to the TSB
   * specification for the Level and Version in use.
   *
   */
  virtual const std::string& getId() const;

  /**
   * Returns the content of the "notes" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The "notes" element content returned by this method will be in XML
   * form, but libTSB does not provide an object model specifically for
   * the content of notes.  Callers will need to traverse the XML tree
   * structure using the facilities available on XMLNode and related
   * objects.  For an alternative method of accessing the notes, see
   * getNotesString().
   *
   * @return the content of the "notes" subelement of this TSB object as a
   * tree structure composed of XMLNode objects.
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
   XMLNode* getNotes();


  /**
   * Returns the content of the "notes" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The "notes" element content returned by this method will be in XML
   * form, but libTSB does not provide an object model specifically for
   * the content of notes.  Callers will need to traverse the XML tree
   * structure using the facilities available on XMLNode and related
   * objects.  For an alternative method of accessing the notes, see
   * getNotesString().
   *
   * @return the content of the "notes" subelement of this TSB object as a
   * tree structure composed of XMLNode objects.
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  const  XMLNode* getNotes() const;


  /**
   * Returns the content of the "notes" subelement of this object as a
   * string.
   *
   * For an alternative method of accessing the notes, see getNotes(),
   * which returns the content as an XMLNode tree structure.  Depending on
   * an application's needs, one or the other method may be more
   * convenient.
   *
   * @return the content of the "notes" subelement of this TSB object as a
   * string.
   *
   * @see getNotes()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  std::string getNotesString ();


  /**
   * Returns the content of the "notes" subelement of this object as a
   * string.
   *
   * For an alternative method of accessing the notes, see getNotes(),
   * which returns the content as an XMLNode tree structure.  Depending on
   * an application's needs, one or the other method may be more
   * convenient.
   *
   * @return the content of the "notes" subelement of this TSB object as a
   * string.
   *
   * @see getNotes()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  std::string getNotesString () const;


  /**
   * Returns the content of the "testAnnotation" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The annotations returned by this method will be in XML form.  LibTSB
   * provides an object model and related interfaces for certain specific
   * kinds of annotations, namely model history information and RDF
   * content.  See the ModelHistory, CVTerm and RDFAnnotationParser classes
   * for more information about the facilities available.
   *
   * @return the annotation of this TSB object as a tree of XMLNode objects.
   *
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
   XMLNode* getTestAnnotation ();


  /**
   * Returns the content of the "testAnnotation" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The annotations returned by this method will be in XML form.  LibTSB
   * provides an object model and related interfaces for certain specific
   * kinds of annotations, namely model history information and RDF
   * content.  See the ModelHistory, CVTerm and RDFAnnotationParser classes
   * for more information about the facilities available.
   *
   * @return the annotation of this TSB object as a tree of XMLNode objects.
   *
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  const  XMLNode* getTestAnnotation () const;


  /**
   * Returns the content of the "testAnnotation" subelement of this object as a
   * character string.
   *
   * The annotations returned by this method will be in string form.  See the
   * method getTestAnnotation() for a version that returns annotations in XML form.
   *
   * @return the annotation of this TSB object as a character string.
   *
   * @see getTestAnnotation()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  std::string getTestAnnotationString ();


  /**
   * Returns the content of the "testAnnotation" subelement of this object as a
   * character string.
   *
   * The annotations returned by this method will be in string form.  See the
   * method getTestAnnotation() for a version that returns annotations in XML form.
   *
   * @return the annotation of this TSB object as a character string.
   *
   * @see getTestAnnotation()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  std::string getTestAnnotationString () const;


  /**
   * Returns a list of the XML Namespaces declared on the TSB document
   * owning this object.
   *
   * The TSBNamespaces object encapsulates TSB Level/Version/namespaces
   * information.  It is used to communicate the TSB Level, Version, and (in
   * Level&nbsp;3) packages used in addition to TSB Level&nbsp;3 Core.
   *
   * @return the XML Namespaces associated with this TSB object, or @c NULL
   * in certain very usual circumstances where a namespace is not set.
   *
   * @see getLevel()
   * @see getVersion()
   */
  virtual const  XMLNamespaces* getNamespaces() const ;


  /**
   * Returns a list of the XML Namespaces declared on the TSB document
   * owning this object.
   *
   * The TSBNamespaces object encapsulates TSB Level/Version/namespaces
   * information.  It is used to communicate the TSB Level, Version, and (in
   * Level&nbsp;3) packages used in addition to TSB Level&nbsp;3 Core.
   *
   * @return the XML Namespaces associated with this TSB object, or @c NULL
   * in certain very usual circumstances where a namespace is not set.
   *
   * @see getLevel()
   * @see getVersion()
   */
  virtual  XMLNamespaces* getNamespaces();


  /**
   * Returns the TSBDocument object containing this object instance.
   *
   * This method allows the caller to obtain the TSBDocument for the
   * current object.
   * 
   * @return the parent TSBDocument object of this TSB object.
   *
   * @see getParentTSBObject()
   * @see getModel()
   */
  const TSBDocument* getTSBDocument () const;


  /**
   * Returns the TSBDocument object containing this object instance.
   *
   * This method allows the caller to obtain the TSBDocument for the
   * current object.
   * 
   * @return the parent TSBDocument object of this TSB object.
   *
   * @see getParentTSBObject()
   * @see getModel()
   */
  TSBDocument* getTSBDocument ();


  /**
   * Returns the parent TSB object containing this object.
   *
   * This returns the immediately-containing object.  This method is
   * convenient when holding an object nested inside other objects in an
   * TSB model.  
   * 
   * @return the parent TSB object of this TSB object.
   *
   * @see getTSBDocument()
   * @see getModel()
   */
  TSBBase* getParentTSBObject();


  /**
   * Returns the parent TSB object containing this object.
   *
   * This returns the immediately-containing object.  This method is
   * convenient when holding an object nested inside other objects in an
   * TSB model.  
   * 
   * @return the parent TSB object of this TSB object.
   *
   * @see getTSBDocument()
   * @see getModel()
   */
  const TSBBase* getParentTSBObject() const;


  /**
   * Returns the first ancestor object that has the given TSB type code.
   *
   * @if clike LibTSB attaches an identifying code to every kind of TSB
   * object.  These are known as <em>TSB type codes</em>.  The set of
   * possible type codes is defined in the enumeration #TSBTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * TSB_. @endif@if java LibTSB attaches an identifying code to every
   * kind of TSB object.  These are known as <em>TSB type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libTSB, the type codes are defined as
   * static integer constants in the interface class {@link
   * libtsbConstants}.  The names of the type codes all begin with the
   * characters @c TSB_. @endif@if python LibTSB attaches an identifying
   * code to every kind of TSB object.  These are known as <em>TSB type
   * codes</em>.  In the Python language interface for libTSB, the type
   * codes are defined as static integer constants in the interface class
   * @link libtsb@endlink.  The names of the type codes all begin with the
   * characters @c TSB_. @endif@if csharp LibTSB attaches an identifying
   * code to every kind of TSB object.  These are known as <em>TSB type
   * codes</em>.  In the C# language interface for libTSB, the type codes
   * are defined as static integer constants in the interface class @link
   * libtsbcs.libtsb libtsb@endlink.  The names of the type codes all begin with
   * the characters @c TSB_. @endif@~
   *
   * This method searches the tree of objects that are parents of this
   * object, and returns the first one that has the given TSB type code from 
   * the given @p pkgName.
   *
   * @param type the TSB type code of the object sought
   *
   * @return the ancestor TSB object of this TSB object that corresponds
   * to the given @if clike #TSBTypeCode_t value@else TSB object type
   * code@endif, or @c NULL if no ancestor exists.
   */
  TSBBase* getAncestorOfType(int type);


  /**
   * Returns the first ancestor object that has the given TSB type code.
   *
   * @if clike LibTSB attaches an identifying code to every kind of TSB
   * object.  These are known as <em>TSB type codes</em>.  The set of
   * possible type codes is defined in the enumeration #TSBTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * TSB_. @endif@if java LibTSB attaches an identifying code to every
   * kind of TSB object.  These are known as <em>TSB type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libTSB, the type codes are defined as
   * static integer constants in the interface class {@link
   * libtsbConstants}.  The names of the type codes all begin with the
   * characters @c TSB_. @endif@if python LibTSB attaches an identifying
   * code to every kind of TSB object.  These are known as <em>TSB type
   * codes</em>.  In the Python language interface for libTSB, the type
   * codes are defined as static integer constants in the interface class
   * @link libtsb@endlink.  The names of the type codes all begin with the
   * characters @c TSB_. @endif@if csharp LibTSB attaches an identifying
   * code to every kind of TSB object.  These are known as <em>TSB type
   * codes</em>.  In the C# language interface for libTSB, the type codes
   * are defined as static integer constants in the interface class @link
   * libtsbcs.libtsb libtsb@endlink.  The names of the type codes all begin with
   * the characters @c TSB_. @endif@~
   *
   * This method searches the tree of objects that are parents of this
   * object, and returns the first one that has the given TSB type code from 
   * the given @p pkgName.
   *
   * @param type the TSB type code of the object sought
   *
   * @return the ancestor TSB object of this TSB object that corresponds
   * to the given @if clike #TSBTypeCode_t value@else TSB object type
   * code@endif, or @c NULL if no ancestor exists.
   *
   */
  const TSBBase* getAncestorOfType(int type) const;


  /**
   * Returns the line number on which this object first appears in the XML
   * representation of the TSB document, or '0' if the object was created,
   * not read from a file.
   *
   * @return the line number of this TSB object, or '0' if no such value.
   *
   * @note The line number for each construct in an TSB model is set upon
   * reading the model.  The accuracy of the line number depends on the
   * correctness of the XML representation of the model, and on the
   * particular XML parser library being used.  The former limitation
   * relates to the following problem: if the model is actually invalid
   * XML, then the parser may not be able to interpret the data correctly
   * and consequently may not be able to establish the real line number.
   * The latter limitation is simply that different parsers seem to have
   * their own accuracy limitations, and out of all the parsers supported
   * by libTSB, none have been 100% accurate in all situations. (At this
   * time, libTSB supports the use of <a target="_blank"
   * href="http://xmlsoft.org">libxml2</a>, <a target="_blank"
   * href="http://expat.sourceforge.net/">Expat</a> and <a target="_blank"
   * href="http://xerces.apache.org/xerces-c/">Xerces</a>.)
   *
   * @see getColumn()
   */
  unsigned int getLine () const;


  /**
   * Returns the column number on which this object first appears in the XML
   * representation of the TSB document, or '0' if the object was created,
   * not read from a file.
   * 
   * @return the column number of this TSB object, or '0' if no such value.
   * 
   * @note The column number for each construct in an TSB model is set
   * upon reading the model.  The accuracy of the column number depends on
   * the correctness of the XML representation of the model, and on the
   * particular XML parser library being used.  The former limitation
   * relates to the following problem: if the model is actually invalid
   * XML, then the parser may not be able to interpret the data correctly
   * and consequently may not be able to establish the real column number.
   * The latter limitation is simply that different parsers seem to have
   * their own accuracy limitations, and out of all the parsers supported
   * by libTSB, none have been 100% accurate in all situations. (At this
   * time, libTSB supports the use of <a target="_blank"
   * href="http://xmlsoft.org">libxml2</a>, <a target="_blank"
   * href="http://expat.sourceforge.net/">Expat</a> and <a target="_blank"
   * href="http://xerces.apache.org/xerces-c/">Xerces</a>.)
   * 
   * @see getLine()
   */
  unsigned int getColumn () const;


  /**
   * Predicate returning @c true if this object's "metaid" attribute is set.
   *
   * @return @c true if the "metaid" attribute of this TSB object is
   * set, @c false otherwise.
   *
   * @see getMetaId()
   * @see setMetaId(const std::string& metaid)
   */
  bool isSetMetaId () const;


  /**
   * Predicate returning @c true if this object's "id" attribute is set.
   *
   * @return @c true if the "id" attribute of this TSB object is
   * set, @c false otherwise.
   *
   * @see getId()
   */
  virtual bool isSetId() const;

  /**
   * Predicate returning @c true if this
   * object's "notes" subelement exists and has content.
   *
   * The optional TSB element named "notes", present on every major TSB
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type TSBBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libTSB provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode xhtml@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://tsb.org/Documents/Specifications">TSB specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The TSB Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @return @c true if a "notes" subelement exists, @c false otherwise.
   * 
   * @see getNotes()
   * @see getNotesString()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  bool isSetNotes () const;


  /**
   * Predicate returning @c true if this
   * object's "testAnnotation" subelement exists and has content.
   *
   * Whereas the TSBBase "notes" subelement is a container for content to be
   * shown directly to humans, the "testAnnotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from TSBBase can have its own value for
   * "testAnnotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * @return @c true if a "testAnnotation" subelement exists, @c false
   * otherwise.
   * 
   * @see getTestAnnotation()
   * @see getTestAnnotationString()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  bool isSetTestAnnotation () const;


  /**
   * Sets the value of the meta-identifier attribute of this object.
   *
   * @copydetails doc_what_is_metaid 
   *
   * The string @p metaid is copied.  
   *
   * @param metaid the identifier string to use as the value of the
   * "metaid" attribute
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
   * 
   * @see getMetaId()
   * @see isSetMetaId()
   */
  int setMetaId (const std::string& metaid);


  /**
  /**
   * Sets the value of the "id" attribute of this TSB object.
   *
   * @copydetails doc_set_id
   */
  virtual int setId(const std::string& sid);


  /**
   * Sets the value of the "testAnnotation" subelement of this TSB object.
   *
   * The content of @p annotation is copied, and any previous content of
   * this object's "testAnnotation" subelement is deleted.
   * 
   * Whereas the TSBBase "notes" subelement is a container for content to be
   * shown directly to humans, the "testAnnotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from TSBBase can have its own value for
   * "testAnnotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * Call this method will result in any existing content of the
   * "testAnnotation" subelement to be discarded.  Unless you have taken steps
   * to first copy and reconstitute any existing annotations into the @p
   * annotation that is about to be assigned, it is likely that performing
   * such wholesale replacement is unfriendly towards other software
   * applications whose annotations are discarded.  An alternative may be
   * to use TSBBase::appendTestAnnotation(const XMLNode* annotation) or
   * TSBBase::appendTestAnnotation(const std::string& annotation).
   *
   * @param annotation an XML structure that is to be used as the new content
   * of the "testAnnotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   *
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  virtual int setTestAnnotation ( XMLNode* annotation);


  /**
   * Sets the value of the "testAnnotation" subelement of this TSB object.
   *
   * The content of @p annotation is copied, and any previous content of
   * this object's "testAnnotation" subelement is deleted.
   * 
   * Whereas the TSBBase "notes" subelement is a container for content to be
   * shown directly to humans, the "testAnnotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from TSBBase can have its own value for
   * "testAnnotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * Call this method will result in any existing content of the
   * "testAnnotation" subelement to be discarded.  Unless you have taken steps
   * to first copy and reconstitute any existing annotations into the @p
   * annotation that is about to be assigned, it is likely that performing
   * such wholesale replacement is unfriendly towards other software
   * applications whose annotations are discarded.  An alternative may be
   * to use TSBBase::appendTestAnnotation(const XMLNode* annotation) or
   * TSBBase::appendTestAnnotation(const std::string& annotation).
   *
   * @param annotation an XML string that is to be used as the content
   * of the "testAnnotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   *
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  virtual int setTestAnnotation (const std::string& annotation);


  /**
   * Appends the given @p annotation to the "testAnnotation" subelement of this
   * object.
   * 
   * Whereas the TSBBase "notes" subelement is a container for content to be
   * shown directly to humans, the "testAnnotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from TSBBase can have its own value for
   * "testAnnotation".  The element's content type is <a
   * target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type "any"</a>,
   * allowing essentially arbitrary well-formed XML data content.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * Unlike TSBBase::setTestAnnotation(const XMLNode* annotation) or
   * TSBBase::setTestAnnotation(const std::string& annotation), this method
   * allows other annotations to be preserved when an application adds its
   * own data.
   *
   * @param annotation an XML structure that is to be copied and appended
   * to the content of the "testAnnotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   *
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   * @see unsetTestAnnotation()
   */
  virtual int appendTestAnnotation (const  XMLNode* annotation);


  /**
   * Appends the given @p annotation to the "testAnnotation" subelement of this
   * object.
   *
   * Whereas the TSBBase "notes" subelement is a container for content to be
   * shown directly to humans, the "testAnnotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from TSBBase can have its own value for
   * "testAnnotation".  The element's content type is <a
   * target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type "any"</a>,
   * allowing essentially arbitrary well-formed XML data content.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * Unlike TSBBase::setTestAnnotation(const XMLNode* annotation) or
   * TSBBase::setTestAnnotation(const std::string& annotation), this method
   * allows other annotations to be preserved when an application adds its
   * own data.
   *
   * @param annotation an XML string that is to be copied and appended
   * to the content of the "testAnnotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   *
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see unsetTestAnnotation()
   */
  virtual int appendTestAnnotation (const std::string& annotation);


  /**
   * Removes the top-level element within the "testAnnotation" subelement of this
   * TSB object with the given name and optional URI.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * Calling this method allows a particular annotation element to be removed
   * whilst the remaining annotations remain intact.
   *
   * @param elementName a string representing the name of the top level
   * annotation element that is to be removed
   * @param elementURI an optional string that is used to check both the name
   * and URI of the top level element to be removed
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBTSB_ANNOTATION_NAME_NOT_FOUND LIBTSB_ANNOTATION_NAME_NOT_FOUND @endlink
   * @li @link OperationReturnValues_t#LIBTSB_ANNOTATION_NS_NOT_FOUND LIBTSB_ANNOTATION_NS_NOT_FOUND @endlink
   *
   * @see replaceTopLevelTestAnnotationElement(const XMLNode *)
   * @see replaceTopLevelTestAnnotationElement(const std::string&)
   */
  int removeTopLevelTestAnnotationElement(const std::string elementName,
                                      const std::string elementURI = "");


  /**
   * Replaces the given top-level element within the "testAnnotation"
   * subelement of this TSB object and with the annotation element supplied.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * This method determines the name of the element to be replaced from the
   * annotation argument. Functionally it is equivalent to calling
   * <code> removeTopLevelTestAnnotationElement(name); appendTestAnnotation(annotation_with_name);
   * </code> with the exception that the placement of the annotation element remains
   * the same.
   *
   * @param annotation XMLNode representing the replacement top level annotation
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBTSB_INVALID_OBJECT LIBTSB_INVALID_OBJECT @endlink
   *
   * @see removeTopLevelTestAnnotationElement(const std::string elementName, const std::string elementURI)
   * @see replaceTopLevelTestAnnotationElement(const std::string&)
   */
  int replaceTopLevelTestAnnotationElement(const  XMLNode* annotation);


  /**
   * Replaces the given top-level element within the "testAnnotation"
   * subelement of this TSB object and with the annotation element supplied.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * This method determines the name of the element to be replaced from the
   * annotation argument. Functionally it is equivalent to calling
   * <code> removeTopLevelTestAnnotationElement(name); appendTestAnnotation(annotation_with_name);
   * </code> with the exception that the placement of the annotation element remains
   * the same.
   *
   * @param annotation string representing the replacement top level annotation
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBTSB_INVALID_OBJECT LIBTSB_INVALID_OBJECT @endlink
   *
   * @see removeTopLevelTestAnnotationElement(const std::string elementName, const std::string elementURI)
   * @see replaceTopLevelTestAnnotationElement(const XMLNode*)
   */
  int replaceTopLevelTestAnnotationElement(const std::string& annotation);


  /**
   * Sets the value of the "notes" subelement of this TSB object.
   *
   * The content of @p notes is copied, and any existing content of this
   * object's "notes" subelement is deleted.
   *
   * The optional TSB element named "notes", present on every major TSB
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type TSBBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libTSB provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode xhtml@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://tsb.org/Documents/Specifications">TSB specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The TSB Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @param notes an XML structure that is to be used as the content of the
   * "notes" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_INVALID_OBJECT LIBTSB_INVALID_OBJECT @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int setNotes(const  XMLNode* notes);


  /**
   * Sets the value of the "notes" subelement of this TSB object to a copy
   * of the string @p notes.
   *
   * The content of @p notes is copied, and any existing content of this
   * object's "notes" subelement is deleted.
   *
   * The optional TSB element named "notes", present on every major TSB
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type TSBBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libTSB provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://tsb.org/Documents/Specifications">TSB specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The TSB Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @param notes an XML string that is to be used as the content of the
   * "notes" subelement of this object
   *
   * @param addXHTMLMarkup a boolean indicating whether to wrap the contents
   * of the @p notes argument with XHTML paragraph (<code>&lt;p&gt;</code>)
   * tags.  This is appropriate when the string in @p notes does not already
   * containg the appropriate XHTML markup.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_INVALID_OBJECT LIBTSB_INVALID_OBJECT @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int setNotes(const std::string& notes, bool addXHTMLMarkup = false);


  /**
   * Appends the given @p notes to the "notes" subelement of this object.
   *
   * The content of @p notes is copied.
   *
   * The optional TSB element named "notes", present on every major TSB
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type TSBBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libTSB provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://tsb.org/Documents/Specifications">TSB specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The TSB Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   * 
   * @param notes an XML node structure that is to appended to the content
   * of the "notes" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_INVALID_OBJECT LIBTSB_INVALID_OBJECT @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int appendNotes(const  XMLNode* notes);


  /**
   * Appends the given @p notes to the "notes" subelement of this object.
   *
   * The content of the parameter @p notes is copied.
   *
   * The optional TSB element named "notes", present on every major TSB
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type TSBBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libTSB provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://tsb.org/Documents/Specifications">TSB specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The TSB Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @param notes an XML string that is to appended to the content of
   * the "notes" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBTSB_INVALID_OBJECT LIBTSB_INVALID_OBJECT @endlink
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_FAILED LIBTSB_OPERATION_FAILED @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const XMLNode* notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int appendNotes(const std::string& notes);


  /** @cond doxygenLibtsbInternal */
  /**
   * Sets the parent TSBDocument of this TSB object.
   *
   * @param d the TSBDocument object to use
   *
   * @see connectToChild()
   * @if clike
   * @see enablePackageInternal()
   * @endif@~
   */
  virtual void setTSBDocument (TSBDocument* d);
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /**
   * Sets the parent TSB object of this TSB object.
   * (Creates a child-parent relationship by the child)
   * This function is called when a child element is
   * set/added/created by its parent element (e.g. by setXXX,
   * addXXX, createXXX, and connectToChild functions of the
   * parent element).
   *
   * @param parent the TSB object to use
   */
  virtual void connectToParent (TSBBase* parent);


  /**
   * Sets this TSB object to child TSB objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * Subclasses must override this function if they define
   * one ore more child elements.
   * Basically, this function needs to be called in
   * constructor, copy constructor, assignment operator.
   *
   * @if clike
   * @see setTSBDocument()
   * @see enablePackageInternal()
   * @endif@~
   */
  virtual void connectToChild ();

  /** @endcond */


  /**
   * Sets the namespaces relevant of this TSB object.
   *
   * The content of @p xmlns is copied, and this object's existing
   * namespace content is deleted.
   *
   * The TSBNamespaces object encapsulates TSB Level/Version/namespaces
   * information.  It is used to communicate the TSB Level, Version, and
   * (in Level&nbsp;3) packages used in addition to TSB Level&nbsp;3 Core.
   * 
   * @param xmlns the namespaces to set
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setNamespaces( XMLNamespaces* xmlns);


  /**
   * Unsets the value of the "metaid" attribute of this TSB object.
   *
   */
  int unsetMetaId ();


  /**
   * Unsets the value of the "id" attribute of this TSB object.
   *
   * @copydetails doc_unset_id
   */
  virtual int unsetId ();


  /**
   * Unsets the value of the "notes" subelement of this TSB object.
   *
   * The optional TSB element named "notes", present on every major TSB
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type TSBBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libTSB provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://tsb.org/Documents/Specifications">TSB specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The TSB Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int unsetNotes ();


  /**
   * Unsets the value of the "testAnnotation" subelement of this TSB object.
   *
   * Whereas the TSBBase "notes" subelement is a container for content to be
   * shown directly to humans, the "testAnnotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from TSBBase can have its own value for
   * "testAnnotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * TSB places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the TSB specifications for more details.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBTSB_OPERATION_SUCCESS LIBTSB_OPERATION_SUCCESS @endlink
   *
   * @see getTestAnnotation()
   * @see getTestAnnotationString()
   * @see isSetTestAnnotation()
   * @see setTestAnnotation(const XMLNode* annotation)
   * @see setTestAnnotation(const std::string& annotation)
   * @see appendTestAnnotation(const XMLNode* annotation)
   * @see appendTestAnnotation(const std::string& annotation)
   */
  int unsetTestAnnotation ();


  /**
   * Returns the TSB Level of the TSBDocument object containing @em this
   * object.
   * 
   * @return the TSB level of this TSB object.
   * 
   * @see getVersion()
   * @see getNamespaces()
   * @see getPackageVersion()
   */
  unsigned int getLevel () const;


  /**
   * Returns the Version within the TSB Level of the TSBDocument object
   * containing @em this object.
   * 
   * @return the TSB version of this TSB object.
   *
   * @see getLevel()
   * @see getNamespaces()
   */
  unsigned int getVersion () const;


  /**
   * Returns the libTSB type code for this object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @copydetails doc_additional_typecode_details
   *
   * @return the @if clike #TSBTypeCode_t value@else TSB object type
   * code@endif@~ of this TSB object, or @tsbconstant{TSB_UNKNOWN,
   * TSBTypeCode_t} (the default).  The latter is possible because
   * subclasses of TSBBase are not required to implement this method to return
   * a type code.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getPackageName()
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Predicate returning @c true if this object's level/version and namespace
   * values correspond to a valid TSB specification.
   *
   * @return @c true if the level, version and namespace values of this 
   * TSB object correspond to a valid set of values, @c false otherwise.
   */
  bool hasValidLevelVersionNamespaceCombination();

  
  /**
   * Returns the XML element name of this object.
   *
   * This is overridden by subclasses to return a string appropriate to the
   * TSB component.  For example, Model defines it as returning @c
   * "model", CompartmentType defines it as returning @c "compartmentType",
   * and so on.
   */
  virtual const std::string& getElementName () const = 0;


  /**
   * Returns a string consisting of a partial TSB corresponding to just
   * this object.
   * 
   * @return the partial TSB that describes this TSB object.
   *
   * @warning <span class="warning">This is primarily provided for testing
   * and debugging purposes.  It may be removed in a future version of
   * libTSB.</span>
   */
  char* toTSB();


  // ------------------------------------------------------------------

  #ifndef SWIG
   /** @cond doxygenLibtsbInternal */


   virtual int getAttribute(const std::string& attributeName, double& value) const;

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int getAttribute(const std::string& attributeName, bool& value) const;

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int getAttribute(const std::string& attributeName, unsigned int& value) const;

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int getAttribute(const std::string& attributeName, std::string& value) const;

  /** @endcond */

//   virtual int getAttribute(const std::string& attributeName, const char * value) const;


   virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int setAttribute(const std::string& attributeName, unsigned int value);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int setAttribute(const std::string& attributeName, const std::string& value);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

//   virtual int setAttribute(const std::string& attributeName, const char* value);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual TSBBase* createChildObject(const std::string& elementName);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual int addChildObject(const std::string& elementName, const TSBBase* element);

   /** @endcond */

   /** @cond doxygenLibtsbInternal */

   virtual TSBBase* removeChildObject(const std::string& elementName, const std::string& id);

   /** @endcond */

   /** @cond doxygenLibtsbInternal */

   virtual unsigned int getNumObjects(const std::string& objectName);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

   virtual TSBBase* getObject(const std::string& objectName, unsigned int index);

  /** @endcond */

  /** @cond doxygenLibtsbInternal */

  template<typename T> T getAttribute(const std::string& attributeName)
  {
    T result;
    getAttribute(attributeName, result);
    return result;
  }
  /** @endcond */

#endif /* SWIG */



  /** @cond doxygenLibtsbInternal */
  /**
   * Reads (initializes) this TSB object by reading from XMLInputStream.
   */
  void read ( XMLInputStream& stream);
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /**
   * Writes (serializes) this TSB object by writing it to XMLOutputStream.
   */
  virtual void write ( XMLOutputStream& stream) const;
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /**
   * Subclasses should override this method to write out their contained
   * TSB objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.  For example:@if clike
   * <pre>
   *   TSBBase::writeElements();
   *   mReactants.write(stream);
   *   mProducts.write(stream);
   *   ...
   * </pre>@endif@~
   */
  virtual void writeElements ( XMLOutputStream& stream) const;
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /* function returns true if component has all the required
   * attributes
   * needs to be overloaded for each component
   */
  virtual bool hasRequiredAttributes() const ;
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /* function returns true if component has all the required
   * elements
   * needs to be overloaded for each component
   */
  virtual bool hasRequiredElements() const ;
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /* function returns value if the object matches level/version/namespace
   */
  int checkCompatibility(const TSBBase * object) const ;
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /* sets the TSBnamespaces - internal use only*/
  int setTSBNamespaces(TSBNamespaces * tsbns);

  /* sets the TSBNamaepaces and owns the given object - internal use only */
  void setTSBNamespacesAndOwn(TSBNamespaces * disownedNs);
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /* gets the TSBnamespaces - internal use only*/
  virtual TSBNamespaces * getTSBNamespaces() const;
  /** @endcond */


  /**
   * Removes this object from its parent.
   *
   * If the parent was storing this object as a pointer, it is deleted.  If
   * not, it is simply cleared (as in TSBListOf objects).  This is a pure
   * virtual method, as every TSBBase element has different parents, and
   * therefore different methods of removing itself.  Will fail (and not
   * delete itself) if it has no parent object.  This function is designed to
   * be overridden, but for all objects whose parent is of the class TSBListOf,
   * the default implementation will work.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int removeFromParentAndDelete();


  /**
   * Returns @c true if this object's set of XML namespaces are the same
   * as the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * the same as @p sb's, @c false otherwise.
   */
  bool matchesTSBNamespaces(const TSBBase * sb);


  /**
   * Returns @c true if this object's set of XML namespaces are the same
   * as the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * the same as @p sb's, @c false otherwise.
   */
  bool matchesTSBNamespaces(const TSBBase * sb) const;


  /**
   * Returns @c true if this object's set of XML namespaces are a subset
   * of the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * a subset of @p sb's, @c false otherwise.
   */
  bool matchesRequiredTSBNamespacesForAddition(const TSBBase * sb);
  
  
  /**
   * Returns @c true if this object's set of XML namespaces are a subset
   * of the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * a subset of @p sb's, @c false otherwise.
   */
  bool matchesRequiredTSBNamespacesForAddition(const TSBBase * sb) const;


  /**
   * Sets the user data of this element.
   *
   * @copydetails doc_what_is_user_data
   *
   * @param userData specifies the new user data.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int setUserData(void *userData);


  /**
   * Returns the user data that has been previously set via setUserData().
   *
   * @copydetails doc_what_is_user_data
   *
   * @return the user data of this node, or @c NULL if no user data has been set.
   *
   * @if clike
   * @see ASTNode::setUserData(void *userData)
   * @endif@~
   */
  void *getUserData() const;

  /**
   * Predicate returning true or false depending on whether
   * the user data of this element has been set.
   *
   * @copydetails doc_what_is_user_data
   *
   * @return boolean, @c true if this object's user data has been set,
   * @c false otherwise.
   */
  bool isSetUserData() const;


  /**
   * Unsets the user data of this element.
   *
   * @copydetails doc_what_is_user_data
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUserData();


  /**
   * Returns the TSBErrorLog used to log errors while reading and
   * validating TSB.
   *
   * @return the TSBErrorLog used to log errors while reading and
   * validating TSB.
   */
  TSBErrorLog* getErrorLog ();

protected:

  bool getHasBeenDeleted() const;

  /** 
   * When overridden allows TSBBase elements to use the text included in between
   * the elements tags. The default implementation does nothing.
   * 
   * @param text the text string found between the element tags.
   */ 
  virtual void setElementText(const std::string &text);


  /** @cond doxygenLibtsbInternal */

  bool matchesCoreTSBNamespace(const TSBBase * sb);

  bool matchesCoreTSBNamespace(const TSBBase * sb) const;

  /**
   * Creates a new TSBBase object with the given TSB level, version.
   */
  TSBBase (unsigned int level, unsigned int version);


  /**
   * Creates a new TSBBase object with the given TSBNamespaces.
   * Only subclasses may create TSBBase objects.
   */
  TSBBase (TSBNamespaces* tsbns);


  /**
  * Copy constructor. Creates a copy of this TSBBase object.
   *
   * @param orig the object to copy.
  */
  TSBBase(const TSBBase& orig);


  /**
   * Subclasses should override this method to create, store, and then
   * return an TSB object corresponding to the next XMLToken in the
   * XMLInputStream.
   *
   * @return the TSB object corresponding to next XMLToken in the
   * XMLInputStream or @c NULL if the token was not recognized.
   */
  virtual TSBBase* createObject ( XMLInputStream& stream);


  /**
   * Predicate returning @c true if this
   * object's level/version and namespace values correspond to a valid
   * TSB specification.
   *
   * @param typecode the typecode for this element
   * @param xmlns the namespaces used by this element.
   *
   * @note  This function is provided as convenience method to be called from constructors. This 
   *        allows to use it in scenarios where the namespaces or typecode have not yet been initialized. 
   * 
   * @return @c true if the level, version and namespace values of this 
   * TSB object correspond to a valid set of values, @c false otherwise.
   */
  bool hasValidLevelVersionNamespaceCombination(int typecode,  XMLNamespaces *xmlns);


  /**
   * Subclasses should override this method to read (and store) XHTML,
   * MathML, etc. directly from the XMLInputStream.
   *
   * @return true if the subclass read from the stream, false otherwise.
   */
  virtual bool readOtherXML ( XMLInputStream& stream);


  /**
   * The TSB XML Schema is written such that the order of child elements
   * is significant.  LibTSB can read elements out of order.  If you
   * override this method to indicate the ordinal position of element with
   * respect to its siblings, libTSB will log an error if the element is
   * read out of order.
   *
   * @return the ordinal position of the element with respect to its
   * siblings or @c -1 (the default) to indicate the position is not
   * significant.
   */
  virtual int getElementPosition () const;


  /**
   * Convenience method for easily logging problems from within method
   * implementations.
   *
   * This is essentially a short form of getErrorLog()->logError(...)
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  void logError (  unsigned int       id
                 , const unsigned int level   = 2
                 , const unsigned int version = 3
                 , const std::string& details = "" );


  /**
   * Helper to log a common type of error.
   */
  void logUnknownAttribute( const std::string& attribute,
          const unsigned int level,
          const unsigned int version,
          const std::string& element,
          const std::string& prefix="");


  /**
   * Helper to log a common type of error.
   */
  void logUnknownElement( const std::string& element,
        const unsigned int level,
        const unsigned int version );

 
  /**
   * Helper to log a common type of error.
   */
  void logEmptyString( const std::string& attribute,
                       const unsigned int level,
                       const unsigned int version,
                       const std::string& element);


  /**
   * Subclasses should override this method to add the list of
   * expected attributes. Be sure to call your parents implementation 
   * of this method as well.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const  XMLAttributes& attributes, 
                               const  ExpectedAttributes& expectedAttributes);


  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.  For example:
   *
   *   TSBBase::writeAttributes(stream);
   *   stream.writeAttribute( "id"  , mId   );
   *   stream.writeAttribute( "name", mName );
   *   ...
   *
   * (NOTICE) this function doesn't write xmlns attributes.
   * Be sure to implement wirteXMLNS() function to write xmlns attributes.
   *
   */
  virtual void writeAttributes ( XMLOutputStream& stream) const;


  /**
   *
   * Subclasses should override this method to write their xmlns attriubutes
   * (if any) to the XMLOutputStream. 
   *
   */
  virtual void writeXMLNS ( XMLOutputStream& stream) const;


  /**
   * Checks that an TSB TSBListOf element is populated.  
   * If a listOf element has been declared with no elements, 
   * an error is logged.
   */
  void checkTSBListOfPopulated(TSBBase* object);

  /**
   * Checks that the given default namespace in the given element is valid.
   * If the given default namespace is not valid, an error is logged.
   */
  void checkDefaultNamespace(const  XMLNamespaces* xmlns, 
    const std::string& elementName, const std::string& prefix = "");

  /**
   * Checks the annotation does not declare an tsb namespace.
   * If the annotation declares an tsb namespace an error is logged.
   */
  void checkTestAnnotation();


  /**
   * Checks that the XHTML is valid.
   * If the xhtml does not conform to the specification of valid xhtml within
   * an tsb document, an error is logged.
   */
  void checkXHTML(const  XMLNode *);


  /**
   * Checks that the math ml ns has been declared
   */
  const std::string checkMathMLNamespace(const  XMLToken elem);

   /**
   * Sets the XML namespace to which this element belongs to.
   * For example, all elements that belong to TSB Level 3 Version 1 Core
   * must set the namespace to <code>"http://www.tsb.org/tsb/level3/version1/core"</code>; 
   * all elements that belong to Layout Extension Version 1 for TSB Level 3
   * Version 1 Core must set the namespace to 
   * <code>"http://www.tsb.org/tsb/level3/version1/layout/version1"</code>.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setElementNamespace(const std::string &uri);


  /**
   * Gets the XML namespace (URI) to which this element belongs to.
   */
  const std::string& getElementNamespace() const;

  std::string getURI() const;

  std::string getPrefix() const;

  /**
   * Return the TSB XML namespace prefix of this element.
   *
   * This will be the same as getPrefix() unless the element in question is
   * an element of an TSB extension class.
   *
   * @return the XML namespace prefix
   */
  std::string getTSBPrefix() const;


  /**
   * Returns the root element of the node tree to which this element is connected.
   *
   * @note The root element may not be an TSBDocument element. For example,
   * this element is the root element if this element doesn't have a parent
   * TSB object (i.e. mParentTSBObject is NULL)
   *
   * @see enablePackageInternal
   */
  TSBBase* getRootElement();


  // ------------------------------------------------------------------


  std::string     mMetaId;
  std::string     mId;
   XMLNode*        mNotes;
   XMLNode*        mTestAnnotation;
  TSBDocument*   mTSB;
  TSBNamespaces* mTSBNamespaces;
  void*           mUserData;

  unsigned int mLine;
  unsigned int mColumn;

  /* store the parent TSB object */
  TSBBase* mParentTSBObject;
  bool mHasBeenDeleted;

  std::string mEmptyString;

  //
  // namespace to which this TSBBase object belongs.
  // This variable can be publicly accessible by getElementNamespace function.
  //
  // For example, mURI of elements defined in L3 Core (or defined in Level 2 
  // or before) will be the URI defined in the corresponding TSB specification
  // (e.g. "http://www.tsb.org/tsb/level3/version1" for L3V1 Core); and mURI
  // will be "http://www.tsb.org/tsb/level3/version1/layout/version1" for 
  // elements defined in layout extension L3V1-V1.
  // The purpuse of this data member is to explicitly distinguish elements in core 
  // package and extension packages.
  // 
  // From the implementation point of view, this variable is needed to identify
  // if the prefix needs to be added when printing elements in some package extension.
  // (i.e. used in getPrefix function)
  //
  std::string mURI;

  
  /** @endcond */

private:
  /** @cond doxygenLibtsbInternal */
  /**
   * Stores the location (line and column) and any XML namespaces (for
   * roundtripping) declared on this TSB (XML) element.
   */
  void setTSBBaseFields (const  XMLToken& element);


  /**
   * Reads an annotation from the stream and returns true if successful.
   *
   * @return true if read an <annotation> element from the stream
   */
  bool readTestAnnotation ( XMLInputStream& stream);


  /**
   * Reads the notes from the stream and returns true if successful.
   *
   * @return true if read a <notes> element from the stream
   */
  bool readNotes ( XMLInputStream& stream);


  /** @endcond */
};

LIBTSB_CPP_NAMESPACE_END

#endif  /* __cplusplus */



#ifndef SWIG

LIBTSB_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Returns the value of the "metaid" attribute of the given TSBBase_t
 * structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @return the value of the "metaid" attribute of @p sb
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
const char *
TSBBase_getMetaId (TSBBase_t *sb);


/**
 * Returns the parent TSBDocument_t structure of the given TSBBase_t
 * structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @return the parent TSBDocument of this TSB structure.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
const TSBDocument_t *
TSBBase_getTSBDocument (TSBBase_t *sb);


/**
 * Returns the parent TSBBase_t structure of the given TSBBase_t
 * structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @return the parent TSBBase  of this TSB structure.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
const TSBBase_t *
TSBBase_getParentTSBObject (TSBBase_t *sb);


/**
 * Returns the ancestor TSBBase_t structure of the given TSBBase_t
 * structure that corresponds to the given type.
 *
 * This function allows any structure to determine its exact
 * location/function within a model. For example a
 * StoichiometryMath_t structure has ancestors of type SpeciesReference_t,
 * TSBListOf_t(Products/Reactants), Reaction_t, TSBListOfReactions_t and Model_t;
 * any of which can be accessed via this function.
 *
 * @param sb the TSBBase_t structure
 * @param type the typecode (int) of the structure to be returned
 *
 * @return the ancestor TSBBase_t structure of this TSB structure with
 * the corresponding typecode (int), NULL if there is no ancestor of
 * this type.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
const TSBBase_t *
TSBBase_getAncestorOfType (TSBBase_t *sb, int type);

/**
 * Returns the line number on which the given structure first appears in the
 * XML representation of the TSB document, or '0' if the object was created,
 * not read from a file.
 *
 * @param sb the TSBBase_t structure
 *
 * @return the line number of the given structure, or '0' if no such value.
 *
 * @see getColumn().
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
unsigned int
TSBBase_getLine (const TSBBase_t *sb);


/**
 * Returns the column number on which the given structure first appears in the
 * XML representation of the TSB document, or '0' if the object was created,
 * not read from a file.
 *
 * @param sb the TSBBase_t structure
 *
 * @return the column number of this TSB structure, or '0' if no such value.
 *
 * @see getLine().
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
unsigned int
TSBBase_getColumn (const TSBBase_t *sb);


/**
 * Returns the notes from given TSB structure.
 *
 * @param sb the given TSB structure.
 *
 * @return the XMLNode_t structure representing the notes from this structure.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
XMLNode_t *
TSBBase_getNotes (TSBBase_t *sb);


/**
 * Returns the notes string from given TSB structure.
 * The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @param sb the given TSB structure.
 *
 * @return the string (char*) representing the notes from this structure.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
char*
TSBBase_getNotesString (TSBBase_t *sb);


/**
 * Returns the annotation from given TSB structure.
 *
 * @param sb the given TSB structure.
 *
 * @return the XMLNode_t structure representing the annotation from this structure.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
XMLNode_t *
TSBBase_getTestAnnotation (TSBBase_t *sb);


/**
 * Returns the annotation string from given TSB structure.
 * The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @param sb the given TSB structure.
 *
 * @return the string (char*) representing the annotation from this structure.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
char*
TSBBase_getTestAnnotationString (TSBBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "metaid" attribute is set.
 *
 * @param sb the TSBBase_t structure to query
 *
 * @return nonzero (for true) if the "metaid" attribute of this TSB structure
 * is set, zero (for false) otherwise.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_isSetMetaId (const TSBBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "notes" subelement is set.
 *
 * @param sb the TSBBase_t structure to query
 *
 * @return nonzero (for true) if the "notes" subelement of this TSB structure
 * is set, zero (for false) otherwise.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_isSetNotes (const TSBBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "testAnnotation" subelement is set.
 *
 * @param sb the TSBBase_t structure to query
 *
 * @return nonzero (for true) if the "testAnnotation" subelement of this TSB structure
 * is set, zero (for false) otherwise.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_isSetTestAnnotation (const TSBBase_t *sb);


/**
 * Sets the value of the "metaid" attribute of the given structure.
 *
 * The string @p metaid is copied.  The value of @p metaid must be an
 * identifier conforming to the syntax defined by the XML 1.0 data type
 * ID.  Among other things, this type requires that a value is unique
 * among all the values of type XML ID in an TSBDocument_t.  Although TSB
 * only uses XML ID for the "metaid" attribute, callers should be careful
 * if they use XML ID's in XML portions of a model that are not defined
 * by TSB, such as in the application-specific content of the
 * "testAnnotation" subelement.
 *
 * @param sb the TSBBase_t structure
 *
 * @param metaid the identifier string to use as the value of the
 * "metaid" attribute
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with the metaid set to NULL is equivalent to
 * unsetting the "metaid" attribute.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setMetaId (TSBBase_t *sb, const char *metaid);


/**
 * Sets the namespaces relevant of this TSB structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @param xmlns the namespaces to set
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setNamespaces (TSBBase_t *sb, XMLNamespaces_t *xmlns);


/**
 * Sets the notes for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param notes the XMLNode_t structure respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setNotes (TSBBase_t *sb, XMLNode_t *notes);


/**
 * Sets the notes for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setNotesString (TSBBase_t *sb, const char *notes);


/**
 * Sets the notes for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setNotesStringAddMarkup (TSBBase_t *sb, const char *notes);


/**
 * Appends the notes for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param notes the XMLNode_t structure respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_appendNotes (TSBBase_t *sb, XMLNode_t *notes);


/**
 * Appends the notes for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_appendNotesString (TSBBase_t *sb, const char *notes);


/**
 * Sets the annotation for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param annotation the XMLNode_t structure respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setTestAnnotation (TSBBase_t *sb, XMLNode_t *annotation);


/**
 * Sets the annotation for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param annotation the string (const char*) respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_setTestAnnotationString (TSBBase_t *sb, const char *annotation);


/**
 * Appends the annotation for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param annotation the XMLNode_t structure respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_appendTestAnnotation (TSBBase_t *sb, XMLNode_t *annotation);


/**
 * Appends the annotation for the given TSB structure.
 *
 * @param sb the given TSB structure.
 * @param annotation the string (const char*) respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_appendTestAnnotationString (TSBBase_t *sb, const char *annotation);


/**
 * Unsets the "metaid" attribute of the given structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_unsetMetaId (TSBBase_t *sb);


/**
 * Unsets the "notes" subelement of the given structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_unsetNotes (TSBBase_t *sb);


/**
 * Unsets the "testAnnotation" subelement of the given structure.
 *
 * @param sb the TSBBase_t structure
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_unsetTestAnnotation (TSBBase_t *sb);


/**
 * Returns the TSB Level of the overall TSB document.
 *
 * @param sb the TSBBase_t structure to query
 *
 * @return the TSB level of the given structure.
 *
 * @see getVersion()
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
unsigned int
TSBBase_getLevel (const TSBBase_t *sb);


/**
 * Returns the Version within the TSB Level of the overall TSB document.
 *
 * @param sb the TSBBase_t structure to query
 *
 * @return the TSB version of the given structure.
 *
 * @see getLevel()
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
unsigned int
TSBBase_getVersion (const TSBBase_t *sb);


/**
 * Returns the libTSB type code for this structure.
 *
 * This method MAY return the typecode of this TSB structure or it MAY
 * return TSB_UNKNOWN.  That is, subclasses of TSBBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibTSB C interface where class and subclass
 * information is not readily available.
 *
 * @note In libTSB 5, the type of return value has been changed from
 * typecode (int) to int. The return value is one of enum values defined for
 * each package. For example, return values will be one of typecode (int) if
 * this structure is defined in TSB core package, return values will be one of
 * TSBLayoutTypeCode_t if this structure is defined in Layout extension
 * (i.e. similar enum types are defined in each package extension for each
 * TSBBase subclass) The value of each typecode can be duplicated between those
 * of different packages. Thus, to distinguish the typecodes of different
 * packages, not only the return value of getTypeCode() but also that of
 * getPackageName() must be checked.
 *
 * @param sb the TSBBase_t structure
 *
 * @return the typecode (int value) of this TSB structure or TSB_UNKNOWN
 * (default).
 *
 * @see getElementName()
 * @see getPackageName()
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_getTypeCode (const TSBBase_t *sb);


/**
 * Returns the XML element name of the given structure.
 *
 * This is overridden by subclasses to return a string appropriate to the
 * TSB component.  For example, Model defines it as returning "model",
 * CompartmentType defines it as returning "compartmentType", etc.
 *
 * @param sb the TSBBase_t structure
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
const char *
TSBBase_getElementName (const TSBBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the
 * structure's level/version and namespace values correspond to a valid
 * TSB specification.
 *
 * @param sb the TSBBase_t structure
 *
 * @return nonzero (true) if the level, version and namespace values of this
 * TSB structure correspond to a valid set of values, zero (false) otherwise.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int
TSBBase_hasValidLevelVersionNamespaceCombination(TSBBase_t *sb);


/**
 * Sets the user data of this node. This can be used by the application
 * developer to attach custom information to the node. In case of a deep
 * copy this attribute will passed as it is. The attribute will be never
 * interpreted by this class.
 *
 * @param sb defines the node of which the user data should be set.
 * @param userData specifies the new user data.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int 
TSBBase_setUserData(TSBBase_t* sb, void *userData);

/**
 * Returns the user data that has been previously set by setUserData().
 *
 * @param sb the TSBBase_t structure in question.
 * @return the user data of this node. NULL if no user data has been.
 * @see TSBBase_setUserData
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
void *
TSBBase_getUserData(const TSBBase_t* sb);

/**
 * Predicate returning nonzero true or false depending on whether the
 * structure's user data object has been set.
 *
 * @param sb defines the node of which the user data should be queried.
 *
 * @return nonzero (true) if the user data object of this
 * TSB structure has been set, zero (false) otherwise.
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int 
TSBBase_isSetUserData(const TSBBase_t* sb);

/**
 * Unsets the user data of this node. 
 *
 * @param sb defines the node of which the user data should be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBBase_t
 */
LIBTSB_EXTERN
int 
TSBBase_unsetUserData(TSBBase_t* sb);

END_C_DECLS
LIBTSB_CPP_NAMESPACE_END

#endif  /* !SWIG   */
#endif  /* TSBBase_h */
