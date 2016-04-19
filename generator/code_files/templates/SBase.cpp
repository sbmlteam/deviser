#include <sstream>
#include <vector>

<verbatim>
#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLNode.h>

#include <sbml/util/util.h>
</verbatim>

#include <sbml/SBMLError.h>
#include <sbml/SBMLErrorLog.h>
#include <sbml/SBMLDocument.h>
#include <sbml/ListOf.h>
#include <sbml/SBase.h>


/** @cond doxygenIgnored */
using namespace std;
/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SBase*
SBase::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;

  return NULL;
}


SBase*
SBase::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;

  return NULL;
}

List*
SBase::getAllElements()
{
  return NULL;
}

/** @cond doxygenLibsbmlInternal */
/*
 * Creates a new SBase object with the given level and version.
 * Only subclasses may create SBase objects.
 */
SBase::SBase (unsigned int level, unsigned int version) 
 : mMetaId ("")
 , mNotes(NULL)
 , mAnnotation( NULL )
 , mSBML      ( NULL )
 , mSBMLNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSBMLObject (NULL)
  , mHasBeenDeleted(false)
  , mEmptyString("")
 , mURI("")
{
  mSBMLNamespaces = new SBMLNamespaces(level, version);

  //
  // Sets the XMLNS URI of corresponding SBML Level/Version to
  // the element namespace (mURI) of this object.
  //
  //
  setElementNamespace(mSBMLNamespaces->getURI());
}



/*
 * Creates a new SBase object with the given SBMLNamespaces.
 * Only subclasses may create SBase objects.
 */
