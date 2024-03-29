cmake_minimum_required(VERSION 2.8.12)
project(libsedml)
if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

set(LIBSEDML_ROOT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH
    "Path to the libSEDML root source directory")
set(LIBSEDML_ROOT_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}" CACHE PATH
    "Path to the libSEDML root build directory")

include (CMakeTestCCompiler)
include (CheckCSourceCompiles)
include (CheckCXXSourceCompiles)
include (CheckStructHasMember)
include (CheckLibraryExists)
include (CheckFunctionExists)
include (CheckCCompilerFlag)
include (CheckCSourceRuns)
include (CheckSymbolExists)
include (CheckTypeSize)
include (GNUInstallDirs)

###############################################################################
#
# Parse VERSION.txt to determine the package version
#

set(LIBSEDML_VERSION_MAJOR)
set(LIBSEDML_VERSION_MINOR)
set(LIBSEDML_VERSION_PATCH)
set(LIBSEDML_VERSION_RELEASE)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt")

    file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt" VersionString NEWLINE_CONSUME)
    string(STRIP "${VersionString}" VersionString)
    string(REPLACE "." ";" VersionString "${VersionString}" )
    string(REPLACE "-" ";" VersionString "${VersionString}" )
    list(LENGTH VersionString versionLength)
    list(GET VersionString 0 LIBSEDML_VERSION_MAJOR )
    list(GET VersionString 1 LIBSEDML_VERSION_MINOR )
    list(GET VersionString 2 LIBSEDML_VERSION_PATCH )

    if(${versionLength} GREATER 3)
        list(GET VersionString 3 LIBSEDML_VERSION_RELEASE )
    endif()

endif()

MATH(EXPR LIBSEDML_VERSION_NUMERIC "${LIBSEDML_VERSION_MAJOR} * 10000 + ${LIBSEDML_VERSION_MINOR} * 100 + ${LIBSEDML_VERSION_PATCH}" )
set(PACKAGE_VERSION "${LIBSEDML_VERSION_MAJOR}.${LIBSEDML_VERSION_MINOR}.${LIBSEDML_VERSION_PATCH}${LIBSEDML_VERSION_RELEASE}")
set(PACKAGE_NAME "libSEDML")

