/**
 * @file x_example1.cpp
 * @brief Implementation of the example code for the x package.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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
#include "sbml/packages/x/common/XExtensionTypes.h"


LIBSBML_CPP_NAMESPACE_USE


/*
 * x_example1
 */
int
main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: x_example1\n";
    return 1;
  }

  SBMLNamespaces sbmlns(3, 1, "x", 1);

  SBMLDocument *document = new SBMLDocument(&sbmlns);

  document->setPackageRequired("x", false);

  Model* model = document->createModel();

  XModelPlugin* mplugin = static_cast<XModelPlugin*>(model->getPlugin("x"));

  ContainerX* cx = mplugin->createContainerX();

  Fred* f = cx->createFred();

  f->setId("FIXME");

  writeSBML(document, "x_example1.xml");
  delete document;

  return 0;
}


