#ifndef ListWrapper_h
#define ListWrapper_h

<verbatim>
#include <sbml/util/List.h>
</verbatim>
#include <sbml/common/extern.h>

LIBSBML_CPP_NAMESPACE_USE

/**
 *
 * ListWrapper : a wrapper template class for List class.
 */
template<typename IType>
class LIBSBML_EXTERN ListWrapper
{
  private:
    List *mList;
    bool mMemOwn;

  public:
    /**
     * Creates a new List.
     *
     * A ListXXX object is newly created (i.e. owned by the caller) and 
     * deleted by the destructor below if the constructor of this class 
     * invoked without an argument. 
     */
    ListWrapper() : mList(new List()), mMemOwn(true) {}


#ifndef SWIG
    /**
     * Creates a new List.
     * (internal implementation)
     *
     * An existing List object is given (i.e. not owned by the caller)
     * and stored.
     *
     */
    ListWrapper(List* list, bool memown = false) : mList(list), mMemOwn(memown) {}

    List* getList() { return mList; }
#endif


    /**
     * destructor
     */
    virtual ~ListWrapper() { if (mMemOwn) delete mList; }


    /**
     * Adds @p item to the end of this List.
     *
     * @param item a pointer to the item to be added.
     */
    void add(IType* item) 
    { 
      if (mList) mList->add(static_cast<void*>(item)); 
    }


    /**
     * Get the nth item in this List.
     *
     * If @p n > <code>listobj.size()</code>, this method returns @c 0.
     *
     * @return the nth item in this List.
     *
     * @see remove()
     *
     */
    IType* get(unsigned int n) const 
    { 
      return (mList) ? static_cast<IType*>(mList->get(n)) : 0; 
    }


    /**
     * Adds @p item to the beginning of this List.
     *
     * @param item a pointer to the item to be added.
     */
    void prepend(IType* item) 
    { 
      if (mList) mList->prepend(static_cast<void*>(item)); 
    }


    /**
     * Removes the nth item from this List and returns a pointer to it.
     *
     * If @p n > <code>listobj.size()</code>, this method returns @c 0.
     *
     * @return the nth item in this List.
     *
     * @see get()
     */
     IType* remove(unsigned int n) 
    { 
      return (mList) ? static_cast<IType*>(mList->remove(n)) : 0; 
    }


    /**
     * Get the number of items in this List.
     * 
     * @return the number of elements in this List.
     */
    unsigned int getSize() const 
    { 
      return (mList) ? mList->getSize() : 0; 
    }
};

#endif // ListWrapper_h
