/**
 * @file TSBReader.h
 * @brief Definition of the TSBReader class.
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
 *
 * @class TSBReader
 * @sbmlbrief{} TODO:Definition of the TSBReader class.
 */


#ifndef TSBReader_h
#define TSBReader_h


#include <tsb/common/extern.h>
#include <tsb/common/tsbfwd.h>

#ifdef __cplusplus


#include <string>

LIBTSB_CPP_NAMESPACE_BEGIN

class TSBDocument;


class LIBTSB_EXTERN TSBReader
{
public:

  /**
   * Creates a new TSBReader object and returns it.
   *
   * The libTSB TSBReader object offers methods for reading TSB in
   * XML form from files and text strings.
   */
  TSBReader ();


  /**
   * Destroys this TSBReader.
   */
  virtual ~TSBReader ();


  /**
   * This method is identical to
   * @if python @link TSBReader::readTSBFromFile() TSBReader.readTSBFromFile()@endlink@endif@if java @link TSBReader::readTSBFromFile(String) TSBReader.readTSBFromFile(String)@endlink@endif@if cpp TSBReader::readTSBFromFile()@endif@if csharp TSBReader.readTSBFromFile()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the TSBDocument object created from the TSB
   * content in @p filename.
   *
   * @see readTSBFromString(@if java String@endif)
   * @see TSBError
   * @see TSBDocument
   */
  TSBDocument* readTSB (const std::string& filename);


  /**
   * This method is identical to
   * @if python @link TSBReader::readTSB() TSBReader.readTSB()@endlink@endif@if java @link TSBReader::readTSB(String) TSBReader.readTSB(String)@endlink@endif@if cpp TSBReader::readTSB()@endif@if csharp TSBReader.readTSB()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the TSBDocument object created from the TSB
   * content in @p filename.
   *
   * @see readTSBFromString(@if java String@endif)
   * @see TSBError
   * @see TSBDocument
   */
  TSBDocument* readTSBFromFile (const std::string& filename);


  /**
   * @param xml a string containing a full TSB model
   *
   * @return a pointer to the TSBDocument created from the TSB content,
   * or a null pointer if @p xml is null.
   *
   * @see TSBReader::readTSB(@if java String@endif)
   */
  TSBDocument* readTSBFromString (const std::string& xml);


  /**
   * Static method; returns @c true if this copy of libTSB supports
   * <i>gzip</I> and <i>zip</i> format compression.
   *
   * @return @c true if libTSB has been linked with the <i>zlib</i>
   * library, @c false otherwise.
   *
   * @see @if clike hasBzip2() @else TSBReader::hasBzip2()@endif@~
   */
  static bool hasZlib();


  /**
   * Static method; returns @c true if this copy of libTSB supports
   * <i>bzip2</i> format compression.
   *
   * @return @c true if libTSB is linked with the <i>bzip2</i>
   * libraries, @c false otherwise.
   *
   * @see @if clike hasZlib() @else TSBReader::hasZlib()@endif@~
   */
  static bool hasBzip2();


protected:
  /** @cond doxygenLibtsbInternal */
  /**
   * Used by readTSB() and readTSBFromString().
   */
  TSBDocument* readInternal (const char* content, bool isFile = true);

  /** @endcond */
};

LIBTSB_CPP_NAMESPACE_END

#endif /* __cplusplus */


LIBTSB_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new TSBReader_t and returns it.
 *
 * By default, XML Schema validation is off.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBReader_t *
TSBReader_create (void);


/**
 * Frees the given TSBReader_t.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
void
TSBReader_free (TSBReader_t *sr);


/**
 * This function is identical to TSBReader_readTSBFromFile().
 *
 * @param sr The TSBReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the TSBDocument structure created from the TSB
 * content read from @p filename.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBDocument_t *
TSBReader_readTSB (TSBReader_t *sr, const char *filename);


/**
 * This function is identical to TSBReader_readTSB().
 *
 * @param sr The TSBReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the TSBDocument structure created from the TSB
 * content read from @p filename.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBDocument_t *
TSBReader_readTSBFromFile (TSBReader_t *sr, const char *filename);


/**
 * @param sr the TSBReader_t structure to use
 *
 * @param xml the input xml string.
 *
 * @return a pointer to the TSBDocument read.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBDocument_t *
TSBReader_readTSBFromString (TSBReader_t *sr, const char *xml);


/**
 * Returns @c true if the underlying libTSB supports @em gzip and @em zlib
 * format compression.
 *
 * This predicate tests whether the underlying copy of the libTSB library
 * has been linked with the necessary libraries to support @em zlib
 * compression.
 *
 * @return @c non-zero if libTSB is linked with zlib, @c zero otherwise.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
int
TSBReader_hasZlib ();


/**
 * Returns @c true if the underlying libTSB supports @em bzip2 format
 * compression.
 *
 * This predicate tests whether the underlying copy of the libTSB library
 * has been linked with the necessary libraries to support @em bzip2
 * compression.
 *
 * @return @c non-zero if libTSB is linked with bzip2, @c zero otherwise.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
int
TSBReader_hasBzip2 ();

#endif  /* !SWIG */


/**
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBDocument_t *
readTSB (const char *filename);


/**
 * @param filename the name or full pathname of the file to be read.
 *
 * @return a pointer to the TSBDocument structure created from the TSB
 * content in @p filename.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBDocument_t *
readTSBFromFile (const char *filename);


/**
 * @param xml a string containing a full TSB model
 *
 * @return a pointer to the TSBDocument structure created from the TSB
 * content in @p xml.
 *
 * @if conly
 * @memberof TSBReader_t
 * @endif
 */
LIBTSB_EXTERN
TSBDocument_t *
readTSBFromString (const char *xml);


END_C_DECLS
LIBTSB_CPP_NAMESPACE_END

#endif  /* TSBReader_h */
