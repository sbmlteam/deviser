/**
 * @file TestSBMLError.h
 * @brief Definition of the TestSBMLError class.
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


#ifndef TestSBMLError_H__
#define TestSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


typedef enum
{
  TestUnknown                                                 = 10010100
, TestNSUndeclared                                            = 10010101
, TestElementNotInNs                                          = 10010102
, TestDuplicateComponentId                                    = 10010301
, TestIdSyntaxRule                                            = 10010302
, TestAttributeRequiredMissing                                = 10020101
, TestAttributeRequiredMustBeBoolean                          = 10020102
, TestAttributeRequiredMustHaveValue                          = 10020103
, TestSpeciesAllowedAttributes                                = 10020201
, TestSpeciesChargeMustBeInteger                              = 10020202
, TestSpeciesChemicalFormulaMustBeString                      = 10020203
, TestMyTestClassAllowedCoreAttributes                        = 10020301
, TestMyTestClassAllowedCoreElements                          = 10020302
, TestMyTestClassAllowedAttributes                            = 10020303
, TestMyTestClassNameMustBeString                             = 10020304
, TestMyTestClassNumMustBeNonNegativeInteger                  = 10020305
, TestMyTestClassNum2MustBeNonNegativeInteger                 = 10020306
, TestMyTestClassNum3MustBeInteger                            = 10020307
, TestMyTestClassNum1MustBeDouble                             = 10020308
, TestMyTestClassTrueMustBeBoolean                            = 10020309
, TestMyTestClassFalseMustBeBoolean                           = 10020310
, TestMyTestClassUnitMustBeUnit                               = 10020311
, TestMyTestClassRef1MustBeThing1                             = 10020312
, TestMyTestClassRef2MustBeThing2                             = 10020313
, TestMyTestClassRefUnitMustBeUnit                            = 10020314
, TestMyTestClassIdRefMustBeString                            = 10020315
, TestMyTestClassIdref1MustBeString                           = 10020316
, TestMyTestClassIdref2MustBeString                           = 10020317
, TestUnitAllowedCoreAttributes                               = 10020401
, TestUnitAllowedCoreElements                                 = 10020402
, TestUnitAllowedAttributes                                   = 10020403
, TestUnitUnitMustBeUnit                                      = 10020404
, TestMyLoTestAllowedCoreAttributes                           = 10020501
, TestMyLoTestAllowedCoreElements                             = 10020502
, TestMyLoTestAllowedAttributes                               = 10020503
, TestMyRequiredClassAllowedCoreAttributes                    = 10020601
, TestMyRequiredClassAllowedCoreElements                      = 10020602
, TestMyRequiredClassAllowedAttributes                        = 10020603
, TestMyRequiredClassNameMustBeString                         = 10020604
, TestMyRequiredClassNumMustBeNonNegativeInteger              = 10020605
, TestMyRequiredClassNum2MustBeNonNegativeInteger             = 10020606
, TestMyRequiredClassNum3MustBeInteger                        = 10020607
, TestMyRequiredClassNum1MustBeDouble                         = 10020608
, TestMyRequiredClassTrueMustBeBoolean                        = 10020609
, TestMyRequiredClassFalseMustBeBoolean                       = 10020610
, TestMyRequiredClassUnitMustBeUnit                           = 10020611
, TestMyRequiredClassRef1MustBeThing1                         = 10020612
, TestMyRequiredClassRef2MustBeThing2                         = 10020613
, TestMyRequiredClassRefUnitMustBeUnit                        = 10020614
, TestMyRequiredClassPosintMustBeNonNegativeInteger           = 10020615
, TestMyRequiredClassPosint2MustBeNonNegativeInteger          = 10020616
, TestMyRequiredClassPosint1MustBeNonNegativeInteger          = 10020617
, TestMyRequiredClassMetaidMustBeString                       = 10020618
, TestMyRequiredClassMetaid1MustBeString                      = 10020619
, TestMyRequiredClassNum4MustBeInteger                        = 10020620
, TestMyRequiredClassMetaidref1MustBeString                   = 10020621
, TestMyRequiredClassNotmetaidMustBeString                    = 10020622
, TestMyRequiredClassVectorDoubleMustBeString                 = 10020623
, TestMyRequiredClassVectorDouble1MustBeString                = 10020624
, TestMyRequiredClassVectorIntMustBeString                    = 10020625
, TestMyRequiredClassVectorInt1MustBeString                   = 10020626
, TestMyRequiredClassArrayDMustBeString                       = 10020627
, TestMyRequiredClassArrayIntMustBeString                     = 10020628
, TestArrayChildAllowedCoreAttributes                         = 10020701
, TestArrayChildAllowedCoreElements                           = 10020702
, TestArrayChildAllowedAttributes                             = 10020703
, TestArrayChildAllowedElements                               = 10020704
, TestArrayChildNumberMustBeString                            = 10020705
, TestContainerAllowedCoreAttributes                          = 10020801
, TestContainerAllowedCoreElements                            = 10020802
, TestContainerAllowedElements                                = 10020803
, TestContainerEmptyLOElements                                = 10020804
, TestContainerLOMyLoTestsAllowedCoreElements                 = 10020805
, TestContainerLOMyLoTestsAllowedCoreAttributes               = 10020806
, TestContainerLOMyLoTestsAllowedAttributes                   = 10020807
} TestSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !TestSBMLError_H__ */


