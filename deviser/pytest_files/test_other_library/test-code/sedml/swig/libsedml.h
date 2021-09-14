/**
 * @file libsedml.h
 * @brief Definition of the libsedml class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */



#include <sedml/common/libsedml-version.h>
#include <sedml/common/SedOperationReturnValues.h>

#include <sedml/SedTypes.h>

#include "ListWrapper.h"

#include <sbml/SyntaxChecker.h>
#include <sbml/ExpectedAttributes.h>
#include <sbml/SBase.h>

#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>
#include <sbml/math/FormulaParser.h>
#include <sbml/math/FormulaFormatter.h>
#include <sbml/math/L3Parser.h>
#include <sbml/math/L3ParserSettings.h>

#include <xml/XMLAttributes.h>
#include <xml/XMLNamespaces.h>
#include <xml/XMLConstructorException.h>
#include <xml/XMLToken.h>
#include <xml/XMLNode.h>
#include <xml/XMLTriple.h>
#include <xml/XMLInputStream.h>
#include <xml/XMLOutputStream.h>
#include <xml/XMLError.h>
#include <xml/XMLErrorLog.h>

#include <numl/common/extern.h>
#include <numl/common/libnuml-namespace.h>
#include <numl/common/libnuml-version.h>
#include <numl/common/operationReturnValues.h>

#include <numl/NUMLNamespaces.h>
#include <numl/NUMLTypeCodes.h>
#include <numl/NUMLTypes.h>
#include <numl/NUMLError.h>
#include <numl/NUMLErrorLog.h>

