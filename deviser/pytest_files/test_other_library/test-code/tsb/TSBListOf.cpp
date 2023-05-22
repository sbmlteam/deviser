/**
 * @file TSBListOf.cpp
 * @brief Implementation of the TSBListOf class.
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
 */


#include <algorithm>
#include <functional>

#include <tsb/TSBVisitor.h>
#include <tsb/TSBListOf.h>
#include <tsb/common/common.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBTSB_CPP_NAMESPACE_BEGIN
#ifdef __cplusplus

/*
 * Creates a new TSBListOf items.
 */
TSBListOf::TSBListOf (unsigned int level, unsigned int version)
: TSBBase(level,version)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw TSBConstructorException();
}


/*
 * Creates a new TSBListOf items.
 */
TSBListOf::TSBListOf (TSBNamespaces* tsbns)
: TSBBase(tsbns)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw TSBConstructorException();
}


/**
 * Used by the Destructor to delete each item in mItems.
 */
struct Delete : public unary_function<TSBBase*, void>
{
  void operator() (TSBBase* sb) { delete sb; }
};


/*
 * Destroys the given TSBListOf and its constituent items.
 */
TSBListOf::~TSBListOf ()
{
  for_each( mItems.begin(), mItems.end(), Delete() );
}


/**
 * Used by the Copy Constructor to clone each item in mItems.
 */
struct Clone : public unary_function<TSBBase*, TSBBase*>
{
  TSBBase* operator() (TSBBase* sb) { return sb->clone(); }
};


/*
 * Copy constructor. Creates a copy of this TSBListOf items.
 */
TSBListOf::TSBListOf (const TSBListOf& orig) : TSBBase(orig), mItems()
{
  mItems.resize( orig.size() );
  transform( orig.mItems.begin(), orig.mItems.end(), mItems.begin(), Clone() );
  connectToChild();
}


/*
 * Assignment operator
 */
TSBListOf& TSBListOf::operator=(const TSBListOf& rhs)
{
  if(&rhs!=this)
  {
    this->TSBBase::operator =(rhs);
    // Deletes existing items
    for_each( mItems.begin(), mItems.end(), Delete() );
    mItems.resize( rhs.size() );
    transform( rhs.mItems.begin(), rhs.mItems.end(), mItems.begin(), Clone() );
    connectToChild();
  }

  return *this;
}

/** @cond doxygenLibtsbInternal */
bool
TSBListOf::accept (TSBVisitor& v) const
{
  v.visit(*this, getItemTypeCode() );
  for (unsigned int n = 0 ; n < mItems.size() && mItems[n]->accept(v); ++n) ;
  v.leave(*this, getItemTypeCode() );

  return true;
}
/** @endcond */


/*
 * @return a (deep) copy of this TSBListOf items.
 */
TSBListOf*
TSBListOf::clone () const
{
  return new TSBListOf(*this);
}


/*
 * Inserts the item at the given location.  This TSBListOf items assumes
 * no ownership of item and will not delete it.
 */
int 
TSBListOf::insert(int location, const TSBBase* item)
{
  return insertAndOwn(location, item->clone());
}


/*
 * Inserts the item at the given location.  This TSBListOf items assumes
 * ownership of item and will delete it.
 */
int 
TSBListOf::insertAndOwn(int location, TSBBase* item)
{
  /* no list elements yet */
  if (this->getItemTypeCode() == TSB_UNKNOWN )
  {
    mItems.insert( mItems.begin() + location, item );
    item->connectToParent(this);
    return LIBTSB_OPERATION_SUCCESS;
  }
  else if (!isValidTypeForList(item))
  {
    return LIBTSB_INVALID_OBJECT;
  }
  else
  {
    mItems.insert( mItems.begin() + location, item );
    item->connectToParent(this);
    return LIBTSB_OPERATION_SUCCESS;
  }
}


/*
 * Adds item to the end of this TSBListOf items.  This TSBListOf items assumes
 * no ownership of item and will not delete it.
 */
int
TSBListOf::append (const TSBBase* item)
{
  TSBBase* clone = item->clone();
  int ret = appendAndOwn( clone );
  if (ret != LIBTSB_OPERATION_SUCCESS) 
  {
    delete clone;
  }
  return ret;
}


/*
 * Adds item to the end of this TSBListOf items.  This TSBListOf items assumes
 * ownership of item and will delete it.
 */
int
TSBListOf::appendAndOwn (TSBBase* item)
{
  /* no list elements yet */
  if (this->getItemTypeCode() == TSB_UNKNOWN )
  {
    mItems.push_back( item );
    item->connectToParent(this);
    return LIBTSB_OPERATION_SUCCESS;
  }
  else if (!isValidTypeForList(item))
  {
    return LIBTSB_INVALID_OBJECT;
  }
  else
  {
    mItems.push_back( item );
    item->connectToParent(this);
    return LIBTSB_OPERATION_SUCCESS;
  }
}

