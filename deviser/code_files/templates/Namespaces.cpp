#include <sbml/SBMLNamespaces.h>
#include <sstream>
#include <sbml/common/common.h>
#include <iostream>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */


LIBSBML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsbmlInternal */
void 
SBMLNamespaces::initSBMLNamespace()
{
  mNamespaces = new XMLNamespaces();

  switch (mLevel)
  {
  case <SPEC_LEVEL>:
  default:
    switch (mVersion)
    {
    case <SPEC_VERSION>:
    default:
      mNamespaces->add(SBML_XMLNS_L<SPEC_LEVEL>V<SPEC_VERSION>);
      break;
    }
    break;
  }

  if (mNamespaces->getLength() == 0)
  {
    mLevel = SBML_INT_MAX;
    mVersion = SBML_INT_MAX;
    delete mNamespaces;
    mNamespaces = NULL;
  }
}
/** @endcond */


SBMLNamespaces::SBMLNamespaces(unsigned int level, unsigned int version)
 : mLevel(level)
  ,mVersion(version)
{
  initSBMLNamespace();
}


SBMLNamespaces::~SBMLNamespaces()
{
  if (mNamespaces != NULL)
    delete mNamespaces;
}


/*
 * Copy constructor; creates a copy of a SBMLNamespaces.
 */
SBMLNamespaces::SBMLNamespaces(const SBMLNamespaces& orig)
 : mLevel(orig.mLevel)
 , mVersion(orig.mVersion)
 , mNamespaces(NULL)
{
  if(orig.mNamespaces != NULL)
    this->mNamespaces = 
          new XMLNamespaces(*const_cast<SBMLNamespaces&>(orig).mNamespaces);
}


const List * 
SBMLNamespaces::getSupportedNamespaces()
{
  List *result = new List();
  result->add(new SBMLNamespaces(<SPEC_LEVEL>,<SPEC_VERSION>));
  return result;
}


void 
SBMLNamespaces::freeSBMLNamespaces(List * supportedNS)
{
  if (supportedNS == NULL) return;
  for (unsigned int i = 0; i < supportedNS->getSize(); i++)
  {
    delete (SBMLNamespaces*)supportedNS->get(i);
  }
  delete supportedNS;
}

/*
 * Assignment operator for SBMLNamespaces.
 */
SBMLNamespaces&
SBMLNamespaces::operator=(const SBMLNamespaces& rhs)
{
  if (&rhs != this)
  {
    mLevel   = rhs.mLevel;
    mVersion = rhs.mVersion;
    delete this->mNamespaces;
    if(rhs.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<SBMLNamespaces&>(rhs).mNamespaces);
    else
      this->mNamespaces = NULL;
  }

  return *this;
}



/*
 * Creates and returns a deep copy of this SBMLNamespaces.
 */
SBMLNamespaces *
SBMLNamespaces::clone () const
{
  return new SBMLNamespaces(*this);
}


std::string 
SBMLNamespaces::getSBMLNamespaceURI(unsigned int level,
                                 unsigned int version)
{
  std::string uri = "";
  switch (level)
  {
  case <SPEC_LEVEL>:
  default:
    switch (version)
    {
    case <SPEC_VERSION>:
    default:
      uri = SBML_XMLNS_L<SPEC_LEVEL>V<SPEC_VERSION>;
      break;
    }
    break;
  }
  return uri;
}


std::string
SBMLNamespaces::getURI() const
{
  return getSBMLNamespaceURI(mLevel,mVersion);
}


unsigned int 
SBMLNamespaces::getLevel()
{
  return mLevel;
}


unsigned int 
SBMLNamespaces::getLevel() const
{
  return mLevel;
}


unsigned int 
SBMLNamespaces::getVersion()
{
  return mVersion;
}


unsigned int 
SBMLNamespaces::getVersion() const
{
  return mVersion;
}


XMLNamespaces * 
SBMLNamespaces::getNamespaces()
{
  return mNamespaces;
}


const XMLNamespaces * 
SBMLNamespaces::getNamespaces() const
{
  return mNamespaces;
}


int
SBMLNamespaces::addNamespaces(const XMLNamespaces * xmlns)
{
  int success = LIBSBML_OPERATION_SUCCESS;

  if (xmlns == NULL)
    return LIBSBML_INVALID_OBJECT;

  if (!mNamespaces) 
  {
    initSBMLNamespace();
  }

  /* check whether the namespace already exists
   * add if it does not
   */
  for (int i = 0; i < xmlns->getLength(); i++)
  {
    if (mNamespaces != NULL && !(mNamespaces->hasNS(xmlns->getURI(i), xmlns->getPrefix(i))))
    {
      success = mNamespaces->add(xmlns->getURI(i), xmlns->getPrefix(i));
    }
  }

  return success;
}


