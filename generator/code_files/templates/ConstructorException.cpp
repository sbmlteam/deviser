#include <sbml/SBMLConstructorException.h>

#include <sbml/SBMLNamespaces.h>
<verbatim>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/xml/XMLOutputStream.h>
</verbatim>

#include <string>
#include <sstream>

LIBSBML_CPP_NAMESPACE_BEGIN


/** @cond doxygenLibsbmlInternal */

SBMLConstructorException::SBMLConstructorException(std::string errmsg) :
      std::invalid_argument("Level/version/namespaces combination is invalid")
    , mSBMLErrMsg(errmsg)
{
}


SBMLConstructorException::SBMLConstructorException (std::string errmsg, std::string sbmlErrMsg) :
    std::invalid_argument(errmsg)
  , mSBMLErrMsg(sbmlErrMsg)
{
}


SBMLConstructorException::SBMLConstructorException (std::string elementName, SBMLNamespaces* sbmlns) :
    std::invalid_argument("Level/version/namespaces combination is invalid")
  , mSBMLErrMsg(elementName)
{
  if (sbmlns == NULL) return;
  
  XMLNamespaces* xmlns = sbmlns->getNamespaces();
  
  if (xmlns == NULL) return;
    
  std::ostringstream oss;
  XMLOutputStream xos(oss);
  xos << *xmlns;
  mSBMLErrMsg.append(oss.str());
  
}


SBMLConstructorException::~SBMLConstructorException() throw()
{
}

/** @endcond */

LIBSBML_CPP_NAMESPACE_END

