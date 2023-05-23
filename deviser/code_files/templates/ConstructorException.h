#ifndef SBML_CONSTRUCTOR_EXCEPTION_H
#define SBML_CONSTRUCTOR_EXCEPTION_H

#include <common/extern.h>
#include <sbml/SBMLNamespaces.h>

#ifdef __cplusplus

#include <string>
#include <stdexcept>
#include <algorithm>

LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN SBMLConstructorException : public std::invalid_argument
{
public:

  /** @cond doxygenLibsbmlInternal */
  
  /* constructor */
  SBMLConstructorException (std::string errmsg = "");
  SBMLConstructorException (std::string errmsg, std::string sbmlErrMsg);
  SBMLConstructorException (std::string elementName, SBMLNamespaces* xmlns);
  virtual ~SBMLConstructorException () throw();
  
 /** @endcond */

  /**
   * Returns the message associated with this SBML exception.
   *
   * @return the message string.
   */
  const std::string getSBMLErrMsg() const { return mSBMLErrMsg; }

private:
  std::string mSBMLErrMsg;
};


LIBSBML_CPP_NAMESPACE_END

#endif /* __cplusplus */

#endif /* SBML_CONSTRUCTOR_EXCEPTION_H */

