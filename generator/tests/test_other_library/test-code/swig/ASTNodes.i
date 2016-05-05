/**
 * @file ASTNodes.i
 * @brief Base file
 * @author DEVISER
 */



%{

#include <sbml/math/ASTNode.h>
#include <sbml/math/MathML.h>
#include <sbml/math/L3FormulaFormatter.h>
#include <sbml/math/FormulaFormatter.h>
#include <sbml/math/FormulaParser.h>
#include <sbml/math/L3Parser.h>
#include <sbml/math/L3ParserSettings.h>

%}


%include sbml/math/ASTNode.h
%include sbml/math/MathML.h
%include sbml/math/FormulaParser.h
%include sbml/math/L3FormulaFormatter.h
%include sbml/math/FormulaFormatter.h
%include sbml/math/L3Parser.h
%include sbml/math/L3ParserSettings.h

