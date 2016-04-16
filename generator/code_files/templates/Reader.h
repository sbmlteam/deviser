#ifndef SBMLReader_h
#define SBMLReader_h


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
<verbatim>
#include <sbml/util/util.h>
</verbatim>

#ifdef __cplusplus


#include <string>

LIBSBML_CPP_NAMESPACE_BEGIN

class SBMLDocument;


class LIBSBML_EXTERN SBMLReader
{
public:

  /**
   * Creates a new SBMLReader object and returns it.
   *
   * The libSBML SBMLReader object offers methods for reading SBML in
   * XML form from files and text strings.
   */
  SBMLReader ();


  /**
   * Destroys this SBMLReader.
   */
  virtual ~SBMLReader ();


  /**
   * This method is identical to
   * @if python @link SBMLReader::readSBMLFromFile() SBMLReader.readSBMLFromFile()@endlink@endif@if java @link SBMLReader::readSBMLFromFile(String) SBMLReader.readSBMLFromFile(String)@endlink@endif@if cpp SBMLReader::readSBMLFromFile()@endif@if csharp SBMLReader.readSBMLFromFile()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SBMLDocument object created from the SBML
   * content in @p filename.
   *
   * @see readSBMLFromString(@if java String@endif)
   * @see SBMLError
   * @see SBMLDocument
   */
  SBMLDocument* readSBML (const std::string& filename);


  /**
   * This method is identical to
   * @if python @link SBMLReader::readSBML() SBMLReader.readSBML()@endlink@endif@if java @link SBMLReader::readSBML(String) SBMLReader.readSBML(String)@endlink@endif@if cpp SBMLReader::readSBML()@endif@if csharp SBMLReader.readSBML()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SBMLDocument object created from the SBML
   * content in @p filename.
   *
   * @see readSBMLFromString(@if java String@endif)
   * @see SBMLError
   * @see SBMLDocument
   */
  SBMLDocument* readSBMLFromFile (const std::string& filename);


  /**
   * @param xml a string containing a full SBML model
   *
   * @return a pointer to the SBMLDocument created from the SBML content,
   * or a null pointer if @p xml is null.
   *
   * @see SBMLReader::readSBML(@if java String@endif)
   */
  SBMLDocument* readSBMLFromString (const std::string& xml);


  /**
   * Static method; returns @c true if this copy of libSBML supports
   * <i>gzip</I> and <i>zip</i> format compression.
   *
   * @return @c true if libSBML has been linked with the <i>zlib</i>
   * library, @c false otherwise.
   *
   * @see @if clike hasBzip2() @else SBMLReader::hasBzip2()@endif@~
   */
  static bool hasZlib();


  /**
   * Static method; returns @c true if this copy of libSBML supports
   * <i>bzip2</i> format compression.
   *
   * @return @c true if libSBML is linked with the <i>bzip2</i>
   * libraries, @c false otherwise.
   *
   * @see @if clike hasZlib() @else SBMLReader::hasZlib()@endif@~
   */
  static bool hasBzip2();


protected:
  /** @cond doxygenLibsbmlInternal */
  /**
   * Used by readSBML() and readSBMLFromString().
   */
  SBMLDocument* readInternal (const char* content, bool isFile = true);

  /** @endcond */
};

LIBSBML_CPP_NAMESPACE_END

#endif /* __cplusplus */


LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SBMLReader_t and returns it.
 *
 * By default, XML Schema validation is off.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLReader_t *
SBMLReader_create (void);


/**
 * Frees the given SBMLReader_t.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
void
SBMLReader_free (SBMLReader_t *sr);


/**
 * This function is identical to SBMLReader_readSBMLFromFile().
 *
 * @param sr The SBMLReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the SBMLDocument structure created from the SBML
 * content read from @p filename.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLDocument_t *
SBMLReader_readSBML (SBMLReader_t *sr, const char *filename);


/**
 * This function is identical to SBMLReader_readSBML().
 *
 * @param sr The SBMLReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the SBMLDocument structure created from the SBML
 * content read from @p filename.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLDocument_t *
SBMLReader_readSBMLFromFile (SBMLReader_t *sr, const char *filename);


/**
 * @param sr the SBMLReader_t structure to use
 *
 * @param xml the input xml string.
 *
 * @return a pointer to the SBMLDocument read.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLDocument_t *
SBMLReader_readSBMLFromString (SBMLReader_t *sr, const char *xml);


/**
 * Returns @c true if the underlying libSBML supports @em gzip and @em zlib
 * format compression.
 *
 * This predicate tests whether the underlying copy of the libSBML library
 * has been linked with the necessary libraries to support @em zlib
 * compression.
 *
 * @return @c non-zero if libSBML is linked with zlib, @c zero otherwise.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
int
SBMLReader_hasZlib ();


/**
 * Returns @c true if the underlying libSBML supports @em bzip2 format
 * compression.
 *
 * This predicate tests whether the underlying copy of the libSBML library
 * has been linked with the necessary libraries to support @em bzip2
 * compression.
 *
 * @return @c non-zero if libSBML is linked with bzip2, @c zero otherwise.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
int
SBMLReader_hasBzip2 ();

#endif  /* !SWIG */


/**
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLDocument_t *
readSBML (const char *filename);


/**
 * @param filename the name or full pathname of the file to be read.
 *
 * @return a pointer to the SBMLDocument structure created from the SBML
 * content in @p filename.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLDocument_t *
readSBMLFromFile (const char *filename);


/**
 * @param xml a string containing a full SBML model
 *
 * @return a pointer to the SBMLDocument structure created from the SBML
 * content in @p xml.
 *
 * @if conly
 * @memberof SBMLReader_t
 * @endif
 */
LIBSBML_EXTERN
SBMLDocument_t *
readSBMLFromString (const char *xml);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* SBMLReader_h */
