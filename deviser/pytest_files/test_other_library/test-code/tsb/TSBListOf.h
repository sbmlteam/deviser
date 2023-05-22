/**
 * @file TSBListOf.h
 * @brief Definition of the TSBListOf class.
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
 * @class TSBListOf
 * @sbmlbrief{} TODO:Definition of the TSBListOf class.
 */


#ifndef TSBListOf_h
#define TSBListOf_h


#include <tsb/common/extern.h>
#include <tsb/common/tsbfwd.h>
#include <tsb/TSBTypeCodes.h>


#ifdef __cplusplus


#include <vector>
#include <algorithm>
#include <functional>

#include <tsb/TSBBase.h>

LIBTSB_CPP_NAMESPACE_BEGIN

class TSBVisitor;


/** @cond doxygenLibtsbInternal */
/**
 * Used by TSBListOf::get() to lookup an TSBBase based by its id.
 */
#ifndef SWIG
template<class CNAME>
struct TSBIdEq : public std::unary_function<TSBBase*, bool>
{
  const std::string& id;

  TSBIdEq (const std::string& id) : id(id) { }
  bool operator() (TSBBase* sb) 
       { return static_cast <CNAME*> (sb)->getId() == id; }
};
#endif /* SWIG */
/** @endcond */


class LIBTSB_EXTERN TSBListOf : public TSBBase
{
public:

  /**
   * Creates a new TSBListOf object.
   *
   * @param level the TSB Level; if not assigned, defaults to the
   * value of TSB_DEFAULT_LEVEL.
   *
   * @param version the Version within the TSB Level; if not assigned,
   * defaults to the value of TSB_DEFAULT_VERSION.
   */
  TSBListOf (unsigned int level   = TSB_DEFAULT_LEVEL,
          unsigned int version = TSB_DEFAULT_VERSION);


  /**
   * Creates a new TSBListOf with a given TSBNamespaces object.
   *
   * @param tsbns the set of TSB namespaces that this TSBListOf should
   * contain.
   */
  TSBListOf (TSBNamespaces* tsbns);


  /**
   * Destroys this TSBListOf and the items inside it.
   */
  virtual ~TSBListOf ();


  /**
   * Copy constructor; creates a copy of this TSBListOf.
   *
   * @param orig the TSBListOf instance to copy.
   */
  TSBListOf (const TSBListOf& orig);


  /**
   * Assignment operator for TSBListOf.
   */
  TSBListOf& operator=(const TSBListOf& rhs);



  /** @cond doxygenLibtsbInternal */
  /**
   * Accepts the given TSBVisitor.
   *
   * @param v the TSBVisitor instance to be used.
   *
   * @return the result of calling <code>v.visit()</code>, which indicates
   * whether the Visitor would like to visit the next item in the
   * list.
   */
  virtual bool accept (TSBVisitor& v) const;
  /** @endcond */


  /**
   * Creates and returns a deep copy of this TSBListOf object.
   *
   * @return the (deep) copy of this TSBListOf object.
   */
  virtual TSBListOf* clone () const;


  /**
   * Adds an item to the end of this TSBListOf's list of items.
   *
   * This method makes a clone of the @p item handed to it.  This means that
   * when the TSBListOf object is destroyed, the original items will not be
   * destroyed.  For a method with an alternative ownership behavior, see the
   * TSBListOf::appendAndOwn(@if java TSBBase@endif) method.
   *
   * @param item the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see appendAndOwn(TSBBase* disownedItem)
   * @see appendFrom(const TSBListOf* list)
   */
  int append (const TSBBase* item);


  /**
   * Adds an item to the end of this TSBListOf's list of items.
   *
   * This method does not clone the @p disownedItem handed to it; instead, it assumes
   * ownership of it.  This means that when the TSBListOf is destroyed, the item
   * will be destroyed along with it.  For a method with an alternative
   * ownership behavior, see the TSBListOf::append(TSBBase* item) method.
   *
   * @param disownedItem the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const TSBBase* item)
   * @see appendFrom(const TSBListOf* list)
   */
  int appendAndOwn (TSBBase* disownedItem);


