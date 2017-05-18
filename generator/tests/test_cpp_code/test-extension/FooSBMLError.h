/**
 * @file FooSBMLError.h
 * @brief Definition of the FooSBMLError class.
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


#ifndef FooSBMLError_H__
#define FooSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


typedef enum
{
  FooUnknown                                                  = 110100
, FooNSUndeclared                                             = 110101
, FooElementNotInNs                                           = 110102
, FooDuplicateComponentId                                     = 110301
, FooIdSyntaxRule                                             = 110302
, FooAttributeRequiredMissing                                 = 120101
, FooAttributeRequiredMustBeBoolean                           = 120102
, FooAttributeRequiredMustHaveValue                           = 120103
, FooModelAllowedElements                                     = 120201
, FooModelLOElementChildren                                   = 120202
, FooModelLOApplesAllowedCoreElements                         = 120203
, FooModelLOApplesAllowedCoreAttributes                       = 120204
, FooCompartmentAllowedElements                               = 120301
, FooCompartmentLOPearsAllowedCoreElements                    = 120302
, FooCompartmentLOPearsAllowedCoreAttributes                  = 120303
, FooSpeciesAllowedElements                                   = 120401
, FooSpeciesEmptyLOElements                                   = 120402
, FooSpeciesLOBananasAllowedCoreElements                      = 120403
, FooSpeciesLOBananasAllowedCoreAttributes                    = 120404
, FooAppleAllowedCoreAttributes                               = 120501
, FooAppleAllowedCoreElements                                 = 120502
, FooPearAllowedCoreAttributes                                = 120601
, FooPearAllowedCoreElements                                  = 120602
, FooBowlAllowedCoreAttributes                                = 120701
, FooBowlAllowedCoreElements                                  = 120702
, FooBowlAllowedElements                                      = 120703
, FooBowlLOPearsAllowedCoreElements                           = 120704
, FooBowlLOPearsAllowedCoreAttributes                         = 120705
, FooPlateAllowedCoreAttributes                               = 120801
, FooPlateAllowedCoreElements                                 = 120802
, FooPlateAllowedElements                                     = 120803
, FooPlateLOElementChildren                                   = 120804
, FooPlateLOApplesAllowedCoreElements                         = 120805
, FooPlateEmptyReqdLOElements                                 = 120806
, FooPlateLOBananasAllowedCoreElements                        = 120807
, FooPlateLOApplesAllowedCoreAttributes                       = 120808
, FooPlateLOBananasAllowedCoreAttributes                      = 120809
, FooBananaAllowedCoreAttributes                              = 120901
, FooBananaAllowedCoreElements                                = 120902
} FooSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !FooSBMLError_H__ */


