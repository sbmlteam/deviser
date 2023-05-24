/**
 * @file TSBVisitor.h
 * @brief Definition of the TSBVisitor class.
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
 * @class TSBVisitor
 * @sbmlbrief{} TODO:Definition of the TSBVisitor class.
 */



#ifndef TSBVisitor_h
#define TSBVisitor_h


#ifdef __cplusplus


#include <tsb/TSBTypeCodes.h>


LIBTSB_CPP_NAMESPACE_BEGIN

/**
 * Forward class name declarations avoid cyclic dependencies.
 */

class TSBBase;

class TSBDocument;
class TSBListOf;

class TSBComment;


class TSBVisitor
{
public:

  /**
   * Destructor method.
   */
  virtual ~TSBVisitor ();

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on TSBDocument objects.
   *
   * @param x the TSBDocument object to visit.
   */
  virtual void visit (const TSBDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on TSBListOf objects.
   *
   * @param x the TSBListOf object to visit.
   *
   * @param type the object type code.
   */
  virtual void visit (const TSBListOf       &x, int type);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on TSBBase objects.
   *
   * @param x the TSBBase object to visit.
   */
  virtual bool visit (const TSBBase                    &x);



/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on TSBBase objects.
 *
 * @param x the TSBBase object to visit.
 */
virtual bool visit (const TSBComment &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on TSBDocument objects.
   *
   * @param x the TSBDocument object to visit.
   */
  virtual void leave (const TSBDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on Reaction objects.
   *
   * @param x the Reaction object to visit.
   */
  virtual void leave (const TSBBase     &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on TSBListOf objects.
   *
   * @param x the TSBListOf object to visit.
   *
   * @param type the object type code.
   *
   */
  virtual void leave (const TSBListOf &x, int type);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on TSBBase objects.
 *
 * @param x the TSBBase object to leave.
 */
virtual void leave (const TSBComment &x);
};

LIBTSB_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* TSBVisitor_h */