  /**
   * Adds a clone of a list of items to this TSBListOf's list.
   *
   * Note that because this clones the objects handed to it, the original
   * items will not be destroyed when this TSBListOf object is destroyed.
   *
   * @param list a list of items to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const TSBBase* item)
   * @see appendAndOwn(TSBBase* disownedItem)
   */
  virtual int appendFrom (const TSBListOf* list);


  /**
   * Inserts an item at a given position in this TSBListOf's list of items.
   *
   * This variant of the method makes a clone of the @p item handed to it.
   * This means that when the TSBListOf is destroyed, the original @p item will
   * <em>not</em> be destroyed.
   *
   * @param location the location in the list where to insert the item.
   * @param item the item to be inserted to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insertAndOwn(int location, TSBBase* item)
   */
  int insert (int location, const TSBBase* item);


  /**
   * Inserts an item at a given position in this TSBListOf's list of items.
   *
   * This variant of the method does not make a clone of the @p disownedItem handed to it.
   * This means that when the TSBListOf is destroyed, the original @p item
   * <em>will</em> be destroyed.
   *
   * @param location the location where to insert the item
   * @param disownedItem the item to be inserted to the list
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insert(int location, const TSBBase* item)
   */
  int insertAndOwn(int location, TSBBase* disownedItem);


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   *
   * @return the <em>n</em>th item in this TSBListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual const TSBBase* get (unsigned int n) const;


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   * 
   * @return the <em>n</em>th item in this TSBListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual TSBBase* get (unsigned int n);


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
   * Returns the first child element found with the given meta-identifier.
   *
   * @param metaid string representing the "metaid" attribute of the object
   * to find.
   *
   * @return the first element found with the given @p metaid, or @c NULL if
   * no such object is found.
   */
  virtual TSBBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child TSBBase objects.
   *
   * The values returned include all children of the objects in this TSBListOf
   * list, nested to an arbitrary depth.
   *
   * @return a List of pointers to all child objects.
   */
  virtual List* getAllElements();


  /**
   * Removes all items in this TSBListOf object.
   *
   * If parameter @p doDelete is @c true (default), all items in this TSBListOf
   * object are deleted and cleared, and thus the caller doesn't have to
   * delete those items.  Otherwise, all items are cleared only from this
   * TSBListOf object; the caller is still responsible for deleting the actual
   * items.  (In the latter case, callers are advised to store pointers to
   * all items elsewhere before calling this function.)
   *
   * @param doDelete if @c true (default), all items are deleted and cleared.
   * Otherwise, all items are just cleared and not deleted.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  void clear (bool doDelete = true);


  /**
   * Removes all items in this TSBListOf object and deletes its properties too.
   *
   * This performs a call to clear() with an argument of @c true (thus removing
   * all the child objects in the list), followed by calls to various libTSB
   * <code>unset<em>Foo</em></code> methods to delete everything else: CVTerm
   * objects, model history objects, etc.
   *
   * @if cpp Implementations of subclasses of TSBListOf may need to override
   * this method if different handling of child objects is needed.@endif@~
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int removeFromParentAndDelete();


  /**
   * Removes the <em>n</em>th item from this TSBListOf list of items and returns
   * it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the item to remove
   *
   * @see size()
   */
  virtual TSBBase* remove (unsigned int n);


  /**
   * Returns number of items in this TSBListOf list.
   *
   * @return the number of items in this TSBListOf items.
   */
  unsigned int size () const;


  /** @cond doxygenLibtsbInternal */
  /**
   * Sets the parent TSBDocument of this TSB object.
   *
   * @param d the TSBDocument that should become the parent of this
   * TSBListOf.
   */
  virtual void setTSBDocument (TSBDocument* d);
  /** @endcond */


