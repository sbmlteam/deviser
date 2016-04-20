/**
 * @file SedVisitor.h
 * @brief Definition of the SedVisitor class.
 * @author DEVISER
 *
 * @class 
 * @sbmlbrief{} TODO:Definition of the SedVisitor class.
 */



#ifndef SedVisitor_h
#define SedVisitor_h


#ifdef __cplusplus


#include <sedml/SedTypeCodes.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

/**
 * Forward class name declarations avoid cyclic dependencies.
 */

class SedBase;

class SedDocument;
class SedListOf;



class SedVisitor
{
public:

  /**
   * Destructor method.
   */
  virtual ~SedVisitor ();

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedDocument objects.
   *
   * @param x the SedDocument object to visit.
   */
  virtual void visit (const SedDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedListOf objects.
   *
   * @param x the SedListOf object to visit.
   *
   * @param type the object type code.
   */
  virtual void visit (const SedListOf       &x, int type);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedBase objects.
   *
   * @param x the SedBase object to visit.
   */
  virtual bool visit (const SedBase                    &x);



  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedDocument objects.
   *
   * @param x the SedDocument object to visit.
   */
  virtual void leave (const SedDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on Reaction objects.
   *
   * @param x the Reaction object to visit.
   */
  virtual void leave (const SedBase     &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedListOf objects.
   *
   * @param x the SedListOf object to visit.
   *
   * @param type the object type code.
   *
   */
  virtual void leave (const SedListOf &x, int type);
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SedVisitor_h */

