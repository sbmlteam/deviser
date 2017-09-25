/**
 * @file groups_example1.cpp
 * @brief Implementation of the example code for the groups package.
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

#include <iostream>

#include "sbml/SBMLTypes.h"
#include "sbml/packages/groups/common/GroupsExtensionTypes.h"


LIBSBML_CPP_NAMESPACE_USE


/**
 * ****************************************************
 *
 * CODE HERE IS EXPERIMENTAL AND MAY REQUIRE ADJUSTMENT
 *
 * ****************************************************
 */
/*
 * groups_example1
 */
int
main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: groups_example1\n";
    return 1;
  }

  SBMLNamespaces sbmlns(3, 1, "groups", 1);

  SBMLDocument *document = new SBMLDocument(&sbmlns);

  document->setPackageRequired("groups", false);

  Model* model = document->createModel();

  GroupsModelPlugin* mplugin =
    static_cast<GroupsModelPlugin*>(model->getPlugin("groups"));

  Group* g = mplugin->createGroup();

  g->setKind("FIXME");

  Member* m = g->createMember();

  writeSBML(document, "groups_example1.xml");
  delete document;

  return 0;
}