  /** @cond doxygenLibtsbInternal */
  /**
   * Sets this TSB object to child TSB objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * Subclasses must override this function if they define
   * one ore more child elements.
   * Basically, this function needs to be called in
   * constructor, copy constructor and assignment operator.
   *
   * @if cpp
   * @see setTSBDocument()
   * @see enablePackageInternal()
   * @endif
   */
  virtual void connectToChild ();
  /** @endcond */


  /**
   * Returns the libTSB type code for this object, namely,
   * @tsbconstant{TSB_LIST_OF, TSBTypeCode_t}.
   * 
   * @copydetails doc_what_are_typecodes
   *
   * @return the TSB type code for this object:
   * @tsbconstant{TSB_LIST_OF, TSBTypeCode_t} (default).
   *
   * @note The various TSBListOf classes mostly differ from each other in what they
   * contain.  Hence, one must call getItemTypeCode() to fully determine the
   * class of this TSB object.
   *
   * @see getItemTypeCode()
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Get the type code of the objects contained in this TSBListOf.
   *
   * Classes that inherit from the TSBListOf class should override this method
   * to return the TSB type code for the objects contained in this TSBListOf.
   * If they do not, this method will return
   * @tsbconstant{TSB_UNKNOWN, TSBTypeCode_t}
   *
   * @return The TSBListOf base class contains no TSB objects, and therefore
   * this method returns @tsbconstant{TSB_UNKNOWN, TSBTypeCode_t}.
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode () const;


  /**
   * Returns the XML element name of this object, which for TSBListOf, is
   * always @c "listOf".
   *
   * @return the XML name of this element.
   */
  virtual const std::string& getElementName () const;


  /** @cond doxygenLibtsbInternal */
  /**
   * Subclasses should override this method to write out their contained
   * TSB objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;
  /** @endcond */


protected:
  /** @cond doxygenLibtsbInternal */
  typedef std::vector<TSBBase*>           ListItem;
  typedef std::vector<TSBBase*>::iterator ListItemIter;

  /**
   * Subclasses should override this method to get the list of
   * expected attributes.
   * This function is invoked from corresponding readAttributes()
   * function.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  
  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);

  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.  For example:
   *
   *   TSBBase::writeAttributes(stream);
   *   stream.writeAttribute( "id"  , mId   );
   *   stream.writeAttribute( "name", mName );
   *   ...
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;

  virtual bool isValidTypeForList(TSBBase * item);

  ListItem mItems;

  /** @endcond */
};

LIBTSB_CPP_NAMESPACE_END

#endif  /* __cplusplus */


#ifndef SWIG

LIBTSB_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * Creates a new instance of a TSBListOf_t structure.
 *
 * @param level an unsigned int, the TSB Level to assign to this
 * TSBListOf_t structure.
 *
 * @param version an unsigned int, the TSB Version to assign to this
 * TSBListOf_t structure.
 *
 * @return a pointer to the newly-created TSBListOf_t structure.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
TSBListOf_t *
TSBListOf_create (unsigned int level, unsigned int version);


