/**
 * @file TSBConstructorException.cpp
 * @brief Implementation of the TSBConstructorException class.
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


#include <tsb/TSBConstructorException.h>

#include <tsb/TSBNamespaces.h>
#include <xml/XMLNamespaces.h>
#include <xml/XMLOutputStream.h>

#include <string>
#include <sstream>

LIBTSB_CPP_NAMESPACE_BEGIN


/** @cond doxygenLibtsbInternal */

TSBConstructorException::TSBConstructorException(std::string errmsg) :
      std::invalid_argument("Level/version/namespaces combination is invalid")
    , mTSBErrMsg(errmsg)
{
}


TSBConstructorException::TSBConstructorException (std::string errmsg, std::string tsbErrMsg) :
    std::invalid_argument(errmsg)
  , mTSBErrMsg(tsbErrMsg)
{
}


TSBConstructorException::TSBConstructorException (std::string elementName, TSBNamespaces* tsbns) :
    std::invalid_argument("Level/version/namespaces combination is invalid")
  , mTSBErrMsg(elementName)
{
  if (tsbns == NULL) return;
  
  XMLNamespaces* xmlns = tsbns->getNamespaces();
  
  if (xmlns == NULL) return;
    
  std::ostringstream oss;
  XMLOutputStream xos(oss);
  xos << *xmlns;
  mTSBErrMsg.append(oss.str());
  
}


TSBConstructorException::~TSBConstructorException() throw()
{
}

/** @endcond */

LIBTSB_CPP_NAMESPACE_END

