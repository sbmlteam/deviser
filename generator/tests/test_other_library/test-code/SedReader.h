/**
 * @file SedReader.h
 * @brief Definition of the SedReader class.
 * @author DEVISER
 *
 * @class 
 * @sbmlbrief{} TODO:Definition of the SedReader class.
 */


#ifndef SedReader_h
#define SedReader_h


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sbml/util/util.h>

#ifdef __cplusplus


#include <string>

LIBSEDML_CPP_NAMESPACE_BEGIN

class SedDocument;


class LIBSEDML_EXTERN SedReader
{
public:

  /**
   * Creates a new SedReader object and returns it.
   *
   * The libSed SedReader object offers methods for reading Sed in
   * XML form from files and text strings.
   */
  SedReader ();


  /**
   * Destroys this SedReader.
   */
  virtual ~SedReader ();


  /**
   * This method is identical to
   * @if python @link SedReader::readSedMLFromFile() SedReader.readSedMLFromFile()@endlink@endif@if java @link SedReader::readSedMLFromFile(String) SedReader.readSedMLFromFile(String)@endlink@endif@if cpp SedReader::readSedMLFromFile()@endif@if csharp SedReader.readSedMLFromFile()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SedDocument object created from the Sed
   * content in @p filename.
   *
   * @see readSedMLFromString(@if java String@endif)
   * @see SedError
   * @see SedDocument
   */
  SedDocument* readSedML (const std::string& filename);


  /**
   * This method is identical to
   * @if python @link SedReader::readSedML() SedReader.readSedML()@endlink@endif@if java @link SedReader::readSedML(String) SedReader.readSedML(String)@endlink@endif@if cpp SedReader::readSedML()@endif@if csharp SedReader.readSedML()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SedDocument object created from the Sed
   * content in @p filename.
   *
   * @see readSedMLFromString(@if java String@endif)
   * @see SedError
   * @see SedDocument
   */
  SedDocument* readSedMLFromFile (const std::string& filename);


  /**
   * @param xml a string containing a full Sed model
   *
   * @return a pointer to the SedDocument created from the Sed content,
   * or a null pointer if @p xml is null.
   *
   * @see SedReader::readSedML(@if java String@endif)
   */
  SedDocument* readSedMLFromString (const std::string& xml);


  /**
   * Static method; returns @c true if this copy of libSed supports
   * <i>gzip</I> and <i>zip</i> format compression.
   *
   * @return @c true if libSed has been linked with the <i>zlib</i>
   * library, @c false otherwise.
   *
   * @see @if clike hasBzip2() @else SedReader::hasBzip2()@endif@~
   */
  static bool hasZlib();


  /**
   * Static method; returns @c true if this copy of libSed supports
   * <i>bzip2</i> format compression.
   *
   * @return @c true if libSed is linked with the <i>bzip2</i>
   * libraries, @c false otherwise.
   *
   * @see @if clike hasZlib() @else SedReader::hasZlib()@endif@~
   */
  static bool hasBzip2();


protected:
  /** @cond doxygenLibsedmlInternal */
  /**
   * Used by readSedML() and readSedMLFromString().
   */
  SedDocument* readInternal (const char* content, bool isFile = true);

  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SedReader_t and returns it.
 *
 * By default, XML Schema validation is off.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedReader_t *
SedReader_create (void);


/**
 * Frees the given SedReader_t.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
void
SedReader_free (SedReader_t *sr);


/**
 * This function is identical to SedReader_readSedMLFromFile().
 *
 * @param sr The SedReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the SedDocument structure created from the Sed
 * content read from @p filename.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedML (SedReader_t *sr, const char *filename);


/**
 * This function is identical to SedReader_readSedML().
 *
 * @param sr The SedReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the SedDocument structure created from the Sed
 * content read from @p filename.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedMLFromFile (SedReader_t *sr, const char *filename);


/**
 * @param sr the SedReader_t structure to use
 *
 * @param xml the input xml string.
 *
 * @return a pointer to the SedDocument read.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedMLFromString (SedReader_t *sr, const char *xml);


/**
 * Returns @c true if the underlying libSed supports @em gzip and @em zlib
 * format compression.
 *
 * This predicate tests whether the underlying copy of the libSed library
 * has been linked with the necessary libraries to support @em zlib
 * compression.
 *
 * @return @c non-zero if libSed is linked with zlib, @c zero otherwise.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
int
SedReader_hasZlib ();


/**
 * Returns @c true if the underlying libSed supports @em bzip2 format
 * compression.
 *
 * This predicate tests whether the underlying copy of the libSed library
 * has been linked with the necessary libraries to support @em bzip2
 * compression.
 *
 * @return @c non-zero if libSed is linked with bzip2, @c zero otherwise.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
int
SedReader_hasBzip2 ();

#endif  /* !SWIG */


/**
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedDocument_t *
readSedML (const char *filename);


/**
 * @param filename the name or full pathname of the file to be read.
 *
 * @return a pointer to the SedDocument structure created from the Sed
 * content in @p filename.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedDocument_t *
readSedMLFromFile (const char *filename);


/**
 * @param xml a string containing a full Sed model
 *
 * @return a pointer to the SedDocument structure created from the Sed
 * content in @p xml.
 *
 * @if conly
 * @memberof SedReader_t
 * @endif
 */
LIBSEDML_EXTERN
SedDocument_t *
readSedMLFromString (const char *xml);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedReader_h */
