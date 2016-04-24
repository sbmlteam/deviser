/**
 * @file sedmlfwd.h
 * @brief Definition of sedmlfwd.
 * @author DEVISER
 */


#ifndef sedmlfwd_H__
#define sedmlfwd_H__


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
typedef CLASS_OR_STRUCT SedBase          SedBase_t;
typedef CLASS_OR_STRUCT SedListOf        SedListOf_t;
typedef CLASS_OR_STRUCT SedReader        SedReader_t;
typedef CLASS_OR_STRUCT SedWriter        SedWriter_t;
typedef CLASS_OR_STRUCT SedNamespaces    SedNamespaces_t;
typedef CLASS_OR_STRUCT SedError         SedError_t;


LIBSEDML_CPP_NAMESPACE_END


#undef CLASS_OR_STRUCT


#endif /* !sedmlfwd_H__ */