int TSBListOf::appendFrom(const TSBListOf* list)
{
  if (list==NULL) return LIBTSB_INVALID_OBJECT;
  
  if (getItemTypeCode() != list->getItemTypeCode()) 
  {
    return LIBTSB_INVALID_OBJECT;
  }
  
  int ret = LIBTSB_OPERATION_SUCCESS;
  
  for (unsigned int item=0; item<list->size(); item++) 
  {
    ret = appendAndOwn(list->get(item)->clone());
    if (ret != LIBTSB_OPERATION_SUCCESS) return ret;
  }
  return ret;
}

/*
 * @return the nth item in this TSBListOf items.
 */
const TSBBase*
TSBListOf::get (unsigned int n) const
{
  return (n < mItems.size()) ? mItems[n] : NULL;
}


/*
 * @return the nth item in this TSBListOf items.
 */
TSBBase*
TSBListOf::get (unsigned int n)
{
  return const_cast<TSBBase*>( static_cast<const TSBListOf&>(*this).get(n) );
}


TSBBase*
TSBListOf::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;
  
  for (unsigned int i = 0; i < size(); i++)
  {
    TSBBase* obj = get(i);
    if (obj->getId() == id)
    {
      return obj;
    }
    
    obj = obj->getElementBySId(id);
    
    if (obj != NULL) return obj;
  }

  return NULL;
}


TSBBase*
TSBListOf::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;
  
  for (unsigned int i = 0; i < size(); i++)
  {
    TSBBase* obj = get(i);
    if (obj->getMetaId() == metaid)
    {
      return obj;
    }
    
    obj = obj->getElementByMetaId(metaid);
    
    if (obj != NULL) return obj;
  }

  return NULL;
}


List*
TSBListOf::getAllElements()
{
  List* ret = new List();
  List* sublist = NULL;
  
  for (unsigned int i = 0; i < size(); i++) 
  {
    TSBBase* obj = get(i);
    ret->add(obj);
    sublist = obj->getAllElements();
    ret->transferFrom(sublist);
    delete sublist;
  }

  return ret;
}


/*
 * Removes all items in this TSBListOf object.
 *
 * If doDelete is true (default), all items in this TSBListOf object are deleted
 * and cleared, and thus the caller doesn't have to delete those items.
 * Otherwise, all items are just cleared from this TSBListOf object and the caller
 * is responsible for deleting all items (In this case, pointers to all items
 * should be stored elsewhere before calling this function by the caller).
 */
void
TSBListOf::clear (bool doDelete)
{
  if (doDelete)
    for_each( mItems.begin(), mItems.end(), Delete() );
  
  mItems.clear();
}


int TSBListOf::removeFromParentAndDelete()
{
  clear(true);
  unsetTestAnnotation();
  unsetMetaId();
  unsetNotes();
  return LIBTSB_OPERATION_SUCCESS;
}

/*
 * Removes the nth item from this TSBListOf items and returns a pointer to
 * it.  The caller owns the returned item and is responsible for deleting
 * it.
 */
TSBBase*
TSBListOf::remove (unsigned int n)
{
  TSBBase* item = get(n);
  
  if (item != NULL) mItems.erase( mItems.begin() + n );
  
  return item;
}


/*
 * @return the number of items in this TSBListOf items.
 */
unsigned int
TSBListOf::size () const
{
  return (unsigned int)mItems.size();
}


/**
 * Used by TSBListOf::setTSBDocument().
 */
struct SetTSBDocument : public unary_function<TSBBase*, void>
{
  TSBDocument* d;

  SetTSBDocument (TSBDocument* d) : d(d) { }
  void operator() (TSBBase* sbase) { sbase->setTSBDocument(d); }
};


/**
 * Used by TSBListOf::setParentTSBObject().
 */
struct SetParentTSBObject : public unary_function<TSBBase*, void>
{
  TSBBase* sb;

  SetParentTSBObject (TSBBase *sb) : sb(sb) { }
  void operator() (TSBBase* sbase) { sbase->connectToParent(sb); }
};

/** @cond doxygenLibtsbInternal */

/*
 * Sets the parent TSBDocument of this TSB object.
 */
void
TSBListOf::setTSBDocument (TSBDocument* d)
{
  TSBBase::setTSBDocument(d);
  for_each( mItems.begin(), mItems.end(), SetTSBDocument(d) );
}


