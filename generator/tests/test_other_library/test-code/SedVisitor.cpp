/**
 * @file SedVisitor.cpp
 * @brief Implementation of the SedVisitor class.
 * @author DEVISER
 */



#include <sedml/SedVisitor.h>
#include <sedml/SedTypes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SedVisitor::~SedVisitor ()
{
}


void
SedVisitor::visit (const SedDocument& x)
{
  visit( static_cast<const SedBase&>(x) );
}


void
SedVisitor::visit (const SedListOf& x, int type)
{
  visit( static_cast<const SedBase&>(x) );
}


bool
SedVisitor::visit (const SedBase& sb)
{
  return false;
}


void
SedVisitor::leave (const SedDocument& x)
{
}


void
SedVisitor::leave (const SedBase& sb)
{
}


void
SedVisitor::leave (const SedListOf& x, int type)
{
}

#endif /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_END
