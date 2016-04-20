
#ifndef SBMLVisitor_h
#define SBMLVisitor_h


#ifdef __cplusplus


#include <sbml/SBMLTypeCodes.h>


LIBSBML_CPP_NAMESPACE_BEGIN

/**
 * Forward class name declarations avoid cyclic dependencies.
 */

class SBase;

class SBMLDocument;
class ListOf;



class SBMLVisitor
{
public:

  /**
   * Destructor method.
   */
  virtual ~SBMLVisitor ();

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SBMLDocument objects.
   *
   * @param x the SBMLDocument object to visit.
   */
  virtual void visit (const SBMLDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on ListOf objects.
   *
   * @param x the ListOf object to visit.
   *
   * @param type the object type code.
   */
  virtual void visit (const ListOf       &x, int type);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SBase objects.
   *
   * @param x the SBase object to visit.
   */
  virtual bool visit (const SBase                    &x);



  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SBMLDocument objects.
   *
   * @param x the SBMLDocument object to visit.
   */
  virtual void leave (const SBMLDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on Reaction objects.
   *
   * @param x the Reaction object to visit.
   */
  virtual void leave (const SBase     &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on ListOf objects.
   *
   * @param x the ListOf object to visit.
   *
   * @param type the object type code.
   *
   */
  virtual void leave (const ListOf &x, int type);
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SBMLVisitor_h */

