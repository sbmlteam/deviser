/**
 * @file SedConstructorException.h
 * @brief Definition of the SedConstructorException class.
 * @author DEVISER
 *
 * @class 
 * @sbmlbrief{} TODO:Definition of the SedConstructorException class.
 */


#ifndef SEDML_CONSTRUCTOR_EXCEPTION_H
#define SEDML_CONSTRUCTOR_EXCEPTION_H

#include <sedml/common/extern.h>
#include <sedml/SedNamespaces.h>

#ifdef __cplusplus

#include <string>
#include <stdexcept>
#include <algorithm>

LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedConstructorException : public std::invalid_argument
{
public:

  /** @cond doxygenLibsedmlInternal */
  
  /* constructor */
  SedConstructorException (std::string errmsg = "");
  SedConstructorException (std::string errmsg, std::string sedmlErrMsg);
  SedConstructorException (std::string elementName, SedNamespaces* xmlns);
  virtual ~SedConstructorException () throw();
  
 /** @endcond */

  /**
   * Returns the message associated with this Sed exception.
   *
   * @return the message string.
   */
  const std::string getSedErrMsg() const { return mSedErrMsg; }

private:
  std::string mSedErrMsg;
};


LIBSEDML_CPP_NAMESPACE_END

#endif /* __cplusplus */

#endif /* SEDML_CONSTRUCTOR_EXCEPTION_H */

