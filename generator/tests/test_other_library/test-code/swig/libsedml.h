/**
 * @file libsedml.h
 * @brief Definition of the libsedml class.
 * @author DEVISER
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

#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/xml/XMLConstructorException.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLTriple.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>

#include <numl/common/extern.h>
#include <numl/common/libnuml-namespace.h>
#include <numl/common/libnuml-version.h>
#include <numl/common/NUMLOperationReturnValues.h>

#include <numl/NUMLNamespaces.h>
#include <numl/NUMLTypeCodes.h>
#include <numl/NUMLTypes.h>
#include <numl/NUMLError.h>
#include <numl/NUMLErrorLog.h>

