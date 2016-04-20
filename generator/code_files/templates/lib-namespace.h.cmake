/**
 * @file    libsbml-namespace.h
 * @brief   Defines C++ namespace of libSBML
 */
 

#ifndef LIBSBML_NAMESPACE_H
#define LIBSBML_NAMESPACE_H 1

<verbatim>
#ifndef SWIG
#include <sbml/common/libsbml-namespace.h>

LIBSBML_CPP_NAMESPACE_USE

#endif
</verbatim>
/*
 *
 * The idea of the following marcors are borrowed from 
 * Xerces-C++ XML Parser (http://xerces.apache.org/xerces-c/).
 *
 */

/* Define to enable libSBML C++ namespace */
#cmakedefine LIBSBML_USE_CPP_NAMESPACE 1


#if defined(__cplusplus) && defined(LIBSBML_USE_CPP_NAMESPACE) && !defined(SWIG)
  /* C++ namespace of libSBML */
  #define LIBSBML_CPP_NAMESPACE            libsbml
  #define LIBSBML_CPP_NAMESPACE_BEGIN      namespace LIBSBML_CPP_NAMESPACE {
  #define LIBSBML_CPP_NAMESPACE_END        }
  #define LIBSBML_CPP_NAMESPACE_USE        using namespace LIBSBML_CPP_NAMESPACE;
  #define LIBSBML_CPP_NAMESPACE_QUALIFIER  LIBSBML_CPP_NAMESPACE::

  namespace LIBSBML_CPP_NAMESPACE {}
#else
  #define LIBSBML_CPP_NAMESPACE 
  #define LIBSBML_CPP_NAMESPACE_BEGIN
  #define LIBSBML_CPP_NAMESPACE_END  
  #define LIBSBML_CPP_NAMESPACE_USE 
  #define LIBSBML_CPP_NAMESPACE_QUALIFIER 
#endif


#endif  /* LIBSBML_NAMESPACE_H */