SBase::SBase (SBMLNamespaces *sbmlns) 
 : mMetaId("")
 , mNotes(NULL)
 , mAnnotation( NULL )
 , mSBML      ( NULL )
 , mSBMLNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSBMLObject (NULL)
  , mHasBeenDeleted(false)
  , mEmptyString("")
 , mURI("")
{
  if (!sbmlns)
  {
    std::string err("SBase::SBase(SBMLNamespaces*) : SBMLNamespaces is null");
    throw SBMLConstructorException(err);
  }
  mSBMLNamespaces = sbmlns->clone();

  setElementNamespace(static_cast<SBMLNamespaces>(*mSBMLNamespaces).getURI());
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Copy constructor. Creates a copy of this SBase object.
 */
SBase::SBase(const SBase& orig)
  : mMetaId (orig.mMetaId)
  , mNotes (NULL)
  , mAnnotation (NULL)
  , mSBML (NULL)
  , mSBMLNamespaces(NULL)
  , mUserData(orig.mUserData)
  , mLine(orig.mLine)
  , mColumn(orig.mColumn)
  , mParentSBMLObject(NULL)
  , mURI(orig.mURI)
{
  if(orig.mNotes != NULL)
    this->mNotes = new XMLNode(*const_cast<SBase&>(orig).getNotes());
  else
    this->mNotes = NULL;

  if(orig.mAnnotation != NULL)
    this->mAnnotation = new XMLNode(*const_cast<SBase&>(orig).mAnnotation);
  else
    this->mAnnotation = NULL;

  if(orig.getSBMLNamespaces() != NULL)
    this->mSBMLNamespaces =
    new SBMLNamespaces(*const_cast<SBase&>(orig).getSBMLNamespaces());
  else
    this->mSBMLNamespaces = NULL;

  this->mHasBeenDeleted = false;
}
/** @endcond */


/*
 * Destroy this SBase object.
 */
SBase::~SBase ()
{
  if (mNotes != NULL)       delete mNotes;
  if (mAnnotation != NULL)  delete mAnnotation;
  if (mSBMLNamespaces != NULL)  delete mSBMLNamespaces;
}

/*
 * Assignment operator
 */
SBase& SBase::operator=(const SBase& rhs)
{
  if(&rhs!=this)
  {
    this->mMetaId = rhs.mMetaId;

    delete this->mNotes;

    if(rhs.mNotes != NULL)
      this->mNotes = new XMLNode(*const_cast<SBase&>(rhs).getNotes());
    else
      this->mNotes = NULL;

    delete this->mAnnotation;

    if(rhs.mAnnotation != NULL)
      this->mAnnotation = new XMLNode(*const_cast<SBase&>(rhs).mAnnotation);
    else
      this->mAnnotation = NULL;

    this->mSBML       = rhs.mSBML;
    this->mLine       = rhs.mLine;
    this->mColumn     = rhs.mColumn;
    this->mParentSBMLObject = rhs.mParentSBMLObject;
    this->mUserData   = rhs.mUserData;

    delete this->mSBMLNamespaces;

    if(rhs.mSBMLNamespaces != NULL)
      this->mSBMLNamespaces =
      new SBMLNamespaces(*const_cast<SBase&>(rhs).mSBMLNamespaces);
    else
      this->mSBMLNamespaces = NULL;


    this->mURI = rhs.mURI;
  }

  return *this;
}


/*
 * @return the metaid of this SBML object.
 */
const string&
SBase::getMetaId () const
{
  return mMetaId;
}


/*
 * @return the metaid of this SBML object.
 */
string&
SBase::getMetaId ()
{
  return mMetaId;
}


const string&
SBase::getId() const
{
  return mEmptyString;
}


/*
 * @return the notes of this SBML object.
 */
XMLNode*
SBase::getNotes()
{
  return mNotes;
}


const XMLNode*
SBase::getNotes() const
{
  return mNotes;
}


/*
 * @return the notes of this SBML object by string.
 */
std::string
SBase::getNotesString()
{
  return XMLNode::convertXMLNodeToString(mNotes);
}


std::string
SBase::getNotesString() const
{
  return XMLNode::convertXMLNodeToString(mNotes);
}


/*
 * @return the annotation of this SBML object.
 */
XMLNode*
SBase::getAnnotation ()
{
  return mAnnotation;
}


const XMLNode*
SBase::getAnnotation () const
{
  return const_cast<SBase *>(this)->getAnnotation();
}


/*
 * @return the annotation of this SBML object by string.
 */
std::string
SBase::getAnnotationString ()
{
  return XMLNode::convertXMLNodeToString(getAnnotation());
}


std::string
SBase::getAnnotationString () const
{
  return XMLNode::convertXMLNodeToString(getAnnotation());
}


/** @cond doxygenLibsbmlInternal */
std::string
SBase::getURI() const
{
  const SBMLDocument* doc = getSBMLDocument();

  if (doc == NULL)
    return getElementNamespace();

  SBMLNamespaces* sbmlns = doc->getSBMLNamespaces();

  if (sbmlns == NULL)
    return getElementNamespace();

  return getElementNamespace();
}
/** @endcond */


void *
SBase::getUserData() const
{
  return this->mUserData;
}


int
SBase::setUserData(void *userData)
{
  this->mUserData = userData;
  if (userData == NULL && mUserData == NULL)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (mUserData != NULL)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

bool
SBase::isSetUserData() const
{
  if (mUserData != NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int
SBase::unsetUserData()
{
  this->mUserData = NULL;
  if (mUserData == NULL)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

/*
 * @return the Namespaces associated with this SBML object
 */
XMLNamespaces*
SBase::getNamespaces()
{
  if (mSBML != NULL)
    return mSBML->getSBMLNamespaces()->getNamespaces();
  else
    return mSBMLNamespaces->getNamespaces();
}


const XMLNamespaces*
SBase::getNamespaces() const
{
  if (mSBML != NULL)
    return mSBML->getSBMLNamespaces()->getNamespaces();
  else
    return mSBMLNamespaces->getNamespaces();
}


/*
 * @return the parent SBMLDocument of this SBML object.
 */
const SBMLDocument*
SBase::getSBMLDocument () const
{
  if (mSBML != NULL)
  {
    // if the doc object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mSBML->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mSBML;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mSBML;
}

/*
 * @return the parent SBMLDocument of this SBML object.
 */
SBMLDocument*
SBase::getSBMLDocument ()
{
  if (mSBML != NULL)
  {
    // if the doc object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mSBML->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mSBML;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }
  return mSBML;
}
SBase*
SBase::getParentSBMLObject ()
{
  if (mParentSBMLObject != NULL)
  {
    // if the parent object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mParentSBMLObject->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mParentSBMLObject;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mParentSBMLObject;
}

const SBase*
SBase::getParentSBMLObject () const
{
  if (mParentSBMLObject != NULL)
  {
    // if the parent object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mParentSBMLObject->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mParentSBMLObject;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mParentSBMLObject;
}


/*
 * @return the line number of this SBML object.
 */
unsigned int
SBase::getLine () const
{
  return mLine;
}


/*
 * @return the column number of this SBML object.
 */
unsigned int
SBase::getColumn () const
{
  return mColumn;
}


/*
 * @return true if the metaid of this SBML object is set, false
 * otherwise.
 */
bool
SBase::isSetMetaId () const
{
  return (mMetaId.empty() == false);
}


bool
SedBase::isSetId() const
{
  return (getId().empty() == false);
}


/*
 * @return true if the notes of this SBML object is set, false
 * otherwise.
 */
bool
SBase::isSetNotes () const
{
  return (mNotes != NULL);
}


/*
 * @return true if the annotation of this SBML object is set,
 * false otherwise.
 */
bool
SBase::isSetAnnotation () const
{
  return (mAnnotation != NULL);
}


/*
 * Sets the metaid field of the given SBML object to a copy of metaid.
 */
int
SBase::setMetaId (const std::string& metaid)
{
  if (metaid.empty())
  {
    mMetaId.erase();
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (!(SyntaxChecker::isValidXMLID(metaid)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mMetaId = metaid;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the annotation of this SBML object to a copy of annotation.
 */
int
SBase::setAnnotation (XMLNode* annotation)
{
  if (annotation == NULL)
  {
    delete mAnnotation;
    mAnnotation = NULL;
  }

  if (mAnnotation != annotation)
  {
    delete mAnnotation;

    mAnnotation = annotation->clone();
  }

  return LIBSBML_OPERATION_SUCCESS;
}

/*
 * Sets the annotation (by string) of this SBML object to a copy of annotation.
 */
int
SBase::setAnnotation (const std::string& annotation)
{
  
  int success = LIBSBML_OPERATION_FAILED;
  
  if(annotation.empty())
  {
    unsetAnnotation();
    return LIBSBML_OPERATION_SUCCESS;
  }
  
  XMLNode* annt_xmln;
  
  // you might not have a document !!
  if (getSBMLDocument() != NULL)
  {
    XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
    annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = XMLNode::convertStringToXMLNode(annotation);
  }
  
  if(annt_xmln != NULL)
  {
    success = setAnnotation(annt_xmln);
    delete annt_xmln;
  }
  return success;  
}


/*
 * Appends annotation to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int
SBase::appendAnnotation (const XMLNode* annotation)
{
  int success = LIBSBML_OPERATION_FAILED;
  unsigned int duplicates = 0;

  if(annotation == NULL)
    return LIBSBML_OPERATION_SUCCESS;

  XMLNode* new_annotation = NULL;
  const string&  name = annotation->getName();

  // check for annotation tags and add if necessary
  if (name != "annotation")
  {
    XMLToken ann_t = XMLToken(XMLTriple("annotation", "", ""), XMLAttributes());
    new_annotation = new XMLNode(ann_t);
    new_annotation->addChild(*annotation);
  }
  else
  {
    new_annotation = annotation->clone();
  }


  if (mAnnotation != NULL)
  {
    // if mAnnotation is just <annotation/> need to tell
    // it to no longer be an end
    if (mAnnotation->isEnd())
    {
      mAnnotation->unsetEnd();
    }


    // create a list of existing top level ns
      vector<string> topLevelNs;
    unsigned int i = 0;
    for(i = 0; i < mAnnotation->getNumChildren(); i++)
    {
          topLevelNs.push_back(mAnnotation->getChild(i).getName());
    }



    for(i = 0; i < new_annotation->getNumChildren(); i++)
    {
          if (find(topLevelNs.begin(), topLevelNs.end(), (new_annotation->getChild(i).getName())) != topLevelNs.end())
      {
        mAnnotation->addChild(new_annotation->getChild(i));
      }
      else
      {
        duplicates++;
      }
    }

    delete new_annotation;

    if (duplicates > 0)
    {
      success = LIBSBML_DUPLICATE_ANNOTATION_NS;
    }
    else
    {
      XMLNode *copy = mAnnotation->clone();
      success = setAnnotation(copy);
      delete copy;
    }


  }
  else
  {
    success = setAnnotation(new_annotation);

    delete new_annotation;
  }

  return success;
}

/*
 * Appends annotation (by string) to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int
SBase::appendAnnotation (const std::string& annotation)
{
  int success = LIBSBML_OPERATION_FAILED;
  XMLNode* annt_xmln;
  if (getSBMLDocument() != NULL)
  {
    XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
    annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = XMLNode::convertStringToXMLNode(annotation);
  }

  if(annt_xmln != NULL)
  {
    success = appendAnnotation(annt_xmln);
    delete annt_xmln;
  }

  return success;
}


int
SBase::removeTopLevelAnnotationElement(const std::string elementName,
    const std::string elementURI)
{

  int success = LIBSBML_OPERATION_FAILED;
  if (mAnnotation == NULL)
  {
    success = LIBSBML_OPERATION_SUCCESS;
    return success;
  }

  int index = mAnnotation->getIndex(elementName);
  if (index < 0)
  {
    // the annotation does not have a child of this name
    success = LIBSBML_ANNOTATION_NAME_NOT_FOUND;
    return success;
  }
  else
  {
    // check uri matches
    if (elementURI.empty() == false)
    {
      XMLNode child = mAnnotation->getChild(index);
      std::string prefix = child.getPrefix();

      if (prefix.empty() == false
        && elementURI != child.getNamespaceURI(prefix))
      {
        success = LIBSBML_ANNOTATION_NS_NOT_FOUND;
        return success;
      }
      else
      {
        bool match = false;
        int n = 0;

        while (match == false && n < child.getNamespacesLength())
        {
          if (elementURI == child.getNamespaceURI(n))
          {
            match = true;
          }
          n++;
        }

        if (match == false)
        {
          success = LIBSBML_ANNOTATION_NS_NOT_FOUND;
          return success;
        }
      }
    }

    // remove the annotation at the index corresponding to the name
    delete mAnnotation->removeChild(index);

      if (mAnnotation->getNumChildren() == 0)
        {
          delete mAnnotation;
          mAnnotation = NULL;
        }

    // check success
    if (mAnnotation == NULL || mAnnotation->getIndex(elementName) < 0)
    {
      success = LIBSBML_OPERATION_SUCCESS;
    }
  }

  return success;
}


int
SBase::replaceTopLevelAnnotationElement(const XMLNode* annotation)
{
  int success = LIBSBML_OPERATION_FAILED;
  XMLNode * replacement = NULL;
  if (annotation->getName() == "annotation")
  {
    if (annotation->getNumChildren() != 1)
    {
      success = LIBSBML_INVALID_OBJECT;
      return success;
    }
    else
    {
      replacement = annotation->getChild(0).clone();
    }
  }
  else
  {
    replacement = annotation->clone();
  }

  success = removeTopLevelAnnotationElement(replacement->getName());
  if (success == LIBSBML_OPERATION_SUCCESS)
  {
    success = appendAnnotation(annotation);
  }

  delete (replacement);

  return success;
}


int
SBase::replaceTopLevelAnnotationElement(const std::string& annotation)
{
  int success = LIBSBML_OPERATION_FAILED;
  XMLNode* annt_xmln;
  if (getSBMLDocument() != NULL)
  {
    XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
    annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = XMLNode::convertStringToXMLNode(annotation);
  }

  if(annt_xmln != NULL)
  {
    success = replaceTopLevelAnnotationElement(annt_xmln);
  }

  delete annt_xmln;

  return success;
}


/*
 * Sets the notes of this SBML object to a copy of notes.
 */
int
SBase::setNotes(const XMLNode* notes)
{
  if (mNotes == notes)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (notes == NULL)
  {
    delete mNotes;
    mNotes = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }

  delete mNotes;
  const string&  name = notes->getName();

  /* check for notes tags and add if necessary */

  if (name == "notes")
  {
    mNotes = static_cast<XMLNode*>( notes->clone() );
  }
  else
  {
    XMLToken notes_t = XMLToken(XMLTriple("notes", "", ""),
                                XMLAttributes());
    mNotes = new XMLNode(notes_t);

    // The root node of the given XMLNode tree can be an empty XMLNode
    // (i.e. neither start, end, nor text XMLNode) if the given notes was
    // converted from an XML string whose top level elements are neither
    // "html" nor "body" and not enclosed with <notes>..</notes> tag
    // (e.g. <p ...>..</p><br/>).
    if (!notes->isStart() && !notes->isEnd() && !notes->isText() )
    {
      for (unsigned int i=0; i < notes->getNumChildren(); i++)
      {
        if (mNotes->addChild(notes->getChild(i)) < 0)
        {
          return LIBSBML_OPERATION_FAILED;
        }
      }
    }
    else
    {
      if (mNotes->addChild(*notes) < 0)
        return LIBSBML_OPERATION_FAILED;
    }
  }

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(mNotes, NULL))
    {
      delete mNotes;
      mNotes = NULL;
      return LIBSBML_INVALID_OBJECT;
    }

  return LIBSBML_OPERATION_SUCCESS;

}

/*
 * Sets the notes (by std::string) of this SBML object to a copy of notes.
 */
int
SedBase::setNotes(const std::string& notes, bool addXHTMLMarkup)
{
  int success = LIBSBML_OPERATION_FAILED;
  
  if (notes.empty())
  {
    success = unsetNotes();
  }
  else
  {
    XMLNode* notes_xmln;

    // you might not have a document !!
    if (getSBMLDocument() != NULL)
    {
      XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
      notes_xmln = XMLNode::convertStringToXMLNode(notes,xmlns);
    }
    else
    {
      notes_xmln = XMLNode::convertStringToXMLNode(notes);
    }

    if (notes_xmln != NULL)
    {
      if (addXHTMLMarkup == true)
      {
        if (notes_xmln->getNumChildren() == 0
            && notes_xmln->isStart() == false
            && notes_xmln->isEnd() == false
            && notes_xmln->isText() == true)
        {
          //create a parent node of xhtml type p
          XMLAttributes blank_att = XMLAttributes();
          XMLTriple triple = XMLTriple("p", "http://www.w3.org/1999/xhtml", "");
          XMLNamespaces xmlns = XMLNamespaces();
          xmlns.add("http://www.w3.org/1999/xhtml", "");
          XMLNode *xmlnode = new XMLNode(XMLToken(triple, blank_att, xmlns));

          // create a text node from the text given
          xmlnode->addChild(*notes_xmln);
          success = setNotes(xmlnode);
          delete xmlnode;
        }
        else
        {
          success = setNotes(notes_xmln);
        }
      }
      else
      {
        success = setNotes(notes_xmln);
      }

      delete notes_xmln;
    }
  }
  return success;
}


/*
 * Appends notes to the existing notes.
 * This allows other notes to be preserved whilst
 * adding additional information.
 */
int
SBase::appendNotes(const XMLNode* notes)
{
  int success = LIBSBML_OPERATION_FAILED;
  if(notes == NULL)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }

  const string&  name = notes->getName();

  // The content of notes in SBML can consist only of the following
  // possibilities:
  //
  //  1. A complete XHTML document (minus the XML and DOCTYPE
  //     declarations), that is, XHTML content beginning with the
  //     html tag.
  //     (_NotesType is _ANotesHTML.)
  //
  //  2. The body element from an XHTML document.
  //     (_NotesType is _ANotesBody.)
  //
  //  3. Any XHTML content that would be permitted within a body
  //     element, each one must declare the XML namespace separately.
  //     (_NotesType is _ANotesAny.)
  //

  typedef enum { _ANotesHTML, _ANotesBody, _ANotesAny } _NotesType;

  _NotesType addedNotesType = _ANotesAny;
  XMLNode   addedNotes;

  //------------------------------------------------------------
  //
  // STEP1 : identifies the type of the given notes
  //
  //------------------------------------------------------------

  if (name == "notes")
  {
    /* check for notes tags on the added notes and strip if present and
       the notes tag has "html" or "body" element */

    if (notes->getNumChildren() > 0)
    {
      // notes->getChild(0) must be "html", "body", or any XHTML
      // element that would be permitted within a "body" element
      // (e.g. <p>..</p>,  <br>..</br> and so forth).

      const string& cname = notes->getChild(0).getName();

      if (cname == "html")
      {
        addedNotes = notes->getChild(0);
        addedNotesType = _ANotesHTML;
      }
      else if (cname == "body")
      {
        addedNotes = notes->getChild(0);
        addedNotesType = _ANotesBody;
      }
      else
      {
        // the notes tag must NOT be stripped if notes->getChild(0) node
        // is neither "html" nor "body" element because the children of
        // the addedNotes will be added to the curNotes later if the node
        // is neither "html" nor "body".
        addedNotes = *notes;
        addedNotesType = _ANotesAny;
      }
    }
    else
    {
      // the given notes is empty
      return LIBSBML_OPERATION_SUCCESS;
    }
  }
  else
  {
    // if the XMLNode argument notes has been created from a string and
    // it is a set of subelements there may be a single empty node
    // as parent - leaving this in doesnt affect the writing out of notes
    // but messes up the check for correct syntax
    if (!notes->isStart() && !notes->isEnd() && !notes->isText() )
    {
      if (notes->getNumChildren() > 0)
      {
        addedNotes = *notes;
        addedNotesType = _ANotesAny;
      }
      else
      {
        // the given notes is empty
        return LIBSBML_OPERATION_SUCCESS;
      }
    }
    else
    {
      if (name == "html")
      {
        addedNotes = *notes;
        addedNotesType = _ANotesHTML;
      }
      else if (name == "body")
      {
        addedNotes = *notes;
        addedNotesType = _ANotesBody;
      }
      else
      {
        // The given notes node needs to be added to a parent node
        // if the node is neither "html" nor "body" element because the
        // children of addedNotes will be added to the curNotes later if the
        // node is neither "html" nor "body" (i.e. any XHTML element that
        // would be permitted within a "body" element)
        addedNotes.addChild(*notes);
        addedNotesType = _ANotesAny;
      }
    }
  }

  //
  // checks the addedNotes of "html" if the html tag contains "head" and
  // "body" tags which must be located in this order.
  //
  if (addedNotesType == _ANotesHTML)
  {
    if ((addedNotes.getNumChildren() != 2) ||
        ( (addedNotes.getChild(0).getName() != "head") ||
          (addedNotes.getChild(1).getName() != "body")
        )
       )
    {
      return LIBSBML_INVALID_OBJECT;
    }
  }

  // check whether notes is valid xhtml
  if (getLevel() > 2
    || (getLevel() == 2 && getVersion() > 1))
  {
    XMLNode tmpNotes(XMLTriple("notes","",""), XMLAttributes());

    if (addedNotesType == _ANotesAny)
    {
      for (unsigned int i=0; i < addedNotes.getNumChildren(); i++)
      {
        tmpNotes.addChild(addedNotes.getChild(i));
      }
    }
    else
    {
      tmpNotes.addChild(addedNotes);
    }

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(&tmpNotes, NULL))
    {
      return LIBSBML_INVALID_OBJECT;
    }
  }


  if ( mNotes != NULL )
  {
    //------------------------------------------------------------
    //
    //  STEP2: identifies the type of the existing notes
    //
    //------------------------------------------------------------

    _NotesType curNotesType   = _ANotesAny;
    XMLNode&  curNotes = *mNotes;

    // curNotes.getChild(0) must be "html", "body", or any XHTML
    // element that would be permitted within a "body" element .

    const string& cname = curNotes.getChild(0).getName();

    if (cname == "html")
    {
      XMLNode& curHTML = curNotes.getChild(0);
      //
      // checks the curHTML if the html tag contains "head" and "body" tags
      // which must be located in this order, otherwise nothing will be done.
      //
      if ((curHTML.getNumChildren() != 2) ||
          ( (curHTML.getChild(0).getName() != "head") ||
            (curHTML.getChild(1).getName() != "body")
          )
         )
      {
        return LIBSBML_INVALID_OBJECT;
      }
      curNotesType = _ANotesHTML;
    }
    else if (cname == "body")
    {
      curNotesType = _ANotesBody;
    }
    else
    {
      curNotesType = _ANotesAny;
    }

    /*
     * BUT we also have the issue of the rules relating to notes
     * contents and where to add them ie we cannot add a second body element
     * etc...
     */

    //------------------------------------------------------------
    //
    //  STEP3: appends the given notes to the current notes
    //
    //------------------------------------------------------------

    unsigned int i;

    if (curNotesType == _ANotesHTML)
    {
      XMLNode& curHTML = curNotes.getChild(0);
      XMLNode& curBody = curHTML.getChild(1);

      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current html tag

        XMLNode& addedBody = addedNotes.getChild(1);

        for (i=0; i < addedBody.getNumChildren(); i++)
        {
          if (curBody.addChild(addedBody.getChild(i)) < 0 )
            return LIBSBML_OPERATION_FAILED;
        }
      }
      else if ((addedNotesType == _ANotesBody)
             || (addedNotesType == _ANotesAny))
      {
        // adds the given body or other tag (permitted in the body) to the current
        // html tag

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curBody.addChild(addedNotes.getChild(i)) < 0 )
            return LIBSBML_OPERATION_FAILED;
        }
      }
      success = LIBSBML_OPERATION_SUCCESS;
    }
    else if (curNotesType == _ANotesBody)
    {
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current body tag

        XMLNode  addedHTML(addedNotes);
        XMLNode& addedBody = addedHTML.getChild(1);
        XMLNode& curBody   = curNotes.getChild(0);

        for (i=0; i < curBody.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curBody.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedHTML) < 0)
          return LIBSBML_OPERATION_FAILED;
      }
      else if ((addedNotesType == _ANotesBody) || (addedNotesType == _ANotesAny))
      {
        // adds the given body or other tag (permitted in the body) to the current
        // body tag

        XMLNode& curBody = curNotes.getChild(0);

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curBody.addChild(addedNotes.getChild(i)) < 0)
            return LIBSBML_OPERATION_FAILED;
        }
      }
      success = LIBSBML_OPERATION_SUCCESS;
    }
    else if (curNotesType == _ANotesAny)
    {
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current any tag permitted in the body.

        XMLNode  addedHTML(addedNotes);
        XMLNode& addedBody = addedHTML.getChild(1);

        for (i=0; i < curNotes.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curNotes.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedHTML) < 0)
          return LIBSBML_OPERATION_FAILED;
      }
      else if (addedNotesType == _ANotesBody)
      {
        // adds the given body tag to the current any tag permitted in the body.

        XMLNode addedBody(addedNotes);

        for (i=0; i < curNotes.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curNotes.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedBody) < 0)
          return LIBSBML_OPERATION_FAILED;
      }
      else if (addedNotesType == _ANotesAny)
      {
        // adds the given any tag permitted in the boy to that of the current
        // any tag.

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curNotes.addChild(addedNotes.getChild(i)) < 0)
            return LIBSBML_OPERATION_FAILED;
        }
      }
      success = LIBSBML_OPERATION_SUCCESS;
    }
  }
  else // if (mNotes == NULL)
  {
    // setNotes accepts XMLNode with/without top level notes tags.
    success = setNotes(notes);
  }

  return success;
}