int
SBMLNamespaces::addNamespace(const std::string &uri, const std::string &prefix)
{
  if (!mNamespaces) 
  {
    initSBMLNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->add(uri, prefix) : LIBSBML_INVALID_OBJECT;
}


int
SBMLNamespaces::removeNamespace(const std::string &uri)
{
  if (!mNamespaces) 
  {
    initSBMLNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->remove(mNamespaces->getIndex(uri)) : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c true if the given
 * URL is one of SBML_Lang XML namespaces.
 */
bool 
SBMLNamespaces::isSBMLNamespace(const std::string& uri)
{
  if (uri == SBML_XMLNS_L<SPEC_LEVEL>V<SPEC_VERSION>)   return true;

  return false;
}

bool 
SBMLNamespaces::isValidCombination()
{
  bool valid = true;
  bool sbmlDeclared = false;
  std::string declaredURI("");
  unsigned int version = getVersion();
  XMLNamespaces *xmlns = getNamespaces();

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(SBML_XMLNS_L<SPEC_LEVEL>V<SPEC_VERSION>))
    {
      ++numNS;
      declaredURI.assign(SBML_XMLNS_L<SPEC_LEVEL>V<SPEC_VERSION>);
    }

    // checks if the SBML_Lang Namespace is explicitly defined.
    for (int i=0; i < xmlns->getLength(); i++)
    {
      if (!declaredURI.empty() && 
                      xmlns->getURI(i) == declaredURI)
      {
        sbmlDeclared = true;
        break;
      }
    }
  }


  switch (getLevel())
  {
    case <SPEC_LEVEL>:
     switch (version)
      {
        case <SPEC_VERSION>:
          // the namespaces contains the sbml namespaces
          // check it is the correct ns for the level/version
          if (sbmlDeclared)
          {
            if (declaredURI != string(SBML_XMLNS_L<SPEC_LEVEL>V<SPEC_VERSION>))
            {
              valid = false;
            }
          }
          break;
        default:
          valid = false;
          break;
        }
      break;
    default:
      valid = false;
      break;
  }

  return valid;
}


/** @cond doxygenLibsbmlInternal */
void 
SBMLNamespaces::setLevel(unsigned int level)
{
  mLevel = level;
}


void 
SBMLNamespaces::setVersion(unsigned int version)
{
  mVersion = version;
}


void 
SBMLNamespaces::setNamespaces(XMLNamespaces * xmlns)
{
  delete mNamespaces;
  if (xmlns != NULL)
    mNamespaces = xmlns->clone();
  else
    mNamespaces = NULL;
}
/** @endcond */

#endif /* __cplusplus */


/** @cond doxygenIgnored */

LIBSBML_EXTERN
SBMLNamespaces_t *
SBMLNamespaces_create(unsigned int level, unsigned int version)
{
  return new SBMLNamespaces(level, version);
}


LIBSBML_EXTERN
void
SBMLNamespaces_free(SBMLNamespaces_t* ns)
{
  if (ns == NULL) return;
  delete static_cast<SBMLNamespaces*>(ns);
}


LIBSBML_EXTERN
unsigned int
SBMLNamespaces_getLevel(SBMLNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getLevel() : SBML_INT_MAX;
}


LIBSBML_EXTERN
unsigned int
SBMLNamespaces_getVersion(SBMLNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getVersion() : SBML_INT_MAX;
}


LIBSBML_EXTERN
XMLNamespaces_t *
SBMLNamespaces_getNamespaces(SBMLNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getNamespaces() : NULL;
}


LIBSBML_EXTERN
char *
SBMLNamespaces_getSBMLNamespaceURI(unsigned int level, unsigned int version)
{
  return safe_strdup(SBMLNamespaces::getSBMLNamespaceURI(level, version).c_str());
}


LIBSBML_EXTERN
int
SBMLNamespaces_addNamespaces(SBMLNamespaces_t *sbmlns,
                             const XMLNamespaces_t * xmlns)
{
  if (sbmlns != NULL)
    return sbmlns->addNamespaces(xmlns);
  else
    return LIBSBML_INVALID_OBJECT;
}

LIBSBML_EXTERN
SBMLNamespaces_t **
SBMLNamespaces_getSupportedNamespaces(int *length)
{
  if (length == NULL) return NULL;
   const List* supported = SBMLNamespaces::getSupportedNamespaces();
  
   *length = (int) supported->getSize();
  SBMLNamespaces_t ** result = (SBMLNamespaces_t**)malloc(sizeof(SBMLNamespaces_t*)*((unsigned long)*length));
  memset(result, 0, sizeof(SBMLNamespaces_t*)*((unsigned long)*length));
  for (int i = 0; i < *length; i++)
  {
    result[i] = ((SBMLNamespaces*)supported->get((unsigned int)i))->clone();
  }
  SBMLNamespaces::freeSBMLNamespaces(const_cast<List*>(supported));
  return result;
}
/** @endcond */

LIBSBML_CPP_NAMESPACE_END