/*
 * Sets this TSB object to child TSB objects (if any).
 * (Creates a child-parent relationship by the parent)
  */
void
TSBListOf::connectToChild()
{
  TSBBase::connectToChild();
  for_each( mItems.begin(), mItems.end(), SetParentTSBObject(this) );
}

/** @endcond */


/*
 * @return the typecode (int) of this TSB object or TSB_UNKNOWN
 * (default).
 */
int
TSBListOf::getTypeCode () const
{
  return TSB_LIST_OF;
}


/*
 * @return the typecode (int) of TSB objects contained in this TSBListOf or
 * TSB_UNKNOWN (default).
 */
int
TSBListOf::getItemTypeCode () const
{
  return TSB_UNKNOWN;
}


/*
 * @return the name of this element ie "listOf".
 
 */
const string&
TSBListOf::getElementName () const
{
  static const string name = "listOf";
  return name;
}


/**
 * Used by TSBListOf::writeElements().
 */
struct Write : public unary_function<TSBBase*, void>
{
  XMLOutputStream& stream;

  Write (XMLOutputStream& s) : stream(s) { }
  void operator() (TSBBase* sbase) { sbase->write(stream); }
};


/** @cond doxygenLibtsbInternal */
/*
 * Subclasses should override this method to write out their contained
 * TSB objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
TSBListOf::writeElements (XMLOutputStream& stream) const
{
  TSBBase::writeElements(stream);
  for_each( mItems.begin(), mItems.end(), Write(stream) );
}
/** @endcond */

/** @cond doxygenLibtsbInternal */
/**
 * Subclasses should override this method to get the list of
 * expected attributes.
 * This function is invoked from corresponding readAttributes()
 * function.
 */
void
TSBListOf::addExpectedAttributes(ExpectedAttributes& attributes)
{
  TSBBase::addExpectedAttributes(attributes);
}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
TSBListOf::readAttributes (const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)
{
  TSBBase::readAttributes(attributes,expectedAttributes);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v3 ->)
  // is read in TSBBase::readAttributes()
  //
}

void 
TSBListOf::writeAttributes (XMLOutputStream& stream) const
{
  TSBBase::writeAttributes(stream);
}


bool
TSBListOf::isValidTypeForList(TSBBase * item)
{
  bool match = false;

  match = (item->getTypeCode() == getItemTypeCode());

  return match;
}
/** @endcond */



#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBTSB_EXTERN
TSBListOf_t *
TSBListOf_create (unsigned int level, unsigned int version)
{
  return new(nothrow) TSBListOf(level,version);
}


LIBTSB_EXTERN
void
TSBListOf_free (TSBListOf_t *lo)
{
  if (lo != NULL)
  delete lo;
}


LIBTSB_EXTERN
TSBListOf_t *
TSBListOf_clone (const TSBListOf_t *lo)
{
  return (lo != NULL) ? static_cast<TSBListOf_t*>( lo->clone() ) : NULL;
}


LIBTSB_EXTERN
int
TSBListOf_append (TSBListOf_t *lo, const TSBBase *item)
{
  if (lo != NULL)
    return lo->append(item);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
int
TSBListOf_appendAndOwn (TSBListOf_t *lo, TSBBase_t *item)
{
  if (lo != NULL)
    return lo->appendAndOwn(item);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
int
TSBListOf_appendFrom (TSBListOf_t *lo, TSBListOf_t *list)
{
  if (lo != NULL)
    return lo->appendFrom(list);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
int
TSBListOf_insert (TSBListOf_t *lo, int location, const TSBBase_t *item)
{
  if (lo != NULL)
    return lo->insert(location, item);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
int
TSBListOf_insertAndOwn (TSBListOf_t *lo, int location, TSBBase_t *item)
{
  if (lo != NULL)
    return lo->insertAndOwn(location, item);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
TSBBase *
TSBListOf_get (TSBListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->get(n) : NULL;
}


LIBTSB_EXTERN
void
TSBListOf_clear (TSBListOf_t *lo, int doDelete)
{
  if (lo != NULL)
  lo->clear(doDelete);
}


LIBTSB_EXTERN
TSBBase *
TSBListOf_remove (TSBListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->remove(n) : NULL;
}


LIBTSB_EXTERN
unsigned int
TSBListOf_size (const TSBListOf_t *lo)
{
  return (lo != NULL) ? lo->size() : TSB_INT_MAX;
}


LIBTSB_EXTERN
int
TSBListOf_getItemTypeCode (const TSBListOf_t *lo)
{
  return (lo != NULL) ? lo->getItemTypeCode() : TSB_UNKNOWN;
}

/** @endcond */

LIBTSB_CPP_NAMESPACE_END