###############################################################################
#
# The next lines configure the parameters for packaging the binaries.
# They can be invoked with "make package" or "nmake package" or by using
# cpack -G zip|deb|rpm|dmg|nsis
#

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An API library for reading/writing/manipulating SEDML.")
set(CPACK_PACKAGE_NAME "${PACKAGE_NAME}")
set(CPACK_PACKAGE_VENDOR "The SBML Team")
set(CPACK_PACKAGE_CONTACT "The SBML Team <sbml-team@caltech.edu>")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${LIBSEDML_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${LIBSEDML_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${LIBSEDML_VERSION_PATCH}")
set(CPACK_RPM_PACKAGE_LICENSE "BSD")
set(CPACK_RPM_PACKAGE_GROUP "Libraries/Development")
set(CPACK_DEBIAN_PACKAGE_SECTION "Libraries")

set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_CURRENT_BINARY_DIR};/out/;/.git/;/.svn/;/.libs/;/.deps/;/.bzr/;.*.pyc$;.*.o$;.*.lo$;.*.la$;${CPACK_SOURCE_IGNORE_FILES};/.DS_Store;/.svnignore;blib;libsedml-dist")

if(UNIX)
    set(CPACK_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
    set(CPACK_SET_DESTDIR "ON")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")
    set(CPACK_RPM_PACKAGE_ARCHITECTURE "i386")
else()
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
    set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
endif()

include(CPack)


###############################################################################
#
# Here we have the main configuration options for libsedml.
#

# Whether to compile examples
option(WITH_EXAMPLES "Compile the libSEDML example programs."  OFF)

#############
# LATER TO DO
# Which language bindings should be built
# option(WITH_CSHARP   "Generate C# language bindings."     OFF)
# option(WITH_JAVA     "Generate Java language bindings."   OFF)
# option(WITH_PYTHON   "Generate Python language bindings." OFF)
# option(WITH_PERL     "Generate Perl language bindings."   OFF)
# option(WITH_RUBY     "Generate Ruby language bindings"    OFF)
# option(WITH_R        "Generate R language bindings"       OFF)

# Add an option to compile with all warnings shown
option(WITH_WALL     "Compile with -Wall, so that the compiler will display all warnings." OFF)
mark_as_advanced(WITH_WALL)

if(WITH_WALL)
    if(MSVC OR USING_INTEL)
        add_definitions(/W4)
    else()
        add_definitions(-Wall)
    endif()
endif()


set(LIBSEDML_BUILD_TYPE "native")
if (CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(LIBSEDML_BUILD_TYPE "32bit")
else()
  set(LIBSEDML_BUILD_TYPE "64bit")
endif()
if (APPLE AND ENABLE_UNIVERSAL)
  set(LIBSEDML_BUILD_TYPE "universal")
endif()


# Use the version number in the shared library.
#
option (LIBSEDML_SHARED_VERSION "Build the libsedml shared library with version information" ON)
mark_as_advanced(LIBSEDML_SHARED_VERSION)

# Enable the generation of unit tests. If enabled, all test runners
# will be created and can be run with "make test" or ctest.
# This won't work in Visual Studio 2003, so we disable this option there.
#
if(NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 6" AND NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
    option(WITH_CHECK    "Compile unit tests. Run with 'make test' or 'ctest'." OFF)
endif()

# Use C++ namespace.
option(WITH_CPP_NAMESPACE "Use a C++ namespace for libSEDML."   OFF)

#############
# LATER TO DO
# Generate documentation.
# option(WITH_DOXYGEN  "Generate documentation for libSEDML using Doxygen."  OFF )
# marks as advanced, so as to hide documentation generation
# mark_as_advanced(WITH_DOXYGEN)

#############
# LATER TO DO
# Re-generate the swig bindings? This really should be on by default
# otherwise one might have the wrong wrapper code without support for
# the libsedml packages one wants.
# option(WITH_SWIG     "Regenerate SWIG-based language bindings."  ON )

# Set build type default.
set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the build type. The options are: None (CMAKE_CXX_FLAGS or
     CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel.")
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
  "Choose the build type. The options are: None (CMAKE_CXX_FLAGS or
  CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif()

# Set the default dependency directory.
set(LIBSEDML_DEPENDENCY_DIR ${CMAKE_SOURCE_DIR}/dependencies/ CACHE PATH
    "Directory containing libraries that libSEDML depends upon. (Particularly important on Windows.)")
if("${LIBSEDML_DEPENDENCY_DIR}" STREQUAL "")
  set(LIBSEDML_DEPENDENCY_DIR ${CMAKE_SOURCE_DIR}/dependencies/ CACHE PATH
  "Directory containing libraries that libSEDML depends upon. (Particularly important on Windows.)" FORCE)
endif()


###############################################################################
#
# If WITH_SWIG is selected, we need to find swig
#

set (LIBSEDML_USE_CPP_NAMESPACE 0)
if(WITH_CPP_NAMESPACE)
    add_definitions(-DLIBSEDML_USE_CPP_NAMESPACE)
    set (LIBSEDML_USE_CPP_NAMESPACE 1)
endif()

if(WITH_SWIG)
    find_program(SWIG_EXECUTABLE
      NAMES swig
      PATHS
        c:/swigwin-3.0.12
        c:/swigwin-3.0.10
        c:/swigwin-3.0.8
        c:/swigwin-3.0.5
        c:/swigwin-3.0.2
        c:/swigwin-3.0.0
        c:/swigwin-2.0.12
        c:/swigwin-2.0.11
        c:/swigwin-2.0.10
        c:/swigwin-2.0.9
        c:/swigwin-2.0.8
        c:/swigwin-2.0.7
        c:/swigwin-2.0.4
        c:/swigwin-2.0.2
        c:/swigwin-2.0.1
        c:/swigwin-2.0.0
        /usr/local/bin
        /opt/local/bin
        /usr/bin
      DOC "The file name of the swig executable."
      )
    set(SWIG_EXTRA_ARGS)
endif(WITH_SWIG)

###############################################################################
#
# Choose which library to link to.
#

option (WITH_LIBLX "Build linked to libLX" ON)
option (WITH_LIBSBML "Build linked to libSBML" OFF)

if (WITH_LIBLX)

    # locate liblx
    find_library(LIBLX_LIBRARY
        NAMES liblx.lib liblx-static.lib
        PATHS ${LIBSEDML_DEPENDENCY_DIR}/lib
        /usr/local/lib          
        /usr/lib 
        DOC "The file name of the libLX library."
    )

    find_path(LIBLX_INCLUDE_DIR
        NAMES liblx/common/liblx-version.h
        PATHS ${LIBSEDML_DEPENDENCY_DIR}/include
        /usr/local/include
        /usr/include 
        DOC "The directory containing the libLX include files."
    )

    # to make seamless use of libsbml/liblx we want include dir to have sbml or liblax already included
    set(XTRA_INC "${LIBLX_INCLUDE_DIR}/liblx")
    set(LIBLX_INCLUDE_DIR "${LIBLX_INCLUDE_DIR}")
    set(LINKED_LIBRARY ${LIBLX_LIBRARY})
    set(LINKED_INCLUDE_DIR ${LIBLX_INCLUDE_DIR})
    set(LINKED_NAME "libLX")

    set(LIBLX_STATIC OFF CACHE BOOL "is libLX statically compiled")

    if (WIN32 AND NOT CYGWIN)
        if (LINKED_LIBRARY AND LINKED_LIBRARY MATCHES ".*-static*$")
            set(LIBLX_STATIC ON CACHE BOOL "is libLX statically compiled")
        else()
            option(LIBLX_STATIC "The libLX library was statically compiled" ON)
        endif()
    endif()

    if (NOT EXISTS "${LIBLX_INCLUDE_DIR}/liblx/common/liblx-version.h")
        message(FATAL_ERROR 
        "The include directory ${LIBLX_INCLUDE_DIR} specified for libLX appears to be invalid. 
        It should contain the file common/liblx-version.h, but it does not. 
        Please specify the LIBLX_INCLUDE_DIR variable.")
    endif()
endif()

if (WITH_LIBSBML)

    # Locate libsbml
    find_library(LIBSBML_LIBRARY
        NAMES libsbml-static.lib sbml-static libsbml.lib sbml
        PATHS ${LIBSEDML_DEPENDENCY_DIR}/lib
        /usr/local/lib          
        /usr/lib 
        DOC "The file name of the sbml library."
    )

    find_path(LIBSBML_INCLUDE_DIR
        NAMES sbml/SBase.h
        PATHS ${LIBSEDML_DEPENDENCY_DIR}/include
        /usr/local/include
        /usr/include 
        DOC "The directory containing the sbml include files."
    )

    # to make seamless use of libsbml/liblx we want include dir to have sbml or liblax already included
    set(LIBSBML_INCLUDE_DIR "${LIBSBML_INCLUDE_DIR}")
    set(XTRA_INC "${LIBSBML_INCLUDE_DIR}/sbml")
    set(LINKED_LIBRARY ${LIBSBML_LIBRARY})
    set(LINKED_INCLUDE_DIR ${LIBSBML_INCLUDE_DIR})
    set(LINKED_NAME "libSBML")

    set(LIBSBML_STATIC OFF CACHE BOOL "is libsbml statically compiled")

    if (WIN32 AND NOT CYGWIN)
        if (LIBSBML_LIBRARY AND LIBSBML_LIBRARY MATCHES ".*-static*$")
            set(LIBSBML_STATIC ON CACHE BOOL "is libsbml statically compiled")
        else()
            option(LIBSBML_STATIC "The LibSBML library was statically compiled" ON)
        endif()
    endif()

    if(NOT EXISTS "${LIBSBML_INCLUDE_DIR}/sbml/SBase.h")
        message(FATAL_ERROR 
        "The include directory ${LIBSBML_INCLUDE_DIR} specified for sbml appears to be invalid. 
        It should contain the file sbml/SBase.h, but it does not. 
        Please specify the LIBSBML_INCLUDE_DIR variable.")
    endif()
endif()

# check only one option is selected
set(LIBRARY_COUNT 0)

if(WITH_LIBLX)
    math(EXPR LIBRARY_COUNT "${LIBRARY_COUNT} + 1")
endif()
if(WITH_LIBSBML)
    math(EXPR LIBRARY_COUNT "${LIBRARY_COUNT} + 1")
endif()

if(LIBRARY_COUNT GREATER 1)
    message(FATAL_ERROR
    "Only one linked library should be chosen. Please select only one of the following options: WITH_LIBSBML or WITH_LIBLX.")
elseif(LIBRARY_COUNT EQUAL 0)
    message(FATAL_ERROR 
    "The ${LIBSEDML_LIBRARY} must be linked against either libLX or libSBML. Neither can be found.")
endif()

set (LIBSEDML_LIBS ${LIBSEDML_LIBS} ${LINKED_LIBRARY})

    set(LINKED_LIBRARY ${LIBLX_LIBRARY})
    set (LINKED_INCLUDE_DIR ${LIBLX_INCLUDE_DIR})
    set(LINKED_NAME "libLX")

    set(LIBLX_STATIC OFF CACHE BOOL "is libLX statically compiled")
    if (WIN32 AND NOT CYGWIN)
        if (LINKED_LIBRARY AND LINKED_LIBRARY MATCHES ".*-static*$")
            set(LIBLX_STATIC ON CACHE BOOL "is libLX statically compiled")
        else()
            option(LIBLX_STATIC "The libLX library was statically compiled" ON)
        endif()
    endif()


    if (NOT EXISTS "${LIBLX_INCLUDE_DIR}/liblx/common/liblx-version.h")
        message(FATAL_ERROR "The include directory ${LIBLX_INCLUDE_DIR} specified for libLX appears to be invalid. 
        It should contain the file common/liblx-version.h, but it does not. 
        Please specify the LIBLX_INCLUDE_DIR variable.")
    endif()

endif()

if (WITH_LIBSBML)
    # Locate libsbml
    find_library(LIBSBML_LIBRARY
        NAMES libsbml-static.lib sbml-static libsbml.lib sbml
        PATHS ${LIBSEDML_DEPENDENCY_DIR}/lib
        /usr/local/lib          
            /usr/lib 
        DOC "The file name of the sbml library."
    )

    find_path(LIBSBML_INCLUDE_DIR
        NAMES sbml/SBase.h
        PATHS 
          ${LIBSEDML_DEPENDENCY_DIR}/include
        /usr/local/include
            /usr/include 
        DOC "The directory containing the sbml include files."
    )

    # to make seamless use of libsbml/liblx we want include dir to
    # have sbml or liblax already included
    set(LIBSBML_INCLUDE_DIR "${LIBSBML_INCLUDE_DIR}")
    set(XTRA_INC "${LIBSBML_INCLUDE_DIR}/sbml")

    set(LINKED_LIBRARY ${LIBSBML_LIBRARY})
    set (LINKED_INCLUDE_DIR ${LIBSBML_INCLUDE_DIR})
    set(LINKED_NAME "libSBML")

###############################################################################
#
# Find the C# compiler to use and set name for resulting library
#

if(WITH_CSHARP)

    find_program(CSHARP_COMPILER
        NAMES gmcs csc
        PATHS C:/Windows/Microsoft.NET/Framework/v2.0.50727/ /usr/bin /usr/local/bin
        DOC "The file name of the C# compiler."
        )
    if(UNIX)
    else()
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            # mark libsedml library as x86
            set(CSHARP_EXTRA_ARGS -platform:x86 )
        elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
            # mark libsedml library as x64
            set(CSHARP_EXTRA_ARGS -platform:x64 )
        endif()
    endif()

endif(WITH_CSHARP)


###############################################################################
#
# Enable support for testing ... can be invoked by running ctest
# or make test
#

if (WITH_CHECK)

    # we do use tests, that require 2.8.4
    cmake_minimum_required(VERSION 2.8.4)
    enable_testing()

endif(WITH_CHECK)

###############################################################################
#
# Need some variables set up, such as the name for the libSEDML
# library and the Path and file separator characters. The
# MISC_PREFIX variable will cause libsedml bindings, examples and
# documentation to be installed in PREFIX/${MISC_PREFIX}.
#

if (APPLE)
    set(CMAKE_MACOSX_RPATH ON)
endif (APPLE)

set( MISC_PREFIX )

if(UNIX OR CYGWIN)
    set(PATH_SEP "/")
    set(FILE_SEP ":")
    set( MISC_PREFIX "share/libsedml/" )
    set(LIBSEDML_LIBRARY sedml)
else()
    set( MISC_PREFIX "" )
    set(PATH_SEP "\\")
    set(FILE_SEP ";")
    if(MINGW)
        set(LIBSEDML_LIBRARY sedml)
    else()
        set(LIBSEDML_LIBRARY libsedml)
    endif()
endif()

# On some Linux  (64bit) systems (64bit) the libraries should be installed into lib64 rather
# than lib. It will default to 'lib' but can be overwritten.

set(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Full path to the library output directory")
mark_as_advanced(CMAKE_INSTALL_LIBDIR)


###############################################################################
#
# Set up remaining variables, add option for universal binaries
#

set(USING_INTEL)
if (WIN32 AND CMAKE_C_COMPILER AND ${CMAKE_C_COMPILER} MATCHES ".*icl.*$")
    message(STATUS "Detected Intel Compiler")
    set(USING_INTEL TRUE)
endif ()

set(BUILD_DEFINITIONS)

if(UNIX)
    if(APPLE)

        # on osx starting with xcode 4.3 the system root is in
        # the app bundle, however cmake (up to 2.8.8) does not seem
        # to update the path, so lets try it here
        if (CMAKE_OSX_SYSROOT AND NOT EXISTS ${CMAKE_OSX_SYSROOT})
            if (EXISTS "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/${CMAKE_OSX_SYSROOT}")
                set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/${CMAKE_OSX_SYSROOT}" CACHE STRING "The SDK root to be used" FORCE)
            endif()
        endif()
        add_definitions(-DMACOSX)
        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DMACOSX")

        # Since we are encountering errors with the use of libc++ on OSX
        # this option allows to override which stdlib to use
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
            option(CLANG_USE_STDLIB "Use libstdc++ rather than libc++" OFF)
            if (CLANG_USE_STDLIB)
                SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++" )
            endif()
        endif()
        
        # On OSX it is common to build universal binaries to support multiple
        # processor architectures. The default behavior is not to build
        # multiple architectures, as most users might not need that.
        option(ENABLE_UNIVERSAL "Create universal binaries on Mac OS X." OFF)

        set(CMAKE_OSX_ARCHITECTURES "${CMAKE_OSX_ARCHITECTURES}" CACHE STRING
           "A semicolon-separated list of build architectures to be used.")
        if(ENABLE_UNIVERSAL)
            # if universal binaries are requested and none defined so far
            # overwrite them with all three common architectures. If the user
            # specified their own list of architectures do not touch!
            if(CMAKE_OSX_ARCHITECTURES STREQUAL "")
                STRING(REGEX REPLACE "^.*MacOSX([0-9]*\\.[0-9]*)\\.sdk$" "\\1"
                       OSX_SDK_VERSION "${CMAKE_OSX_SYSROOT}")
                if(OSX_SDK_VERSION  VERSION_EQUAL "10.7" OR OSX_SDK_VERSION  VERSION_EQUAL "10.8")
                    # OSX Lion no longer supports ppc architecture
                    set(CMAKE_OSX_ARCHITECTURES "i386;x86_64" CACHE STRING
                    "A semicolon-separated list of build architectures to be used." FORCE)
                else()
                    set(CMAKE_OSX_ARCHITECTURES "i386;ppc;x86_64" CACHE STRING
                    "A semicolon-separated list of build architectures to be used." FORCE)
                endif()
            endif()
        endif(ENABLE_UNIVERSAL)

    else(APPLE)

        add_definitions(-DLINUX)

        if(NOT CYGWIN)
            # on cygwin all code is position independent so -fPIC is not needed
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing -fPIC")
            set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing -fPIC")
        endif()

        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLINUX")

    endif(APPLE)

    add_definitions( -DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\")
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\"")

else(UNIX)

    add_definitions(-DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\")
    
    add_definitions(-DWIN32)
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DWIN32")

    if(WITH_LIBLX)
        if (LIBLX_STATIC)
            add_definitions(-DLIBLX_STATIC -DLIBLAX_STATIC)
            set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLIBLX_STATIC -DLIBLAX_STATIC")
        else()
            add_definitions(-DLIBLX_EXPORTS -DLIBLAX_EXPORTS)
            set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLIBLX_EXPORTS -DLIBLAX_EXPORTS")
        endif()
    endif()
    if(WITH_LIBSBML)
        if (LIBSBML_STATIC)
            add_definitions(-DLIBSBML_STATIC -DLIBLAX_STATIC)
            set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLIBSBML_STATIC -DLIBLAX_STATIC")
        else()
            add_definitions(-DLIBSBML_EXPORTS -DLIBLAX_EXPORTS)
            set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLIBSBML_EXPORTS -DLIBLAX_EXPORTS")
        endif()
    endif()
  
    if(MSVC OR USING_INTEL)
      add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE)
      set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -D_CRT_SECURE_NO_WARNINGS")
      option(WITH_STATIC_RUNTIME "Compile using the static MSVC Runtime." OFF)
      if(WITH_STATIC_RUNTIME)
          foreach(flag_var
              CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
              CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
              CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
              CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
      
              if(${flag_var} MATCHES "/MD")
                  string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
              endif(${flag_var} MATCHES "/MD")
          endforeach(flag_var)
      add_definitions( -D_MT)
      endif(WITH_STATIC_RUNTIME)
        # on VS enable multiprocessor build
        SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

      # CMake no longer creates PDB files for static libraries after 2.8.11
      # so we store debug information in the object files instead
      if (${CMAKE_VERSION} VERSION_GREATER "2.8.11")
        foreach(flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
      
            if(${flag_var} MATCHES "/Zi")
              STRING(REPLACE "/Zi"  "/Z7" "${flag_var}" "${${flag_var}}")
            endif(${flag_var} MATCHES "/Zi")
      
        endforeach(flag_var)      
      endif()
        
      file(GLOB WIN32_BINARIES ${LIBSEDML_DEPENDENCY_DIR}/bin/*.dll)
      INSTALL(FILES ${WIN32_BINARIES} DESTINATION bin)
      file(GLOB WIN32_DEPENDENCIES ${LIBSEDML_DEPENDENCY_DIR}/lib/*.lib)
      install(FILES ${WIN32_DEPENDENCIES} DESTINATION lib)
      if(WITH_STATIC_RUNTIME)
        if (EXTRA_LIBS STREQUAL "")
            set(EXTRA_LIBS "WS2_32.lib" CACHE STRING "List of additional libraries to link against." FORCE)
        endif()
      endif()
    elseif(CYGWIN)
        add_definitions(-DCYGWIN)
        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DCYGWIN")
    endif(MSVC OR USING_INTEL)

endif(UNIX)


###############################################################################
#
# Disable in-source build
#

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}" )
    message(FATAL_ERROR "In-source builds of libSEDML are disabled. Please create a separate build directory.")
endif()


if (LIBSEDML_PACKAGE_INCLUDES)
  list(REMOVE_DUPLICATES LIBSEDML_PACKAGE_INCLUDES)
endif()

###############################################################################
#
# Build the actual libSEDML library
#

###############################################################################
#
# Initialize LIBSEDML sources
#
set(LIBSEDML_SOURCES)

###############################################################################
#
# utility macro for copying files only if they have changed, for this it is
# assumed that the source file is always created. Then the macro is called.
# If the target file will only be overwritten if it does not yet exist, or
# its content is different. At the end the source file will be removed.
#
macro(copy_if_different_and_remove source target)
# message(
# "
# copy_if_different_and_remove called with:
#   source = ${source}
#   target = ${target}
# "
# )
file(READ ${source} CONTENT)

if (EXISTS ${target})
  # message("target exists")
  file(READ ${target} CURRENT_CONTENT)
  string(COMPARE EQUAL ${CURRENT_CONTENT} ${CONTENT} IS_SAME)
  if (NOT ${IS_SAME})
    #message("content is different")
    file(WRITE ${target} ${CONTENT})
  endif()
else()
  #message("target does not exist")
  file(WRITE ${target} ${CONTENT})
endif()

file(REMOVE ${source})

endmacro(copy_if_different_and_remove)


###############################################################################
#
# create libsedml-config-common.h
#
include(CheckIncludeFiles)
check_include_files (check.h HAVE_CHECK_H)
check_include_files (expat.h HAVE_EXPAT_H)
check_include_files (errno.h HAVE_ERRNO_H)
check_include_files (ieeefp.h HAVE_IEEEFP_H)
check_include_files (math.h HAVE_MATH_H)
check_include_files (sys/types.h HAVE_SYS_TYPES_H)
check_include_files (float.h STDC_HEADERS)
check_include_files (stdarg.h STDC_HEADERS)
check_include_files (stdlib.h STDC_HEADERS)
check_include_files (string.h STDC_HEADERS)

set(WORDS_BIGENDIAN)
if (UNIX)
  include (TestBigEndian)
  test_big_endian(WORDS_BIGENDIAN)
else()
  # test_big_endian seems to fail with nmake (VS 2010) on windows
  # however, windows is always little endian, so catch this here
  set(WORDS_BIGENDIAN FALSE)
endif()

# for whatever reason some of the values are not correctly picked up
# so we encode these values here
if (MSVC)
  set(HAVE_ERRNO_H TRUE)
  set(HAVE_IEEEFP_H TRUE)
  set(STDC_HEADERS TRUE)
  set(HAVE_MATH_H TRUE)
  set(HAVE_SYS_TYPES_H TRUE)
endif()

##############################################################################
#
# create library
# 
add_subdirectory(src)


###############################################################################
#
# Build examples if specified
#

if(WITH_EXAMPLES)

    # code that builds the examples
    add_subdirectory(examples)

endif(WITH_EXAMPLES)
#
#
#if(WITH_DOXYGEN)
#    add_subdirectory(docs)
#endif()


###############################################################################
#
# Install documentation
#

set(DOCUMENTATION_FILES
        LICENSE.txt
        README.md
        VERSION.txt
)

install(FILES ${DOCUMENTATION_FILES} DESTINATION ${MISC_PREFIX}.)


###############################################################################
#
# Print Summary
#

if (NOT HOSTNAME)
 site_name(HOSTNAME)
endif()

message(STATUS "
----------------------------------------------------------------------
libSEDML version ${PACKAGE_VERSION}
----------------------------------------------------------------------

   More information and the latest version are available online at

   Please report problems using the issue tracker at

   To contact the developers directly, email sbml-team@caltech.edu

   Configured on host '${HOSTNAME}'
     host type                     = ${CMAKE_SYSTEM_NAME}
     host operating system         = ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}
     host CPU architecture         = ${CMAKE_SYSTEM_PROCESSOR}

   General build flags:
     CC                            = ${CMAKE_C_COMPILER}
     CXX                           = ${CMAKE_CXX_COMPILER}
     CPPFLAGS                      = ${BUILD_DEFINITIONS}
     CFLAGS                        = ${CMAKE_C_FLAGS}
     CXXFLAGS                      = ${CMAKE_CXX_FLAGS}
     LDFLAGS                       = ${CMAKE_EXE_LINKER_FLAGS}

   ${LINKED_NAME} library configuration:
     ${LINKED_NAME} library        = ${LINKED_LIBRARY}
     ${LINKED_NAME} include        = -I${LINKED_INCLUDE_DIR}
     EXTRA INCLUDES                = -I${EXTRA_INCLUDE_DIRS}

   NUML library configuration:
     NUML library                  = ${LIBNUML_LIBRARY}
     NUML include                  = -I${LIBNUML_INCLUDE_DIR}

  Other libSEDML configuration settings:
     Installation $prefix          = ${CMAKE_INSTALL_PREFIX}")


if(UNIX)
    if(APPLE)
        message(STATUS "  Value of $DYLD_LIBRARY_PATH   = $ENV{DYLD_LIBRARY_PATH}")
    else()
        message(STATUS "  Value of $LD_LIBRARY_PATH     = $ENV{LD_LIBRARY_PATH}")
    endif()
endif()

if(WITH_SWIG)
    message(STATUS "  Using SWIG                    = ${SWIG_EXECUTABLE}")
endif()


if(WITH_CSHARP)
    message(STATUS "  Using C#                      = ${CSHARP_COMPILER}")
endif()

if(WITH_JAVA)
    message(STATUS "  Using Java                    = ${Java_JAVA_EXECUTABLE}")
endif()

if(WITH_PYTHON)
    message(STATUS "  Using Python                  = ${PYTHON_EXECUTABLE}")
endif()

if(WITH_PERL)
    message(STATUS "  Using Perl                    = ${PERL_EXECUTABLE}")
endif()

if(WITH_RUBY)
    message(STATUS "  Using Ruby                    = ${RUBY_EXECUTABLE}")
endif()

if(WITH_CHECK)
    message(STATUS "  Using libcheck                = ${LIBCHECK_LIBRARY}")
endif()
message(STATUS "
")

if(WITH_CPP_NAMESPACE)
    message(STATUS "  Using C++ namespace for libSEDML (libsedml) = yes")
else()
    message(STATUS "  Using C++ namespace for libSEDML (libsedml) = no")
endif()

if(APPLE)
    if(CMAKE_OSX_ARCHITECTURES STREQUAL "")
        message(STATUS "  Building universal binaries                 = no (using native arch)")
    else()
        list(REMOVE_DUPLICATES CMAKE_OSX_ARCHITECTURES)
        list(REMOVE_ITEM CMAKE_OSX_ARCHITECTURES "")
        list(SORT CMAKE_OSX_ARCHITECTURES)
        list(LENGTH CMAKE_OSX_ARCHITECTURES NUM_ARCHS)
        if(NUMARCHS EQUAL 1)
            message(STATUS "  Building universal binaries                 = no (using ${CMAKE_OSX_ARCHITECTURES})")
        else()
            message(STATUS "  Building universal binaries                 = yes (using ${CMAKE_OSX_ARCHITECTURES})")
        endif()
    endif()
endif()


message(STATUS "
----------------------------------------------------------------------")



## To compile a test program simply comment out the lines below ...
#
#OPTION(WITH_TEST_PROGRAM " COMPILE SMALL TEST PROGRAM " ON)
#
#if(WITH_TEST_PROGRAM)
#
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#
#add_executable(libsedml_test test.cpp)
#target_link_libraries(libsedml_test ${LIBSEDML_LIBRARY}-static)
#
#endif()
#
