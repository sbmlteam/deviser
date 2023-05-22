/**
 * @file TSBWriter.cpp
 * @brief Implementation of the TSBWriter class.
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


#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>

#include <tsb/common/common.h>
#include <xml/XMLOutputStream.h>

#include <tsb/TSBError.h>
#include <tsb/TSBErrorLog.h>
#include <tsb/TSBDocument.h>
#include <tsb/TSBWriter.h>

#include <compress/CompressCommon.h>
#include <compress/OutputCompressor.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBTSB_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/*
 * Creates a new TSBWriter.
 */
TSBWriter::TSBWriter ()
{
}


/*
 * Destroys this TSBWriter.
 */
TSBWriter::~TSBWriter ()
{
}


/*
 * Sets the name of this program. i.\ e.\ the one about to write out the
 * TSBDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libtsb version <libtsb version>. -->
 */
int
TSBWriter::setProgramName (const std::string& name)
{
  mProgramName = name;
  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * TSBDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libtsb version <libtsb version>. -->
 */
int
TSBWriter::setProgramVersion (const std::string& version)
{
  mProgramVersion = version;
  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Writes the given TSBDocument to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 *
 * @note To create a gzip/zip file, underlying libTSB needs to be linked with zlib at 
 * compile time. Also, underlying libTSB needs to be linked with bzip2 to create a 
 * bzip2 file.
 * File unwritable error will be logged and @c false will be returned if a compressed 
 * file name is given and underlying libTSB is not linked with the corresponding 
 * required library.
 * TSBWriter::hasZlib() and TSBWriter::hasBzip2() can be used to check whether
 * underlying libTSB is linked with the library.
 *
 * @return true on success and false if the filename could not be opened
 * for writing.
 */
bool
TSBWriter::writeTSB (const TSBDocument* d, const std::string& filename)
{
  std::ostream* stream = NULL;

  try
  {
    // open an uncompressed XML file.
    if ( string::npos != filename.find(".xml", filename.length() - 4) )
    {
      stream = new(std::nothrow) std::ofstream(filename.c_str());
    }
    // open a gzip file
    else if ( string::npos != filename.find(".gz", filename.length() - 3) )
    {
     stream = OutputCompressor::openGzipOStream(filename);
    }
    // open a bz2 file
    else if ( string::npos != filename.find(".bz2", filename.length() - 4) )
    {
      stream = OutputCompressor::openBzip2OStream(filename);
    }
    // open a zip file
    else if ( string::npos != filename.find(".zip", filename.length() - 4) )
    {
      std::string filenameinzip = filename.substr(0, filename.length() - 4);
  
      if ( ( string::npos == filenameinzip.find(".xml",  filenameinzip.length() - 4) ) &&
           ( string::npos == filenameinzip.find(".tsb", filenameinzip.length() - 5) )
         )
      {
        filenameinzip += ".xml";
      }


#if defined(WIN32) && !defined(CYGWIN)
      char sepr = '\\';
#else
      char sepr = '/';
#endif
      size_t spos = filenameinzip.rfind(sepr, filenameinzip.length() - 1);
      if( spos != string::npos )
      {
        filenameinzip = filenameinzip.substr(spos + 1, filenameinzip.length() - 1);
      }

      
      stream = OutputCompressor::openZipOStream(filename, filenameinzip);
    }
    else
    {
      stream = new(std::nothrow) std::ofstream(filename.c_str());
    }
  }
  catch ( ZlibNotLinked& )
  {
    // libTSB is not linked with zlib.
    XMLErrorLog *log = (const_cast<TSBDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a gzip/zip file is not enabled because "
        << "underlying libTSB is not linked with zlib."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 
  catch ( Bzip2NotLinked& )
  {
    // libTSB is not linked with bzip2.
    XMLErrorLog *log = (const_cast<TSBDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a bzip2 file is not enabled because "
        << "underlying libTSB is not linked with bzip2."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 


  if ( stream == NULL || stream->fail() || stream->bad())
  {
    TSBErrorLog *log = (const_cast<TSBDocument *>(d))->getErrorLog();
    log->logError(XMLFileUnwritable);
    delete stream;
    return false;
  }

   bool result = writeTSB(d, *stream);
   delete stream;

   return result;

}


/*
 * Writes the given TSBDocument to the output stream.
 *
 * @return true on success and false if one of the underlying parser
 * components fail (rare).
 */
bool
TSBWriter::writeTSB (const TSBDocument* d, std::ostream& stream)
{
  bool result = false;

  try
  {
    stream.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    XMLOutputStream xos(stream, "UTF-8", true, mProgramName, 
                                               mProgramVersion);
    d->write(xos);
    stream << endl;

    result = true;
  }
  catch (ios_base::failure&)
  {
    TSBErrorLog *log = (const_cast<TSBDocument *>(d))->getErrorLog();
    log->logError(XMLFileOperationError);
  }

  return result;
}


/** @cond doxygenLibtsbInternal */
/*
 * Writes the given TSBDocument to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and 0 if one of the underlying parser
 * components fail (rare).
 */
LIBTSB_EXTERN
char*
TSBWriter::writeToString (const TSBDocument* d)
{
  ostringstream stream;
  writeTSB(d, stream);

  return tsb_safe_strdup( stream.str().c_str() );
}

std::string 
TSBWriter::writeTSBToStdString(const TSBDocument* d)
{
  if (d == NULL) return "";
  
  ostringstream stream;
  writeTSB(d, stream);
  return stream.str();
}

LIBTSB_EXTERN
char*
TSBWriter::writeTSBToString (const TSBDocument* d)
{
  return writeToString(d);
}
/** @endcond */


LIBTSB_EXTERN
bool
TSBWriter::writeTSBToFile (const TSBDocument* d, const std::string& filename)
{
  return writeTSB(d, filename);
}


/*
 * Predicate returning @c true if
 * underlying libTSB is linked with zlib.
 *
 * @return @c true if libTSB is linked with zlib, @c false otherwise.
 */
bool 
TSBWriter::hasZlib() 
{
  return LIBTSB_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * underlying libTSB is linked with bzip2.
 *
 * @return @c true if libTSB is linked with bzip2, @c false otherwise.
 */
bool 
TSBWriter::hasBzip2() 
{
  return LIBTSB_CPP_NAMESPACE ::hasBzip2();
}


#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBTSB_EXTERN
TSBWriter_t *
TSBWriter_create ()
{
  return new(nothrow) TSBWriter;
}


LIBTSB_EXTERN
void
TSBWriter_free (TSBWriter_t *sw)
{
  delete sw;
}


LIBTSB_EXTERN
int
TSBWriter_setProgramName (TSBWriter_t *sw, const char *name)
{
  if (sw != NULL)
    return (name == NULL) ? sw->setProgramName("") : sw->setProgramName(name);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
int
TSBWriter_setProgramVersion (TSBWriter_t *sw, const char *version)
{
  if (sw != NULL)
    return (version == NULL) ? sw->setProgramVersion("") :
                             sw->setProgramVersion(version);
  else
    return LIBTSB_INVALID_OBJECT;
}


LIBTSB_EXTERN
int
TSBWriter_writeTSB ( TSBWriter_t         *sw,
                       const TSBDocument_t *d,
                       const char           *filename )
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return (filename != NULL) ? 
      static_cast<int>( sw->writeTSB(d, filename) ) : 0;
}


LIBTSB_EXTERN
int
TSBWriter_writeTSBToFile ( TSBWriter_t         *sw,
                       const TSBDocument_t *d,
                       const char           *filename )
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return (filename != NULL) ? 
      static_cast<int>( sw->writeTSB(d, filename) ) : 0;
}


LIBTSB_EXTERN
char *
TSBWriter_writeTSBToString (TSBWriter_t *sw, const TSBDocument_t *d)
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return sw->writeToString(d);
}


LIBTSB_EXTERN
int
TSBWriter_hasZlib ()
{
  return static_cast<int>( TSBWriter::hasZlib() );
}


LIBTSB_EXTERN
int
TSBWriter_hasBzip2 ()
{
   return static_cast<int>( TSBWriter::hasBzip2() );
}


LIBTSB_EXTERN
int
writeTSB (const TSBDocument_t *d, const char *filename)
{
  TSBWriter sw;
  if (d == NULL || filename == NULL)
    return 0;
  else
    return static_cast<int>( sw.writeTSB(d, filename) );
}


LIBTSB_EXTERN
int
writeTSBToFile (const TSBDocument_t *d, const char *filename)
{
  TSBWriter sw;
  if (d == NULL || filename == NULL)
    return 0;
  else
    return static_cast<int>( sw.writeTSB(d, filename) );
}


LIBTSB_EXTERN
char *
writeTSBToString (const TSBDocument_t *d)
{
  TSBWriter sw;
  if (d == NULL)
    return NULL;
  else
    return sw.writeToString(d);
}

LIBTSB_EXTERN
std::string writeTSBToStdString(const TSBDocument* d)
{
  TSBWriter sw;
  if (d == NULL)
    return "";
  else
    return sw.writeTSBToStdString(d);
}
/** @endcond */

LIBTSB_CPP_NAMESPACE_END

