/**
 * @file spatial_example1.cpp
 * @brief Implementation of the example code for the spatial package.
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
#include "sbml/packages/spatial/common/SpatialExtensionTypes.h"


LIBSBML_CPP_NAMESPACE_USE


/**
 * ****************************************************
 *
 * CODE HERE IS EXPERIMENTAL AND MAY REQUIRE ADJUSTMENT
 *
 * ****************************************************
 */
/*
 * spatial_example1
 */
int
main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: spatial_example1\n";
    return 1;
  }

  SBMLNamespaces sbmlns(3, 1, "spatial", 1);

  SBMLDocument *document = new SBMLDocument(&sbmlns);

  document->setPackageRequired("spatial", true);

  Model* model = document->createModel();

  SpatialModelPlugin* mplugin =
    static_cast<SpatialModelPlugin*>(model->getPlugin("spatial"));

  Geometry* g = mplugin->createGeometry();

  g->setCoordinateSystem("FIXME");

  CoordinateComponent* cc = g->createCoordinateComponent();

  cc->setId("FIXME");
  cc->setType("FIXME");

  BoundaryMin* m = cc->createBoundaryMin();

  m->setId("FIXME");
  m->setValue(FIXME);

  BoundaryMax* m = cc->createBoundaryMax();

  m->setId("FIXME");
  m->setValue(FIXME);

  DomainType* dt = g->createDomainType();

  dt->setId("FIXME");
  dt->setSpatialDimensions(FIXME);

  Domain* d = g->createDomain();

  d->setId("FIXME");
  d->setDomainType("FIXME");

  InteriorPoint* ip = d->createInteriorPoint();

  ip->setCoord1(FIXME);

  AdjacentDomains* ad = g->createAdjacentDomains();

  ad->setId("FIXME");
  ad->setDomain1("FIXME");
  ad->setDomain2("FIXME");

  AnalyticGeometry* ag = g->createAnalyticGeometry();

  ag->setId("FIXME");
  ag->setIsActive(false);

  AnalyticVolume* av = ag->createAnalyticVolume();

  av->setId("FIXME");
  av->setFunctionType("FIXME");
  av->setDomainType("FIXME");

  ASTNode* math = SBML_parseL3Formula("TBC");
  av->setMath(math);

  SampledField* sf = g->createSampledField();

  sf->setId("FIXME");
  sf->setDataType("FIXME");
  sf->setNumSamples1(FIXME);
  sf->setInterpolationType("FIXME");
  sf->setCompression("FIXME");
  sf->setSamples("FIXME");
  sf->setSamplesLength(FIXME);

  Compartment* compartment = document->createCompartment();

  SpatialCompartmentPlugin* cplugin =
    static_cast<SpatialCompartmentPlugin*>(compartment->getPlugin("spatial"));

  CompartmentMapping* cm = cplugin->createCompartmentMapping();

  cm->setId("FIXME");
  cm->setDomainType("FIXME");
  cm->setUnitSize(FIXME);

  Species* species = document->createSpecies();

  SpatialSpeciesPlugin* splugin =
    static_cast<SpatialSpeciesPlugin*>(species->getPlugin("spatial"));

  Parameter* parameter = document->createParameter();

  SpatialParameterPlugin* pplugin =
    static_cast<SpatialParameterPlugin*>(parameter->getPlugin("spatial"));

  SpatialSymbolReference* ssr = pplugin->createSpatialSymbolReference();

  ssr->setSpatialRef("FIXME");

  AdvectionCoefficient* ac = pplugin->createAdvectionCoefficient();

  ac->setVariable("FIXME");
  ac->setCoordinate("FIXME");

  BoundaryCondition* bc = pplugin->createBoundaryCondition();

  bc->setVariable("FIXME");
  bc->setType("FIXME");

  DiffusionCoefficient* dc = pplugin->createDiffusionCoefficient();

  dc->setVariable("FIXME");
  dc->setType("FIXME");

  Reaction* reaction = document->createReaction();

  SpatialReactionPlugin* rplugin =
    static_cast<SpatialReactionPlugin*>(reaction->getPlugin("spatial"));

  writeSBML(document, "spatial_example1.xml");
  delete document;

  return 0;
}