/*
 * Appends notes (by string) to the existing notes.
 * This allows other notes to be preserved whilst
 * adding additional information.
 */
int
SBase::appendNotes(const std::string& notes)
{
  int success = LIBSBML_OPERATION_FAILED;
  if (notes.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }

  XMLNode* notes_xmln;
  // you might not have a document !!
  if (getSBMLDocument() != NULL)
  {
      XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
      notes_xmln = XMLNode::convertStringToXMLNode(notes,xmlns);
  }
  else
  {
      notes_xmln = XMLNode::convertStringToXMLNode(notes);
  }

  if(notes_xmln != NULL)
  {
    success = appendNotes(notes_xmln);
    delete notes_xmln;
  }
  return success;
}


/** @cond doxygenLibsbmlInternal */
/*
 * Sets the parent SBMLDocument of this SBML object.
 */
void
SBase::setSBMLDocument (SBMLDocument* d)
{
  mSBML = d;
}


/*
  * Sets the parent SBML object of this SBML object.
  *
  * @param sb the SBML object to use
  */
void
SBase::connectToParent (SBase* parent)
{
  mParentSBMLObject = parent;
  if (mParentSBMLObject)
  {
#if 0
    cout << "[DEBUG] connectToParent " << this << " (parent) " << SBMLTypeCode_toString(parent->getTypeCode(),"core")
         << " " << parent->getSBMLDocument() << endl;
#endif
    setSBMLDocument(mParentSBMLObject->getSBMLDocument());
  }
  else
  {
    setSBMLDocument(NULL);
  }
}


