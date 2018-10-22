/**
 * @file sedfwd.h
 * @brief Definition of sedfwd.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
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


#ifndef sedfwd_H__
#define sedfwd_H__


#include <sedml/common/libsedml-namespace.h>

/**
 * Forward declaration of all opaque C types.
 *
 * Declaring all types up-front avoids "redefinition of type Foo" compile
 * errors and allows our combined C/C++ headers to depend minimally upon each
 * other. Put another way, the type definitions below serve the same purpose as
 * "class Foo;" forward declarations in C++ code.
 */

#ifdef __cplusplus
# define CLASS_OR_STRUCT class
#else
# define CLASS_OR_STRUCT struct
#endif /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_BEGIN


typedef CLASS_OR_STRUCT SedDocument      SedDocument_t;
typedef CLASS_OR_STRUCT SedModel         SedModel_t;
typedef CLASS_OR_STRUCT SedChange        SedChange_t;
typedef CLASS_OR_STRUCT SedAddXML        SedAddXML_t;
typedef CLASS_OR_STRUCT SedSetValue      SedSetValue_t;
typedef CLASS_OR_STRUCT SedDataGenerator SedDataGenerator_t;
typedef CLASS_OR_STRUCT SedRepeatedTask  SedRepeatedTask_t;
typedef CLASS_OR_STRUCT SedSimulation    SedSimulation_t;
typedef CLASS_OR_STRUCT SedVectorRange   SedVectorRange_t;
typedef CLASS_OR_STRUCT SedBase          SedBase_t;
typedef CLASS_OR_STRUCT SedListOf        SedListOf_t;
typedef CLASS_OR_STRUCT SedReader        SedReader_t;
typedef CLASS_OR_STRUCT SedWriter        SedWriter_t;
typedef CLASS_OR_STRUCT SedNamespaces    SedNamespaces_t;
typedef CLASS_OR_STRUCT SedError         SedError_t;


LIBSEDML_CPP_NAMESPACE_END


#undef CLASS_OR_STRUCT


#endif /* !sedfwd_H__ */


