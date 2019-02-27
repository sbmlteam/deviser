/**
 * @file Constraint.cpp
 * @brief Implementation of the Constraint class.
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
#include <sbml/Constraint.h>
#include <sbml/SBMLListOfConstraints.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Constraint using the given SBML Level and @ p version values.
 */
Constraint::Constraint(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mMath (NULL)
  , mMessage (NULL)
{
  setSBMLNamespacesAndOwn(new SBMLNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new Constraint using the given SBMLNamespaces object @p sbmlns.
 */
Constraint::Constraint(SBMLNamespaces *sbmlns)
  : SBase(sbmlns)
  , mMath (NULL)
  , mMessage (NULL)
{
  setElementNamespace(sbmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for Constraint.
 */
Constraint::Constraint(const Constraint& orig)
  : SBase( orig )
  , mMath ( NULL )
  , mMessage ( NULL )
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  if (orig.mMessage != NULL)
  {
    mMessage = orig.mMessage->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Constraint.
 */
Constraint&
Constraint::operator=(const Constraint& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    delete mMath;
    if (rhs.mMath != NULL)
    {
      mMath = rhs.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }

    delete mMessage;
    if (rhs.mMessage != NULL)
    {
      mMessage = rhs.mMessage->clone();
    }
    else
    {
      mMessage = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Constraint object.
 */
Constraint*
Constraint::clone() const
{
  return new Constraint(*this);
}


/*
 * Destructor for Constraint.
 */
Constraint::~Constraint()
{
  delete mMath;
  mMath = NULL;
  delete mMessage;
  mMessage = NULL;
}


/*
 * Returns the value of the "math" element of this Constraint.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
Constraint::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this Constraint.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
Constraint::getMath()
{
  return mMath;
}


/*
 * Returns the value of the "message" element of this Constraint.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
Constraint::getMessage() const
{
  return mMessage;
}


/*
 * Returns the value of the "message" element of this Constraint.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
Constraint::getMessage()
{
  return mMessage;
}


/*
 * Predicate returning @c true if this Constraint's "math" element is set.
 */
bool
Constraint::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Predicate returning @c true if this Constraint's "message" element is set.
 */
bool
Constraint::isSetMessage() const
{
  return (mMessage != NULL);
}


/*
 * Sets the value of the "math" element of this Constraint.
 */
int
Constraint::setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* math)
{
  if (mMath == math)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (math == NULL)
  {
    delete mMath;
    mMath = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (!(math->isWellFormedASTNode()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else
  {
    delete mMath;
    mMath = (math != NULL) ? math->deepCopy() : NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "message" element of this Constraint.
 */
int
Constraint::setMessage(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* message)
{
  if (mMessage == message)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (message == NULL)
  {
    delete mMessage;
    mMessage = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mMessage;
    mMessage = (message != NULL) ? message->clone() : NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "math" element of this Constraint.
 */
int
Constraint::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "message" element of this Constraint.
 */
int
Constraint::unsetMessage()
{
  delete mMessage;
  mMessage = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Constraint object.
 */
const std::string&
Constraint::getElementName() const
{
  static const string name = "";
  return name;
}


/*
 * Returns the libSBML type code for this Constraint object.
 */
int
Constraint::getTypeCode() const
{
  return CORE_CONSTRAINT;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Constraint::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SBase::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, NULL);
  }

  if (isSetMessage() == true)
  {
    stream.startElement("message");
    stream << *mMessage;
    stream.endElement("message");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Constraint::accept(SBMLVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Constraint::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Constraint::connectToChild()
{
  SBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Constraint's attribute "attributeName"
 * is set.
 */
bool
Constraint::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Constraint.
 */
int
Constraint::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
Constraint::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken elem = stream.peek();
    const std::string prefix = checkMathMLNamespace(elem);
    delete mMath;
    mMath = readMathML(stream, prefix);
    read = true;
  }

  if (name == "message")
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& token = stream.next();
    stream.skipText();
    delete mMessage;
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* xml = new
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(stream);
    mMessage = new LIBSBML_CPP_NAMESPACE_QUALIFIER
      XMLNode(*(static_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken*>(xml)));
    stream.skipPastEnd(token);
    delete xml;
    read = true;
  }

  if (SBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Constraint_t using the given SBML Level and @ p version
 * values.
 */
LIBSBML_EXTERN
Constraint_t *
Constraint_create(unsigned int level, unsigned int version)
{
  return new Constraint(level, version);
}


/*
 * Creates and returns a deep copy of this Constraint_t object.
 */
LIBSBML_EXTERN
Constraint_t*
Constraint_clone(const Constraint_t* c)
{
  if (c != NULL)
  {
    return static_cast<Constraint_t*>(c->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Constraint_t object.
 */
LIBSBML_EXTERN
void
Constraint_free(Constraint_t* c)
{
  if (c != NULL)
  {
    delete c;
  }
}


/*
 * Returns the value of the "math" element of this Constraint_t.
 */
LIBSBML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
Constraint_getMath(const Constraint_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return (LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*)(c->getMath());
}


/*
 * Returns the value of the "message" element of this Constraint_t.
 */
LIBSBML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
Constraint_getMessage(const Constraint_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*)(c->getMessage());
}


/*
 * Predicate returning @c 1 (true) if this Constraint_t's "math" element is
 * set.
 */
LIBSBML_EXTERN
int
Constraint_isSetMath(const Constraint_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetMath()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Constraint_t's "message" element is
 * set.
 */
LIBSBML_EXTERN
int
Constraint_isSetMessage(const Constraint_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetMessage()) : 0;
}


/*
 * Sets the value of the "math" element of this Constraint_t.
 */
LIBSBML_EXTERN
int
Constraint_setMath(Constraint_t * c,
                   const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* math)
{
  return (c != NULL) ? c->setMath(math) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "message" element of this Constraint_t.
 */
LIBSBML_EXTERN
int
Constraint_setMessage(Constraint_t * c,
                      const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t* message)
{
  return (c != NULL) ? c->setMessage(message) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this Constraint_t.
 */
LIBSBML_EXTERN
int
Constraint_unsetMath(Constraint_t * c)
{
  return (c != NULL) ? c->unsetMath() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "message" element of this Constraint_t.
 */
LIBSBML_EXTERN
int
Constraint_unsetMessage(Constraint_t * c)
{
  return (c != NULL) ? c->unsetMessage() : LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


