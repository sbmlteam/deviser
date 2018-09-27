
#include <stdlib.h>
#include <sbml/common/SBMLOperationReturnValues.h>

LIBSBML_CPP_NAMESPACE_BEGIN

static SBMLOperationReturnValues_t SBML_OPERATION_RETURN_VALUES_INDICES[] = 
{
    LIBSBML_OPERATION_SUCCESS
  , LIBSBML_INDEX_EXCEEDS_SIZE
  , LIBSBML_UNEXPECTED_ATTRIBUTE
  , LIBSBML_OPERATION_FAILED
  , LIBSBML_INVALID_ATTRIBUTE_VALUE
  , LIBSBML_INVALID_OBJECT
  , LIBSBML_DUPLICATE_OBJECT_ID
  , LIBSBML_LEVEL_MISMATCH
  , LIBSBML_VERSION_MISMATCH
  , LIBSBML_INVALID_XML_OPERATION
  , LIBSBML_NAMESPACES_MISMATCH
  , LIBSBML_DUPLICATE_ANNOTATION_NS
  , LIBSBML_ANNOTATION_NAME_NOT_FOUND
  , LIBSBML_ANNOTATION_NS_NOT_FOUND
  , LIBSBML_MISSING_METAID
  , LIBSBML_DEPRECATED_ATTRIBUTE
};

static const char* SBML_OPERATION_RETURN_VALUES_STRINGS[] =
{
  /* LIBSBML_OPERATION_SUCCESS = 0 */
   "The operation was successful. "
  , /*LIBSBML_INDEX_EXCEEDS_SIZE = -1 */
   "An index parameter exceeded the bounds of a data array or other "
   "collection used in the operation. This return value is typically "
   "returned by methods that take index numbers to refer to lists "
   "of objects, when the caller has provided an index that exceeds "
   "the bounds of the list. LibSBML provides methods for checking the "
   "size of list/sequence/collection structures, and callers should "
   "verify the sizes before calling methods that take index numbers. "

  , /*LIBSBML_UNEXPECTED_ATTRIBUTE = -2*/
   "The attribute that is the subject of this operation is not valid "
   "for the combination of SBML Level and Version for the underlying "
   "object. This can happen because libSBML strives to offer a uniform "
   "API for all SBML Levels and Versions, but some object attributes and "
   "elements are not defined for all SBML Levels and Versions. Calling "
   "programs are expected to be aware of which object structures they "
   "are working with, but when errors of this kind occur, they are "
   "reported using this return value. "

  , /*LIBSBML_OPERATION_FAILED = -3*/
   "The requested action could not be performed. This can occur in "
   "a variety of contexts, such as passing a null object as a parameter "
   "in a situation where it does not make sense to permit a null object. "
   " "

  , /*LIBSBML_INVALID_ATTRIBUTE_VALUE = -4*/
   "A value passed as an argument to the method is not of a type that "
   "is valid for the operation or kind of object involved. For example, "
   "this return code is used when a calling program attempts to set an "
   "SBML object identifier to a string whose syntax does not conform to "
   "the SBML identifier syntax. "

  , /*LIBSBML_INVALID_OBJECT = -5*/
   "The object passed as an argument to the method is not of a type "
   "that is valid for the operation or kind of object involved. For "
   "example, handing an invalidly-constructed ASTNode to a method "
   "expecting an ASTNode will result in this error. "

  , /*LIBSBML_DUPLICATE_OBJECT_ID = -6*/
   "There already exists an object with this identifier in the "
   "context where this operation is being attempted. This error is "
   "typically returned in situations where SBML object identifiers must be "
   "unique, such as attempting to add two species with the same identifier "
   "to a model. "

  , /*LIBSBML_LEVEL_MISMATCH = -7*/
   "The SBML Level associated with the object does not match the Level "
   "of the parent object. This error can happen when an SBML component "
   "such as a species or compartment object is created outside of a model "
   "and a calling program then attempts to add the object to a model that "
   "has a different SBML Level defined. "

  , /*LIBSBML_VERSION_MISMATCH = -8*/
   "The SBML Version within the SBML Level associated with the object "
   "does not match the Version of the parent object. This error can "
   "happen when an SBML component such as a species or compartment object "
   "is created outside of a model and a calling program then attempts to "
   "add the object to a model that has a different SBML Level+Version "
   "combination. "

  , /*LIBSBML_INVALID_XML_OPERATION = -9*/
   "The XML operation attempted is not valid for the object or context "
   "involved. This error is typically returned by the XML interface layer "
   "of libSBML, when a calling program attempts to construct or manipulate "
   "XML in an invalid way. "

  , /*LIBSBML_NAMESPACES_MISMATCH = -10*/
   "The SBML Namespaces associated with the object "
   "do not match the SBML Namespaces of the parent object. This error can "
   "happen when an SBML component such as a species or compartment object "
   "is created outside of a model and a calling program then attempts to "
   "add the object to a model that has a different SBML Namespaces "
   "combination. "

  , /*LIBSBML_DUPLICATE_ANNOTATION_NS = -11*/
   "There already exists a top level annotation with the same namespace as "
   "annotation being appended. This error is "
   "typically returned in situations where the append<Annotation> function "
   "is being used to add an annotation that has a namespace that is already "
   "present in the existing annotation. "

  , /*LIBSBML_ANNOTATION_NAME_NOT_FOUND = -12*/
   "The existing annotation does not have a top-level element with "
   "the given name. This error is "
   "typically returned in situations where the "
   "replaceTopLevel<Annotation>Element function or "
   "the removeTopLevel<Annotation>Element function "
   "is being used to replace or remove an annotation with a name that does "
   "not match the name of any top-level element that is already "
   "present in the existing annotation. "

  , /*LIBSBML_ANNOTATION_NS_NOT_FOUND = -13*/
   "The existing annotation does not have a top-level element with "
   "the given namespace. This error is "
   "typically returned in situations where the "
   "replaceTopLevel<Annotation>Element function or "
   "the removeTopLevel<Annotation>Element function "
   "is being used to replace or remove an annotation with a namespace that does "
   "not match the namespace of any top-level element that is already "
   "present in the existing annotation. "

  , /* LIBSBML_MISSING_METAID   = -14*/
    "The requested action cannot be performed as the target object does not have "
    "the metaid attribute set. "
   
  , /* LIBSBML_DEPRECATED_ATTRIBUTE   = -15*/
    "The attribute that is the subject of this operation has been deprecated "
    "for the combination of SBML Level and Version for the underlying "
    "object. "
     
};

LIBSBML_EXTERN
const char *
SBMLOperationReturnValue_toString (int returnValue)
{
  int length = sizeof(SBML_OPERATION_RETURN_VALUES_INDICES)/sizeof(SBMLOperationReturnValues_t);
  for (int i = 0; i < length; ++i)
  {
    if (SBML_OPERATION_RETURN_VALUES_INDICES[i] == returnValue)
      return SBML_OPERATION_RETURN_VALUES_STRINGS[i];
  }

  return NULL;
}


LIBSBML_CPP_NAMESPACE_END

