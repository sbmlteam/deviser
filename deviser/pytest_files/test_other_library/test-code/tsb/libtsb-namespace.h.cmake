/**
 * @file    libtsb-namespace.h
 * @brief   Defines C++ namespace of libTSB
 */
 

#ifndef LIBTSB_NAMESPACE_H
#define LIBTSB_NAMESPACE_H 1

/*
 *
 * The idea of the following marcors are borrowed from 
 * Xerces-C++ XML Parser (http://xerces.apache.org/xerces-c/).
 *
 */

/* Define to enable libTSB C++ namespace */
#cmakedefine LIBTSB_USE_CPP_NAMESPACE 1


#if defined(__cplusplus) && defined(LIBTSB_USE_CPP_NAMESPACE) && !defined(SWIG)
  /* C++ namespace of libTSB */
  #define LIBTSB_CPP_NAMESPACE            libtsb
  #define LIBTSB_CPP_NAMESPACE_BEGIN      namespace LIBTSB_CPP_NAMESPACE {
  #define LIBTSB_CPP_NAMESPACE_END        }
  #define LIBTSB_CPP_NAMESPACE_USE        using namespace LIBTSB_CPP_NAMESPACE;
  #define LIBTSB_CPP_NAMESPACE_QUALIFIER  LIBTSB_CPP_NAMESPACE::

  namespace LIBTSB_CPP_NAMESPACE {}
#else
  #define LIBTSB_CPP_NAMESPACE 
  #define LIBTSB_CPP_NAMESPACE_BEGIN
  #define LIBTSB_CPP_NAMESPACE_END  
  #define LIBTSB_CPP_NAMESPACE_USE 
  #define LIBTSB_CPP_NAMESPACE_QUALIFIER 
#endif


#endif  /* LIBTSB_NAMESPACE_H */

