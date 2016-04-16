/**
 * @file SedConstructorException.cpp
 * @brief Implementation of the SedConstructorException class.
 * @author DEVISER
 */


#include <sedml/SedConstructorException.h>

#include <sedml/SedNamespaces.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/xml/XMLOutputStream.h>

#include <string>
#include <sstream>

LIBSEDML_CPP_NAMESPACE_BEGIN


/** @cond doxygenLibsedmlInternal */

SedConstructorException::SedConstructorException(std::string errmsg) :
      std::invalid_argument("Level/version/namespaces combination is invalid")
    , mSedErrMsg(errmsg)
{
}


SedConstructorException::SedConstructorException (std::string errmsg, std::string sedmlErrMsg) :
    std::invalid_argument(errmsg)
  , mSedErrMsg(sedmlErrMsg)
{
}


SedConstructorException::SedConstructorException (std::string elementName, SedNamespaces* sedmlns) :
    std::invalid_argument("Level/version/namespaces combination is invalid")
  , mSedErrMsg(elementName)
{
  if (sedmlns == NULL) return;
  
  XMLNamespaces* xmlns = sedmlns->getNamespaces();
  
  if (xmlns == NULL) return;
    
  std::ostringstream oss;
  XMLOutputStream xos(oss);
  xos << *xmlns;
  mSedErrMsg.append(oss.str());
  
}


SedConstructorException::~SedConstructorException() throw()
{
}

/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