/*
 * Sets this SBML object to child SBML objects (if any).
 * (Creates a child-parent relationship by the parent)
 *
 * Subclasses must override this function if they define
 * one ore more child elements.
 * Basically, this function needs to be called in
 * constructors, copy constructors and assignment operators.
 */
void
SBase::connectToChild()
{
}
/** @endcond */

SBase*
SBase::getAncestorOfType(int type)
{
  if (type == SBML_DOCUMENT)
    return getSBMLDocument();

  SBase *child;
  SBase *parent = getParentSBMLObject();

  while ( parent != NULL &&
          !( parent->getTypeCode() == SBML_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type)
      return parent;
    else
    {
      child = parent;
      parent = child->getParentSBMLObject();
    }
  }

  // if we get here we havent found an ancestor of this type
  return NULL;

}


const SBase*
SBase::getAncestorOfType(int type) const
{
  if (type == SBML_DOCUMENT)
    return getSBMLDocument();

  const SBase *child;
  const SBase *parent = getParentSBMLObject();

  while ( parent != NULL &&
          !( parent->getTypeCode() == SBML_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type)
      return parent;
    else
    {
      child = parent;
      parent = child->getParentSBMLObject();
    }
  }

  // if we get here we havent found an ancestor of this type
  return NULL;

}


/*
 * Sets the namespaces relevant of this SBML object.
 *
 * @param xmlns the namespaces to set
 */
int
SBase::setNamespaces(XMLNamespaces* xmlns)
{
  if (xmlns == NULL)
  {
    mSBMLNamespaces->setNamespaces(NULL);
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mSBMLNamespaces->setNamespaces(xmlns);
    return LIBSBML_OPERATION_SUCCESS;
  }
}



/*
 * Unsets the metaid of this SBML object.
 */
