/**
 * @file local-packages-vers.i
 * @brief Casting to most specific packages object for java
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
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


#ifdef USE_VERS
%typemap(javacode) VersExtension
%{
  public SBasePlugin DowncastSBasePlugin(long cPtr, boolean owner)
  {
    if (cPtr == 0) return null;

    SBasePlugin sbp = new SBasePlugin(cPtr, false);
    SBase sb = sbp.getParentSBMLObject();

    switch ( sb.getTypeCode() )
    {
      case (int) libsbml.SBML_MODEL:
        return new VersModelPlugin(cPtr, owner);

      case (int) libsbml.SBML_SPECIES:
        return new VersSpeciesPlugin(cPtr, owner);

      case (int) libsbml.SBML_REACTION:
        return new VersReactionPlugin(cPtr, owner);

      default:
        return new SBasePlugin(cPtr, owner);
    }
  }

  public SBase DowncastSBase(long cPtr, boolean owner)
  {
    if (cPtr == 0) return null;

    SBase sb = new SBase(cPtr, false);
    switch ( sb.getTypeCode() )
    {
      case (int) libsbml.SBML_LIST_OF:
        String name = sb.getElementName();
        if (name.equals("listOfAnothers"))
        {
          return new ListOfAnothers(cPtr, owner);
        }
        else if (name.equals("listOfClassThrees"))
        {
          return new ListOfClassThrees(cPtr, owner);
        }

        return new ListOf(cPtr, owner);

      case (int) libsbml.CLASS_ONE:
        return new ClassOne(cPtr, owner);

      case (int) libsbml.CLASS_A:
        return new Another(cPtr, owner);

      case (int) libsbml.CLASS_B:
        return new BBB(cPtr, owner);

      case (int) libsbml.CLASS_TWO:
        return new ClassTwo(cPtr, owner);

      case (int) libsbml.CLASS_THREE:
        return new ClassThree(cPtr, owner);

      default:
        return new SBase(cPtr, owner);
    }
  }

%}

COVARIANT_RTYPE_CLONE(VersExtension)
COVARIANT_RTYPE_CLONE(ClassOne)
COVARIANT_RTYPE_CLONE(Another)
COVARIANT_RTYPE_CLONE(BBB)
COVARIANT_RTYPE_CLONE(ClassTwo)
COVARIANT_RTYPE_CLONE(ClassThree)
COVARIANT_RTYPE_CLONE(ListOfAnothers)
COVARIANT_RTYPE_CLONE(ListOfClassThrees)

COVARIANT_RTYPE_LISTOF_GET_REMOVE(Another)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(ClassThree)

SBMLCONSTRUCTOR_EXCEPTION(VersPkgNamespaces)
SBMLCONSTRUCTOR_EXCEPTION(ClassOne)
SBMLCONSTRUCTOR_EXCEPTION(Another)
SBMLCONSTRUCTOR_EXCEPTION(BBB)
SBMLCONSTRUCTOR_EXCEPTION(ClassTwo)
SBMLCONSTRUCTOR_EXCEPTION(ClassThree)
SBMLCONSTRUCTOR_EXCEPTION(ListOfAnothers)
SBMLCONSTRUCTOR_EXCEPTION(ListOfClassThrees)


#endif // USE_VERS