/**
 * Frees the given TSBListOf_t structure.
 *
 * This function assumes each item in the list is derived from TSBBase_t.
 *
 * @param lo the TSBListOf_t structure to be freed.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
void
TSBListOf_free (TSBListOf_t *lo);


/**
 * Creates a deep copy of the given TSBListOf_t structure.
 *
 * @param lo the TSBListOf_t structure to be copied.
 *
 * @return a (deep) copy of the given TSBListOf_t structure, or a null
 * pointer if a failure occurred.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
TSBListOf_t *
TSBListOf_clone (const TSBListOf_t *lo);


/**
 * Adds a copy of a given item to the end of a TSBListOf_t list.
 *
 * @param lo the TSBListOf_t structure to which the @p item should be appended.
 * @param item the item to append to the list.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see TSBListOf_appendAndOwn()
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
int
TSBListOf_append (TSBListOf_t *lo, const TSBBase_t *item);


/**
 * Adds the given item to the end of a TSBListOf_t list.
 *
 * @param lo the TSBListOf_t structure to which the @p disownedItem should be appended.
 * @param disownedItem the item to append to the list.
 *
 * Unlike TSBListOf_append(), this function does not copy the @p disownedItem.
 * The given @p lo list will contain the original item.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see TSBListOf_append()
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
int
TSBListOf_appendAndOwn (TSBListOf_t *lo, TSBBase_t *disownedItem);


/**
 * Adds clones a list of items from one list to another.
 *
 * @param lo the TSBListOf_t list to which @p list will be appended.
 * @param list the list of items to append to @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
int
TSBListOf_appendFrom (TSBListOf_t *lo, TSBListOf_t *list);


/**
 * Inserts a copy of an item into a TSBListOf_t list at a given position.
 *
 * @param lo the list into which @p item will be inserted.
 * @param location the starting index for the @p item in the @p lo list.
 * @param item the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
int
TSBListOf_insert (TSBListOf_t *lo, int location, const TSBBase_t *item);


/**
 * Inserts an item into a TSBListOf_t list at a given position.
 *
 * Unlike TSBListOf_insert(), this function does not clone @p disownedItem before
 * inserting it into @p lo, which means that @p lo becomes the owner.
 *
 * @param lo the list into which @p disownedItem will be inserted.
 * @param location the starting index for the @p disownedItem in the @p lo list.
 * @param disownedItem the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
int
TSBListOf_insertAndOwn (TSBListOf_t *lo, int location, TSBBase_t *disownedItem);


/**
 * Returns the <em>n</em>th item of a given list.
 *
 * @param lo the list from which to retrieve the item.
 * @param n the index of the item to retrieve.
 *
 * @return the <em>n</em>th item in this TSBListOf items, or a null pointer if
 * the index number @p n refers to a nonexistent position in @p lo.
 *
 * @see TSBListOf_size()
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
TSBBase_t *
TSBListOf_get (TSBListOf_t *lo, unsigned int n);


/**
 * Removes all items in this TSBListOf_t structure.
 *
 * If @p doDelete is true (non-zero), all items in this TSBListOf_t structure
 * are both deleted and cleared, and thus the caller doesn't have to delete
 * those items.  Otherwise, if @p doDelete is false (zero), all items are
 * only cleared from this TSBListOf_t structure and the caller is responsible
 * for deleting all items.  (In the latter case, callers are advised to store
 * pointers to all items elsewhere before calling this function.)
 *
 * @param lo the TSBListOf_t structure to clear
 * @param doDelete whether to delete the items.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
void
TSBListOf_clear (TSBListOf_t *lo, int doDelete);


/**
 * Removes the <em>n</em>th item from this TSBListOf_t list and returns it.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list from which the item should be removed.
 * @param n the index number of the item to remove.
 *
 * @return the item removed, or a null pointer if no item existed at the
 * index @p n.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
TSBBase_t *
TSBListOf_remove (TSBListOf_t *lo, unsigned int n);


/**
 * Returns the number of items in this TSBListOf_t items.
 *
 * @param lo the TSBListOf_t structure to count.
 *
 * @return the number of items in @p lo.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
unsigned int
TSBListOf_size (const TSBListOf_t *lo);


/**
 * Get the type code of the objects contained in the given TSBListOf_t
 * structure.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @param lo the TSBListOf_t whose item type codes are sought.
 *
 * @return the type code corresponding to the objects in @p lo,
 * or @tsbconstant{TSB_UNKNOWN, TSBTypeCode_t}.
 *
 * @memberof TSBListOf_t
 */
LIBTSB_EXTERN
int
TSBListOf_getItemTypeCode (const TSBListOf_t *lo);


END_C_DECLS
LIBTSB_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* TSBListOf_h */

