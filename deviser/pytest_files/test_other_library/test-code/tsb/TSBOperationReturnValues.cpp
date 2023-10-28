/**
 * @file TSBOperationReturnValues.cpp
 * @brief Implementation of the TSBOperationReturnValues class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */



#include <stdlib.h>
#include <tsb/common/TSBOperationReturnValues.h>

LIBTSB_CPP_NAMESPACE_BEGIN

static TSBOperationReturnValues_t TSB_OPERATION_RETURN_VALUES_INDICES[] = 
{
    LIBTSB_OPERATION_SUCCESS
  , LIBTSB_INDEX_EXCEEDS_SIZE
  , LIBTSB_UNEXPECTED_ATTRIBUTE
  , LIBTSB_OPERATION_FAILED
  , LIBTSB_INVALID_ATTRIBUTE_VALUE
  , LIBTSB_INVALID_OBJECT
  , LIBTSB_DUPLICATE_OBJECT_ID
  , LIBTSB_LEVEL_MISMATCH
  , LIBTSB_VERSION_MISMATCH
  , LIBTSB_INVALID_XML_OPERATION
  , LIBTSB_NAMESPACES_MISMATCH
  , LIBTSB_DUPLICATE_ANNOTATION_NS
  , LIBTSB_ANNOTATION_NAME_NOT_FOUND
  , LIBTSB_ANNOTATION_NS_NOT_FOUND
  , LIBTSB_MISSING_METAID
  , LIBTSB_DEPRECATED_ATTRIBUTE
};

static const char* TSB_OPERATION_RETURN_VALUES_STRINGS[] =
{
  /* LIBTSB_OPERATION_SUCCESS = 0 */
   "The operation was successful. "
  , /*LIBTSB_INDEX_EXCEEDS_SIZE = -1 */
   "An index parameter exceeded the bounds of a data array or other "
   "collection used in the operation. This return value is typically "
   "returned by methods that take index numbers to refer to lists "
   "of objects, when the caller has provided an index that exceeds "
   "the bounds of the list. LibTSB provides methods for checking the "
   "size of list/sequence/collection structures, and callers should "
   "verify the sizes before calling methods that take index numbers. "

  , /*LIBTSB_UNEXPECTED_ATTRIBUTE = -2*/
   "The attribute that is the subject of this operation is not valid "
   "for the combination of TSB Level and Version for the underlying "
   "object. This can happen because libTSB strives to offer a uniform "
   "API for all TSB Levels and Versions, but some object attributes and "
   "elements are not defined for all TSB Levels and Versions. Calling "
   "programs are expected to be aware of which object structures they "
   "are working with, but when errors of this kind occur, they are "
   "reported using this return value. "

  , /*LIBTSB_OPERATION_FAILED = -3*/
   "The requested action could not be performed. This can occur in "
   "a variety of contexts, such as passing a null object as a parameter "
   "in a situation where it does not make sense to permit a null object. "
   " "

  , /*LIBTSB_INVALID_ATTRIBUTE_VALUE = -4*/
   "A value passed as an argument to the method is not of a type that "
   "is valid for the operation or kind of object involved. For example, "
   "this return code is used when a calling program attempts to set an "
   "TSB object identifier to a string whose syntax does not conform to "
   "the TSB identifier syntax. "

  , /*LIBTSB_INVALID_OBJECT = -5*/
   "The object passed as an argument to the method is not of a type "
   "that is valid for the operation or kind of object involved. For "
   "example, handing an invalidly-constructed ASTNode to a method "
   "expecting an ASTNode will result in this error. "

  , /*LIBTSB_DUPLICATE_OBJECT_ID = -6*/
   "There already exists an object with this identifier in the "
   "context where this operation is being attempted. This error is "
   "typically returned in situations where TSB object identifiers must be "
   "unique, such as attempting to add two species with the same identifier "
   "to a model. "

  , /*LIBTSB_LEVEL_MISMATCH = -7*/
   "The TSB Level associated with the object does not match the Level "
   "of the parent object. This error can happen when an TSB component "
   "such as a species or compartment object is created outside of a model "
   "and a calling program then attempts to add the object to a model that "
   "has a different TSB Level defined. "

  , /*LIBTSB_VERSION_MISMATCH = -8*/
   "The TSB Version within the TSB Level associated with the object "
   "does not match the Version of the parent object. This error can "
   "happen when an TSB component such as a species or compartment object "
   "is created outside of a model and a calling program then attempts to "
   "add the object to a model that has a different TSB Level+Version "
   "combination. "

  , /*LIBTSB_INVALID_XML_OPERATION = -9*/
   "The XML operation attempted is not valid for the object or context "
   "involved. This error is typically returned by the XML interface layer "
   "of libTSB, when a calling program attempts to construct or manipulate "
   "XML in an invalid way. "

  , /*LIBTSB_NAMESPACES_MISMATCH = -10*/
   "The TSB Namespaces associated with the object "
   "do not match the TSB Namespaces of the parent object. This error can "
   "happen when an TSB component such as a species or compartment object "
   "is created outside of a model and a calling program then attempts to "
   "add the object to a model that has a different TSB Namespaces "
   "combination. "

  , /*LIBTSB_DUPLICATE_ANNOTATION_NS = -11*/
   "There already exists a top level annotation with the same namespace as "
   "annotation being appended. This error is "
   "typically returned in situations where the appendTestAnnotation function "
   "is being used to add an annotation that has a namespace that is already "
   "present in the existing annotation. "

  , /*LIBTSB_ANNOTATION_NAME_NOT_FOUND = -12*/
   "The existing annotation does not have a top-level element with "
   "the given name. This error is "
   "typically returned in situations where the "
   "replaceTopLevelTestAnnotationElement function or "
   "the removeTopLevelTestAnnotationElement function "
   "is being used to replace or remove an annotation with a name that does "
   "not match the name of any top-level element that is already "
   "present in the existing annotation. "

  , /*LIBTSB_ANNOTATION_NS_NOT_FOUND = -13*/
   "The existing annotation does not have a top-level element with "
   "the given namespace. This error is "
   "typically returned in situations where the "
   "replaceTopLevelTestAnnotationElement function or "
   "the removeTopLevelTestAnnotationElement function "
   "is being used to replace or remove an annotation with a namespace that does "
   "not match the namespace of any top-level element that is already "
   "present in the existing annotation. "

  , /* LIBTSB_MISSING_METAID   = -14*/
    "The requested action cannot be performed as the target object does not have "
    "the metaid attribute set. "
   
  , /* LIBTSB_DEPRECATED_ATTRIBUTE   = -15*/
    "The attribute that is the subject of this operation has been deprecated "
    "for the combination of TSB Level and Version for the underlying "
    "object. "
     
};

LIBTSB_EXTERN
const char *
TSBOperationReturnValue_toString (int returnValue)
{
  int length = sizeof(TSB_OPERATION_RETURN_VALUES_INDICES)/sizeof(TSBOperationReturnValues_t);
  for (int i = 0; i < length; ++i)
  {
    if (TSB_OPERATION_RETURN_VALUES_INDICES[i] == returnValue)
      return TSB_OPERATION_RETURN_VALUES_STRINGS[i];
  }

  return NULL;
}


LIBTSB_CPP_NAMESPACE_END

