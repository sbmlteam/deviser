/**
 * @file TSBVisitor.cpp
 * @brief Implementation of the TSBVisitor class.
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



#include <tsb/TSBVisitor.h>
#include <tsb/TSBTypes.h>

LIBTSB_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

TSBVisitor::~TSBVisitor ()
{
}


void
TSBVisitor::visit (const TSBDocument& x)
{
  visit( static_cast<const TSBBase&>(x) );
}


void
TSBVisitor::visit (const TSBListOf& x, int type)
{
  visit( static_cast<const TSBBase&>(x) );
}


bool
TSBVisitor::visit (const TSBBase& sb)
{
  return false;
}


/*
 * Visit the TSBComment
 */
bool
TSBVisitor::visit(const TSBComment& x)
{
  return visit(static_cast<const TSBBase&>(x));
}


void
TSBVisitor::leave (const TSBDocument& x)
{
}


void
TSBVisitor::leave (const TSBBase& sb)
{
}


void
TSBVisitor::leave (const TSBListOf& x, int type)
{
}


/*
 * Leave the TSBComment
 */
void
TSBVisitor::leave(const TSBComment& x)
{
}



#endif /* __cplusplus */


LIBTSB_CPP_NAMESPACE_END
