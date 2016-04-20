
#include <sbml/SBMLVisitor.h>
#include <sbml/SBMLTypes.h>

LIBSBML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SBMLVisitor::~SBMLVisitor ()
{
}


void
SBMLVisitor::visit (const SBMLDocument& x)
{
  visit( static_cast<const SBase&>(x) );
}


void
SBMLVisitor::visit (const ListOf& x, int type)
{
  visit( static_cast<const SBase&>(x) );
}


bool
SBMLVisitor::visit (const SBase& sb)
{
  return false;
}


<add_visit_classes_code/>
void
SBMLVisitor::leave (const SBMLDocument& x)
{
}


void
SBMLVisitor::leave (const SBase& sb)
{
}


void
SBMLVisitor::leave (const ListOf& x, int type)
{
}
<add_leave_classes_code/>

#endif /* __cplusplus */


LIBSBML_CPP_NAMESPACE_END