int
SBase::unsetMetaId ()
{
  mMetaId.erase();

  if (mMetaId.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the notes of this SBML object.
 */
int
SBase::unsetNotes ()
{
  delete mNotes;
  mNotes = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the annotation of this SBML object.
 */
int
SBase::unsetAnnotation ()
{
  XMLNode* empty = NULL;
  return setAnnotation(empty);
}


/*
 * @return the SBML level of this SBML object.
 */
unsigned int
SBase::getLevel () const
{
  if (mSBML != NULL)
    return mSBML->getLevel();
  else if (mSBMLNamespaces != NULL)
    return mSBMLNamespaces->getLevel();
  else
    return SBML_DEFAULT_LEVEL;
}


/*
 * @return the SBML version of this SBML object.
 */
unsigned int
SBase::getVersion () const
{
  if (mSBML != NULL)
    return mSBML->getVersion();
  else if (mSBMLNamespaces != NULL)
    return mSBMLNamespaces->getVersion();
  else
    return SBML_DEFAULT_VERSION;
}


/*
 * @return the typecode (int) of this SBML object or SBML_UNKNOWN
 * (default).
 *
 * This method MAY return the typecode of this SBML object or it MAY
 * return SBML_UNKNOWN.  That is, subclasses of SBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibSBML C interface where class and subclass
 * information is not readily available.
 *
 * @see getElementName()
 */
int
SBase::getTypeCode () const
{
  return SBML_UNKNOWN;
}


bool
SBase::hasValidLevelVersionNamespaceCombination()
{
  int typecode = getTypeCode();
  XMLNamespaces *xmlns = getNamespaces();

  return hasValidLevelVersionNamespaceCombination(typecode, xmlns);
}

/** @cond doxygenLibsbmlInternal */
bool
SBase::matchesSBMLNamespaces(const SBase * sb)
{
  bool match = matchesCoreSBMLNamespace(sb);

  return match;
}

bool
SBase::matchesSBMLNamespaces(const SBase * sb) const
{
  bool match = matchesCoreSBMLNamespace(sb);

  return match;
}


bool
SBase::matchesRequiredSBMLNamespacesForAddition(const SBase * sb)
{
  // if core does not match forget it
  bool match = matchesCoreSBMLNamespace(sb);

  return match;
}


bool
SBase::matchesRequiredSBMLNamespacesForAddition(const SBase * sb) const
{
  // if core does not match forget it
  bool match = matchesCoreSBMLNamespace(sb);

  return match;
}


bool
SBase::matchesCoreSBMLNamespace(const SBase * sb)
{
  bool match = false;

  SBMLNamespaces *sbmlns = getSBMLNamespaces();
  SBMLNamespaces *sbmlns_rhs = sb->getSBMLNamespaces();

  if (sbmlns->getLevel() != sbmlns_rhs->getLevel())
    return match;

  if (sbmlns->getVersion() != sbmlns_rhs->getVersion())
    return match;

  std::string coreNs = SBMLNamespaces::getSBMLNamespaceURI(
                       sbmlns->getLevel(), sbmlns->getVersion());

  if (sbmlns->getNamespaces()->containsUri(coreNs)
    && sbmlns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  return match;
}


bool
SBase::matchesCoreSBMLNamespace(const SBase * sb) const
{
  bool match = false;

  SBMLNamespaces *sbmlns = getSBMLNamespaces();
  SBMLNamespaces *sbmlns_rhs = sb->getSBMLNamespaces();

  if (sbmlns->getLevel() != sbmlns_rhs->getLevel())
    return match;

  if (sbmlns->getVersion() != sbmlns_rhs->getVersion())
    return match;

  std::string coreNs = SBMLNamespaces::getSBMLNamespaceURI(
                       sbmlns->getLevel(), sbmlns->getVersion());

  if (sbmlns->getNamespaces()->containsUri(coreNs)
    && sbmlns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  return match;
}


bool
SBase::hasValidLevelVersionNamespaceCombination(int typecode, XMLNamespaces *xmlns)
{


  //
  // (TODO) Currently, the following check code works only for
  //        elements in SBML core.
  //        This function may need to be extented for other elements
  //        defined in each package extension.
  //

  bool valid = true;
  bool sbmlDeclared = false;
  std::string declaredURI("");

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(SBML_XMLNS_L1V1))
    {
      // checks different SBML XMLNamespaces
      if (numNS > 0) return false;
      ++numNS;
      declaredURI.assign(SBML_XMLNS_L1V1);
    }

    // checks if the SBML Namespace is explicitly defined.
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

  return valid;
}

/* sets the SBMLnamespaces - internal use only*/
int
SBase::setSBMLNamespaces(SBMLNamespaces * sbmlns)
{
  if (sbmlns == NULL)
    return LIBSBML_INVALID_OBJECT;

  SBMLNamespaces* sbmlnsClone = (sbmlns) ? sbmlns->clone() : 0;
  setSBMLNamespacesAndOwn(sbmlnsClone);

  return LIBSBML_OPERATION_SUCCESS;
}

/*
 * sets the SBMLnamespaces - only for internal use in the
 * constructors of SBase subclasses in extension packages.
 */
void
SBase::setSBMLNamespacesAndOwn(SBMLNamespaces * sbmlns)
{
  delete mSBMLNamespaces;
  mSBMLNamespaces = sbmlns;

  if(sbmlns != NULL)
    setElementNamespace(sbmlns->getURI());
}


/* gets the SBMLnamespaces - internal use only*/
SBMLNamespaces *
SBase::getSBMLNamespaces() const
{
  if (mSBML != NULL)
    return mSBML->mSBMLNamespaces;
  
  // initialize SBML namespace if need be
  if (mSBMLNamespaces == NULL)
    const_cast<SBase*>(this)->mSBMLNamespaces = new SBMLNamespaces();
  return mSBMLNamespaces;  
}
/** @endcond */



/*
 * @return the partial SBML that describes this SBML object.
 */
char*
SBase::toSBML ()
{
  ostringstream    os;
  XMLOutputStream  stream(os, "UTF-8", false);

  write(stream);

  return safe_strdup( os.str().c_str() );
}


/** @cond doxygenLibsbmlInternal */
/*
 * Reads (initializes) this SBML object by reading from XMLInputStream.
 */
void
SBase::read (XMLInputStream& stream)
{
  if ( !stream.peek().isStart() ) return;

  const XMLToken  element  = stream.next();
  int             position =  0;

  setSBaseFields( element );

  ExpectedAttributes expectedAttributes;
  addExpectedAttributes(expectedAttributes);
  readAttributes( element.getAttributes(), expectedAttributes );

  /* if we are reading a document pass the
   * SBML Namespace information to the input stream object
   * thus the MathML reader can find out what level/version
   * of SBML it is parsing
   */
  if (element.getName() == "sbml")
  {
 //   stream.setSBMLNamespaces(this->getSBMLNamespaces());
    // need to check that any prefix on the sbmlns also occurs on element
    // remembering the horrible situation where the sbmlns might be declared
    // with more than one prefix
    XMLNamespaces * xmlns = this->getSBMLNamespaces()->getNamespaces();
    if (xmlns != NULL)
    {
      int i = xmlns->getIndexByPrefix(element.getPrefix());
      if (i < xmlns->getNumNamespaces())
      {
        bool errorLoggedAlready = false;
        bool error = false;
        if (i > -1)
        {
          if (xmlns->getURI(i) != this->getSBMLNamespaces()->getURI())
          {
            error = true;
          }
        }
        else if ( i == -1)
        {
          error = true;
        }

        /* if there is a mismatch in level/version this will already
         * be logged; do not need another error
         */
        for (unsigned int n = 0; n < this->getErrorLog()->getNumErrors(); n++)
        {
          unsigned int errorId =
                             this->getErrorLog()->getError(n)->getErrorId();
          if (errorId == MissingOrInconsistentLevel
            || errorId == MissingOrInconsistentVersion
            || errorId == InvalidSBMLLevelVersion
            || errorId == InvalidNamespaceOnSBML)
          {
            errorLoggedAlready = true;
          }
        }

        if (error == true && errorLoggedAlready == false)
        {
          static ostringstream errMsg;
          errMsg.str("");
          errMsg << "The prefix for the <sbml> element does not match "
            << "the prefix for the SBML namespace.  This means that "
            << "the <sbml> element in not in the SBMLNamespace."<< endl;

          logError(InvalidNamespaceOnSBML,
                    getLevel(), getVersion(), errMsg.str());
        }
      }
    }

  }
  else
  {
    //
    // checks if the given default namespace (if any) is a valid
    // SBML namespace
    //
    checkDefaultNamespace(mSBMLNamespaces->getNamespaces(), element.getName());
    if (!element.getPrefix().empty())
    {
      XMLNamespaces * prefixedNS = new XMLNamespaces();
      prefixedNS->add(element.getURI(), element.getPrefix());
      checkDefaultNamespace(prefixedNS, element.getName(), element.getPrefix());
      delete prefixedNS;
    }
  }

  if ( element.isEnd() ) return;

  while ( stream.isGood() )
  {
    // this used to skip the text
    //    stream.skipText();
    // instead, read text and store in variable
    std::string text;
    while(stream.isGood() && stream.peek().isText())
    {
      text += stream.next().getCharacters();
    }
    setElementText(text);

    const XMLToken& next = stream.peek();

    // Re-check stream.isGood() because stream.peek() could hit something.
    if ( !stream.isGood() ) break;

    if ( next.isEndFor(element) )
    {
      stream.next();
      break;
    }
    else if ( next.isStart() )
    {
      const std::string nextName = next.getName();

      SBase * object = createObject(stream);

      if (object != NULL)
      {
        checkOrderAndLogError(object, position);
        position = object->getElementPosition();

        object->connectToParent(static_cast <SBase*>(this));

        object->read(stream);

        if ( !stream.isGood() ) break;

        checkListOfPopulated(object);
      }
      else if ( !( readOtherXML(stream)
                   || readAnnotation(stream)
                   || readNotes(stream) ))
      {
        logUnknownElement(nextName, getLevel(), getVersion());
        stream.skipPastEnd( stream.next() );
      }
    }
    else
    {
      stream.skipPastEnd( stream.next() );
    }
  }
}
/** @endcond */


void
SBase::setElementText(const std::string &text)
{
}

/** @cond doxygenLibsbmlInternal */
/*
 * Writes (serializes) this SBML object by writing it to XMLOutputStream.
 */
void
SBase::write (XMLOutputStream& stream) const
{
  stream.startElement( getElementName(), getPrefix() );

  writeXMLNS     ( stream );
  writeAttributes( stream );
  writeElements  ( stream );

  stream.endElement( getElementName(), getPrefix() );

}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Subclasses should override this method to write out their contained
 * SBML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SBase::writeElements (XMLOutputStream& stream) const
{
  if ( mNotes != NULL ) stream << *mNotes;

  if (mAnnotation != NULL) stream << *mAnnotation;
}


/** @cond doxygenLibsbmlInternal */
/*
 * Subclasses should override this method to create, store, and then
 * return an SBML object corresponding to the next XMLToken in the
 * XMLInputStream.
 *
 * @return the SBML object corresponding to next XMLToken in the
 * XMLInputStream or @c NULL if the token was not recognized.
 */
SBase*
SBase::createObject (XMLInputStream& stream)
{
  return NULL;
}


/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
SBase::readOtherXML (XMLInputStream& stream)
{
  bool read = false;
  return read;
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * @return true if read an <annotation> element from the stream
 */
bool
SBase::readAnnotation (XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "annotation")
  {
    // If an annotation already exists, log it as an error and replace
    // the content of the existing annotation with the new one.

    if (mAnnotation != NULL)
    {
      string msg = "An SBML <" + getElementName() + "> element ";
      msg += "has multiple <annotation> children.";
      logError(MultipleAnnotations, getLevel(), getVersion(), msg);
    }

    delete mAnnotation;
    mAnnotation = new XMLNode(stream);
    checkAnnotation();
    return true;
  }

  return false;
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * @return true if read a <notes> element from the stream
 */
bool
SBase::readNotes (XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "notes")
  {
    // If a notes element already exists, then it is an error.
    // If an annotation element already exists, then the ordering is wrong.
    // In either case, replace existing content with the new notes read.

    if (mNotes != NULL)
    {
      logError(OnlyOneNotesElementAllowed, getLevel(), getVersion());
    }

    delete mNotes;
    mNotes = new XMLNode(stream);

    //
    // checks if the given default namespace (if any) is a valid
    // SBML namespace
    //
    const XMLNamespaces &xmlns = mNotes->getNamespaces();
    checkDefaultNamespace(&xmlns,"notes");

    return true;
  }

  return false;
}

bool
SBase::getHasBeenDeleted() const
{
  return mHasBeenDeleted;
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * @return the ordinal position of the element with respect to its siblings
 * or -1 (default) to indicate the position is not significant.
 */
int
SBase::getElementPosition () const
{
  return -1;
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
SBMLErrorLog*
SBase::getErrorLog ()
{
  return (mSBML != NULL) ? mSBML->getErrorLog() : NULL;
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Helper to log a common type of error.
 */
void
SBase::logUnknownAttribute( const string& attribute,
                            const unsigned int level,
                            const unsigned int version,
                            const string& element,
                            const string& prefix)
{
  ostringstream msg;

    msg << "Attribute '" << attribute << "' is not part of the "
        << "definition of an SBML Level " << level
        << " Version " << version << " <" << element << "> element.";

  if (mSBML)
  {
  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SBMLDocument attached.
  //
        getErrorLog()->logError(AllowedAttributes, level,
          version, msg.str(), getLine(), getColumn());
  }
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Helper to log a common type of error.
 */
void
SBase::logUnknownElement( const string& element,
        const unsigned int level,
        const unsigned int version )
{


    ostringstream msg;

    msg << "Element '" << element << "' is not part of the definition of "
        << "SBML Level " << level << " Version " << version << ".";

    if (mSBML != NULL)
    {
      getErrorLog()->logError(UnrecognizedElement,
            level, version, msg.str(), getLine(), getColumn());
    }
  

}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Helper to log a common type of error.
 */
void
SBase::logEmptyString( const string& attribute,
                       const unsigned int level,
                       const unsigned int version,
                       const string& element )

{
  ostringstream msg;

  msg << "Attribute '" << attribute << "' on an "
    << element << " must not be an empty string.";

  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SBMLDocument attached.
  //
  if (mSBML != NULL)
    getErrorLog()->logError(NotSchemaConformant,
                            level, version, msg.str(), getLine(), getColumn());
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Convenience method for easily logging problems from within method
 * implementations.
 *
 * This is essentially a short form of getErrorLog()->logError(...)
 */
void
SBase::logError (  unsigned int       id
                 , const unsigned int level
                 , const unsigned int version
                 , const std::string& details )
{
  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SBMLDocument attached.
  //
  if ( SBase::getErrorLog() != NULL && mSBML != NULL)
    getErrorLog()->logError(id, getLevel(), getVersion(), details, getLine(), getColumn());
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/**
 * Subclasses should override this method to get the list of
 * expected attributes.
 * This function is invoked from corresponding readAttributes()
 * function.
 */
void
SBase::addExpectedAttributes(ExpectedAttributes& attributes)
{
  //
  // metaid: ID { use="optional" }  (L2v1 ->)
  //
  attributes.add("metaid");
}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SBase::readAttributes (const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)
{
  const_cast<XMLAttributes&>(attributes).setErrorLog(getErrorLog());

  const unsigned int level   = getLevel  ();
  const unsigned int version = getVersion();

  //
  // check that all attributes are expected
  //
  for (int i = 0; i < attributes.getLength(); i++)
  {
    std::string name   = attributes.getName(i);
    std::string uri    = attributes.getURI(i);
    std::string prefix = attributes.getPrefix(i);

    //
    // To allow prefixed attribute whose namespace doesn't belong to
    // core or extension package.
    //
    // (e.g. xsi:type attribute in Curve element in layout extension)
    //
    if (!prefix.empty())
    {
      if ( expectedAttributes.hasAttribute(prefix + ":" + name) ) continue;
    }


    //
    // Checks if there are attributes of unknown package extensions
    //
    // if we happen to be on the sbml element (document) then
    // getPrefix() and mURI have not been set and just return defaults
    // thus a prefix does not appear to come from the right place !!!
    if (!prefix.empty() && getElementName() == "sbml")
    {
      if (!expectedAttributes.hasAttribute(name))
      {
        logUnknownAttribute(name, level, version, getElementName());
      }
    }
    else if (!expectedAttributes.hasAttribute(name))
    {
      logUnknownAttribute(name, level, version, getElementName(), prefix);
    }
  }

    bool assigned = attributes.readInto("metaid", mMetaId, getErrorLog(), false, getLine(), getColumn());

    if (assigned && mMetaId.empty())
    {
      logEmptyString("metaid", level, version,
                     SBMLTypeCode_toString(getTypeCode()));
    }

    if (isSetMetaId())
    {
      if (!SyntaxChecker::isValidXMLID(mMetaId))
      {
        logError(InvalidMetaidSyntax, getLevel(), getVersion(), "The metaid '" + mMetaId + "' does not conform to the syntax.");
      }
  }

}


/** @cond doxygenLibsbmlInternal */
/*
 * Returns the prefix of this element.
 */
std::string
SBase::getPrefix() const
{
  std::string prefix = "";

  const XMLNamespaces *xmlns = getNamespaces();
  string uri = getURI();
  if(xmlns && mSBML && !mSBML->isEnabledDefaultNS(uri))
  {
    prefix = xmlns->getPrefix(uri);
  }

  return prefix;
}


/*
 * Returns the prefix of this element.
 */
std::string
SBase::getSBMLPrefix() const
{
  std::string prefix = "";

  const XMLNamespaces *xmlns = getNamespaces();
  if (xmlns == NULL)
    return getPrefix();

  for (int i = 0; i < xmlns->getNumNamespaces(); i++)
  {
    string uri = xmlns->getURI(i);
    if (SBMLNamespaces::isSBMLNamespace(uri))
      return xmlns->getPrefix(i);
  }

  return getPrefix();
}

/*
 * Returns the root element of this element.
 *
 * @note The root element may not be an SBMLDocument element. For example,
 * this element is the root element if this element doesn't have a parent
 * SBML object (i.e. mParentSBMLObject is NULL)
 */
SBase*
SBase::getRootElement()
{
  if (mSBML)
  {
    return mSBML;
  }
  else if (mParentSBMLObject)
  {
    return mParentSBMLObject->getRootElement();
  }
  else
  {
    return this;
  }
}


/*
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
SBase::writeAttributes (XMLOutputStream& stream) const
{
  string sbmlPrefix    = getSBMLPrefix();
  if ( !mMetaId.empty() )
  {
    stream.writeAttribute("metaid", sbmlPrefix, mMetaId);
  }

}


/*
 *
 * Subclasses should override this method to write their xmlns attriubutes
 * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 *
 */
void
SBase::writeXMLNS (XMLOutputStream& stream) const
{
  // do nothing.
}
/** @endcond */



/** @cond doxygenLibsbmlInternal */
/*
 * Checks that SBML element has been read in the proper order.  If object
 * is not in the expected position, an error is logged.
 */
void
SBase::checkOrderAndLogError (SBase* object, int expected)
{
  int actual = object->getElementPosition();

  if (actual != -1 && actual < expected)
  {
    SBMLErrorCode_t error = IncorrectOrderInModel;

      logError(error, getLevel(), getVersion());
  }
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
  * Checks that an SBML ListOf element has been populated.
  * If a listOf element has been declared with no elements,
  * an error is logged.
  */
void
SBase::checkListOfPopulated(SBase* object)
{
    // for now log the empty list
  if (object->getTypeCode() == SBML_LIST_OF)
  {
    if (static_cast <ListOf*> (object)->size() == 0)
    {
      SBMLErrorCode_t error = EmptyListElement;
      ostringstream errMsg;
      errMsg << object->getElementName() << " cannot be empty.";

      logError(error, getLevel(), getVersion(), errMsg.str());
    }
  }
}
/** @endcond */

//This assumes that the parent of the object is of the type ListOf.  If this is not the case, it will need to be overridden.
int SBase::removeFromParentAndDelete()
{
  SBase* parent = getParentSBMLObject();

  if (parent==NULL) return LIBSBML_OPERATION_FAILED;
  
  ListOf* parentList = static_cast<ListOf*>(parent);
  
  if (parentList == NULL) return LIBSBML_OPERATION_FAILED;
  
  for (unsigned int i=0; i<parentList->size(); i++) 
  {
    SBase* sibling = parentList->get(i);
    if (sibling == this) 
    {
      parentList->remove(i);
      delete this;
      return LIBSBML_OPERATION_SUCCESS;
    }
  }
  return LIBSBML_OPERATION_FAILED;
}

/** @cond doxygenLibsbmlInternal */
const std::string
SBase::checkMathMLNamespace(const XMLToken elem)
{
  std::string prefix = "";
  unsigned int match = 0;
  int n;
  if (elem.getNamespaces().getLength() != 0)
  {
    for (n = 0; n < elem.getNamespaces().getLength(); n++)
    {
      if (!strcmp(elem.getNamespaces().getURI(n).c_str(),
                  "http://www.w3.org/1998/Math/MathML"))
      {
        match = 1;
        break;
      }
    }
  }
  if (match == 0)
  {
    if( mSBML->getNamespaces() != NULL)
    /* check for implicit declaration */
    {
      for (n = 0; n < mSBML->getNamespaces()->getLength(); n++)
      {
        if (!strcmp(mSBML->getNamespaces()->getURI(n).c_str(),
                    "http://www.w3.org/1998/Math/MathML"))
        {
          match = 1;
          prefix = mSBML->getNamespaces()->getPrefix(n);
          break;
        }
      }
    }
  }
  if (match == 0)
  {
    logError(InvalidMathElement, getLevel(), getVersion(), "The MathML namespace 'http://www.w3.org/1998/Math/MathML' was not found.");
  }

  return prefix;
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
void
SBase::checkDefaultNamespace(const XMLNamespaces* xmlns,
                             const std::string& elementName,
                             const std::string& prefix)
{
  //
  // checks if the given default namespace (if any) is a valid
  // SBML namespace
  //
  if (xmlns == NULL || xmlns->getLength() == 0)
    return;

  const std::string defaultURI = xmlns->getURI(prefix);
  if (defaultURI.empty() || mURI == defaultURI)
    return;

  // if this element (SBase derived) has notes or annotation elements,
  // it is ok for them to be in the SBML namespace!
  if ( SBMLNamespaces::isSBMLNamespace(defaultURI)
       && !SBMLNamespaces::isSBMLNamespace(mURI)
       && (elementName == "notes" || elementName == "annotation"))
    return;

  static ostringstream errMsg;
  errMsg.str("");
  errMsg << "xmlns=\"" << defaultURI << "\" in <" << elementName
         << "> element is an invalid namespace." << endl;

  logError(NotSchemaConformant, getLevel(), getVersion(), errMsg.str());

}

/*
  * Checks the annotation does not declare an sbml namespace.
  * If the annotation declares an sbml namespace an error is logged.
  */
void
SBase::checkAnnotation()
{
  unsigned int nNodes = 0;
  unsigned int match = 0;
  int n = 0;
  std::vector<std::string> uri_list;
  uri_list.clear();

  if (mAnnotation == NULL) return;

  //
  // checks if the given default namespace (if any) is a valid
  // SBML namespace
  //
  const XMLNamespaces &xmlns = mAnnotation->getNamespaces();
  checkDefaultNamespace(&xmlns,"annotation");

  while (nNodes < mAnnotation->getNumChildren())
  {
    XMLNode topLevel = mAnnotation->getChild(nNodes);

    // the top level must be an element (so it should be a start)
    if (topLevel.isStart() == false)
    {
      logError(AnnotationNotElement, getLevel(), getVersion());
      nNodes++;
      continue;
    }
    std::string uri = topLevel.getURI();
    std::string prefix = topLevel.getPrefix();

#ifdef USE_LIBXML
    // sometimes libxml does not catch an empty ns with a prefix
    if (uri.empty() && !prefix.empty())
    {
      logError(BadXMLPrefix);
      nNodes++;
      continue;
    }
#endif

    // cannot be other toplevel element with this uri
    if (!uri.empty())
    {
      if (find(uri_list.begin(), uri_list.end(), uri)
                                               != uri_list.end())
      {
        string msg = "An SBML <" + getElementName() + "> element ";
        msg += "has an <annotation> child with multiple children with the same namespace.";
        logError(DuplicateAnnotationNamespaces, getLevel(), getVersion(), msg);
      }
      uri_list.push_back(uri);
    }

    match = 0;
    n = 0;

    bool implicitNSdecl = false;
   // must have a namespace
    if (topLevel.getNamespaces().getLength() == 0)
    {
      // not on actual element - is it explicit ??
      if(mSBML != NULL && mSBML->getNamespaces() != NULL)
      /* check for implicit declaration */
      {
        for (n = 0; n < mSBML->getNamespaces()->getLength(); n++)
        {
          if (!strcmp(mSBML->getNamespaces()->getPrefix(n).c_str(),
                        prefix.c_str()))
          {
            implicitNSdecl = true;
            break;
          }
        }
     }


      if (!implicitNSdecl)
      {
        logError(MissingAnnotationNamespace);
      }
    }
    // cannot declare sbml namespace
    while(!match && n < topLevel.getNamespaces().getLength())
    {
      match += !strcmp(topLevel.getNamespaces().getURI(n).c_str(),
                                          SPEC_NAMESPACE);
      n++;
    }
    string msg = "An SBML <" + getElementName() + "> element ";
    if (match > 0)
    {
      msg += "uses a restricted namespace on an element in its child <annotation>.";
      logError(SBMLNamespaceInAnnotation, getLevel(), getVersion(), msg);
      break;
    }

    if (implicitNSdecl && prefix.empty())
    {
      msg += "assumes the sbml namespace on an element in its child <annotation>.";
      logError(MissingAnnotationNamespace, getLevel(), getVersion(), msg);
    }
    nNodes++;
  }
}
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Checks that the XHTML is valid.
 * If the xhtml does not conform to the specification of valid xhtml within
 * an sbml document, an error is logged.
 */
void
SBase::checkXHTML(const XMLNode * xhtml)
{
  if (xhtml == NULL) return;

  const string&  name = xhtml->getName();
  unsigned int i, errorNS, errorXML, errorDOC, errorELEM;

  if (name == "notes")
  {
    errorNS   = NotesNotInXHTMLNamespace;
    errorXML  = NotesContainsXMLDecl;
    errorDOC  = NotesContainsDOCTYPE;
    errorELEM = InvalidNotesContent;
  }
  else                                  // We shouldn't ever get to this point.
  {
    logError(UnknownError);
    return;
  }

  /*
  * errors relating to a misplaced XML or DOCTYPE declaration
  * will also cause a parser error.
  * since parsing will terminate at this error, then if it has occurred
  * it will be in the XML currently being checked and so a more
  * informative message can be added
  */
  for (i = 0; i < getErrorLog()->getNumErrors(); i++)
  {
    if (getErrorLog()->getError(i)->getErrorId() == BadXMLDeclLocation)
    {
      logError(errorXML);
    }
    if (getErrorLog()->getError(i)->getErrorId() == BadlyFormedXML)
    {
      logError(errorDOC);
    }
  }

  XMLNamespaces* toplevelNS = (mSBML) ? mSBML->getNamespaces() : NULL;

  /*
  * namespace declaration is variable
  * if a whole html tag has been used
  * or a whole body tag then namespace can be implicitly declared
  */
  unsigned int children = xhtml->getNumChildren();

  if (children > 1)
  {
    for (i=0; i < children; i++)
    {
      if (SyntaxChecker::isAllowedElement(xhtml->getChild(i)))
      {
        if (!SyntaxChecker::hasDeclaredNS(xhtml->getChild(i),
                                                  toplevelNS))
        {
          logError(errorNS);
        }
      }
      else
      {
        logError(errorELEM);
      }
    }
  }
  else
  {
    /* only one element which can be html or body with either implicit/explicit
    * namespace declaration
    * OR could be one of the listed elements.
    */

    const string& top_name = xhtml->getChild(0).getName();

    if (top_name != "html" && top_name != "body"
      && !SyntaxChecker::isAllowedElement(xhtml->getChild(0)))
    {
      logError(errorELEM);
    }
    else
    {
      if (!SyntaxChecker::hasDeclaredNS(xhtml->getChild(0), toplevelNS))
      {
        logError(errorNS);
      }
      if (top_name == "html"
        && !SyntaxChecker::isCorrectHTMLNode(xhtml->getChild(0)))
      {
        logError(errorELEM);
      }
    }
  }
}
/** @endcond */
/** @cond doxygenLibsbmlInternal */
/* default for components that have no required attributes */
bool
SBase::hasRequiredAttributes() const
{
  return true;
}

/* default for components that have no required elements */
bool
SBase::hasRequiredElements() const
{
  return true;
}

int
SBase::checkCompatibility(const SBase * object) const
{
  if (object == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (!(object->hasRequiredAttributes()) || !(object->hasRequiredElements()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != object->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != object->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (this->matchesRequiredSBMLNamespacesForAddition(object) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
}

/** @endcond */

/** @cond doxygenLibsbmlInternal */
/*
 * Stores the location (line and column) and any XML namespaces (for
 * roundtripping) declared on this SBML (XML) element.
 */
void
SBase::setSBaseFields (const XMLToken& element)
{
  mLine   = element.getLine  ();
  mColumn = element.getColumn();

  if (element.getNamespaces().getLength() > 0)
  {
    XMLNamespaces tmpxmlns(element.getNamespaces());
    setNamespaces(&tmpxmlns);
  }
  else
  {
    setNamespaces(NULL);
  }
}


/*
 * Sets the XML namespace to which this element belongs to.
 */
int
SBase::setElementNamespace(const std::string &uri)
{
  mURI = uri;

  return LIBSBML_OPERATION_SUCCESS;
}

/*
 * Gets the XML namespace to which this element belongs to.
 */
const std::string&
SBase::getElementNamespace() const
{
  return mURI;
}
/** @endcond */

#endif /* __cplusplus */

LIBSBML_EXTERN
const char *
SBase_getMetaId (SBase_t *sb)
{
  return (sb != NULL && sb->isSetMetaId()) ? sb->getMetaId().c_str() : NULL;
}


LIBSBML_EXTERN
const SBMLDocument_t *
SBase_getSBMLDocument (SBase_t *sb)
{
  return (sb != NULL) ? sb->getSBMLDocument() : NULL;
}


LIBSBML_EXTERN
const SBase_t *
SBase_getParentSBMLObject (SBase_t *sb)
{
  return (sb != NULL) ? sb->getParentSBMLObject() : NULL;
}


LIBSBML_EXTERN
const SBase_t *
SBase_getAncestorOfType (SBase_t *sb, int type)
{
  return (sb != NULL) ? sb->getAncestorOfType(type) : NULL;
}


LIBSBML_EXTERN
unsigned int
SBase_getLevel (const SBase_t *sb)
{
  return (sb != NULL) ? sb->getLevel() : SBML_INT_MAX;
}


LIBSBML_EXTERN
unsigned int
SBase_getVersion (const SBase_t *sb)
{
  return (sb != NULL) ? sb->getVersion() : SBML_INT_MAX;
}


LIBSBML_EXTERN
XMLNode_t *
SBase_getNotes (SBase_t *sb)
{
  return (sb != NULL) ? sb->getNotes() : NULL;
}


LIBSBML_EXTERN
char*
SBase_getNotesString (SBase_t *sb)
{
  return (sb != NULL && sb->isSetNotes()) ?
    safe_strdup(sb->getNotesString().c_str()) : NULL;
}


LIBSBML_EXTERN
XMLNode_t *
SBase_getAnnotation (SBase_t *sb)
{
  return (sb != NULL) ? sb->getAnnotation() : NULL;
}


LIBSBML_EXTERN
char*
SBase_getAnnotationString (SBase_t *sb)
{
  return (sb != NULL && sb->isSetAnnotation()) ?
    safe_strdup(sb->getAnnotationString().c_str()) : NULL;
}


LIBSBML_EXTERN
int
SBase_isSetMetaId (const SBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetMetaId() ) : 0;
}


LIBSBML_EXTERN
int
SBase_isSetNotes (const SBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetNotes() ) : 0;
}


LIBSBML_EXTERN
int
SBase_isSetAnnotation (const SBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetAnnotation() ) : 0;
}


LIBSBML_EXTERN
int
SBase_setMetaId (SBase_t *sb, const char *metaid)
{
  if (sb != NULL)
    return (metaid == NULL) ? sb->unsetMetaId() : sb->setMetaId(metaid);
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_setNamespaces (SBase_t *sb, XMLNamespaces_t *xmlns)
{
  if (sb != NULL)
    return sb->setNamespaces(xmlns);
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_setNotes (SBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->setNotes(notes);
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_setNotesString (SBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if(notes == NULL)
    {
      return sb->unsetNotes();
    }
    else
    {
      return sb->setNotes(notes);
    }
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_setNotesStringAddMarkup (SBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if(notes == NULL)
    {
      return sb->unsetNotes();
    }
    else
    {
      return sb->setNotes(notes, true);
    }
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_appendNotes (SBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->appendNotes(notes);
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_appendNotesString (SBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if (notes != NULL)
      return sb->appendNotes(notes);
    else
      return LIBSBML_INVALID_OBJECT;
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_setAnnotation (SBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->setAnnotation(annotation);
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_setAnnotationString (SBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if(annotation == NULL)
    {
      return sb->unsetAnnotation();
    }
    else
    {
      return sb->setAnnotation(annotation);
    }
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_appendAnnotation (SBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->appendAnnotation(annotation);
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_appendAnnotationString (SBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->appendAnnotation(annotation);
    else
      return LIBSBML_INVALID_OBJECT;
  }
  else
    return LIBSBML_INVALID_OBJECT;
}

LIBSBML_EXTERN
int
SBase_removeTopLevelAnnotationElement (SBase_t *sb, const char *name)
{
  if (sb != NULL)
  {
    if (name != NULL)
      return sb->removeTopLevelAnnotationElement(name);
    else
      return LIBSBML_INVALID_OBJECT;
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_removeTopLevelAnnotationElementWithURI (SBase_t *sb, const char *name,
                                              const char *uri)
{
  if (sb != NULL)
  {
    if (name != NULL && uri != NULL)
      return sb->removeTopLevelAnnotationElement(name, uri);
    else
      return LIBSBML_INVALID_OBJECT;
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_replaceTopLevelAnnotationElement (SBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->replaceTopLevelAnnotationElement(annotation);
    else
      return LIBSBML_INVALID_OBJECT;
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_replaceTopLevelAnnotationElementString (SBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->replaceTopLevelAnnotationElement(annotation);
    else
      return LIBSBML_INVALID_OBJECT;
  }
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_unsetMetaId (SBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetMetaId();
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_unsetNotes (SBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetNotes();
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
SBase_unsetAnnotation (SBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetAnnotation();
  else
    return LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
const char *
SBase_getElementName (const SBase_t *sb)
{
  return (sb != NULL && !(sb->getElementName().empty())) ?
    sb->getElementName().c_str() : NULL;
}


LIBSBML_EXTERN
unsigned int
SBase_getLine (const SBase_t *sb)
{
  return (sb != NULL) ? sb->getLine() : 0;
}


LIBSBML_EXTERN
unsigned int
SBase_getColumn (const SBase_t *sb)
{
  return (sb != NULL) ? sb->getColumn() : 0;
}


LIBSBML_EXTERN
int
SBase_hasValidLevelVersionNamespaceCombination(SBase_t *sb)
{
  return (sb != NULL) ?
    static_cast <int> (sb->hasValidLevelVersionNamespaceCombination()) : 0;
}


LIBSBML_EXTERN
int
SBase_setUserData(SBase_t* sb, void *userData)
{
  if (sb == NULL) return LIBSBML_INVALID_OBJECT;
  return sb->setUserData(userData);
}


LIBSBML_EXTERN
void *
SBase_getUserData(const SBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getUserData();
}

LIBSBML_EXTERN
int
SBase_isSetUserData(const SBase_t* sb)
{
  if (sb == NULL) return 0;
  return static_cast <int>(sb->isSetUserData());
}

LIBSBML_EXTERN
int
SBase_unsetUserData(SBase_t* sb)
{
  if (sb == NULL) return LIBSBML_INVALID_OBJECT;
  return sb->unsetUserData();
}

LIBSBML_EXTERN
SBase_t*
SBase_getElementByMetaId(SBase_t* sb, const char* metaid)
{
  if (sb == NULL) return NULL;
  return sb->getElementByMetaId(metaid);
}

LIBSBML_EXTERN
List_t*
SBase_getAllElements(SBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getAllElements();
}

/** @endcond */

LIBSBML_CPP_NAMESPACE_END
