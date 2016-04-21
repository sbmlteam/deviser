###############################################################################
#
# Description       : CMake build script for libSBML
# 
###############################################################################


include(CheckLibraryExists)
check_library_exists(m sqrt "" HAVE_LIBM)

# generate configuration for this system
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/common/libsbml-config-common.h.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsbml-config-common.h"
  )

# Replace: @PACKAGE_VERSION@ and @LIBSBML_VERSION_NUMERIC@
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsbml-version.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsbml-version.h"
  )

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsbml-namespace.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsbml-namespace.h"
  )
  

###############################################################################
#
# mark header files for installation
#
foreach(dir annotation common compress conversion extension math units util validator xml  )

  file(GLOB header_files "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.h")
  install(FILES ${header_files} DESTINATION include/sbml/${dir})

endforeach(dir)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${files} DESTINATION include/sbml)

# install generated headers
install(FILES 
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsbml-version.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsbml-config-common.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsbml-namespace.h"
        DESTINATION include/sbml/common)

###############################################################################
#
# specify include directories
#
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
<verbatim>
include_directories(BEFORE ${LIBSBML_INCLUDE_DIR})
</verbatim>
include_directories(BEFORE ${LIBNUML_INCLUDE_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/..)

if (EXTRA_DEFS)
add_definitions(${EXTRA_DEFS})
endif()

###############################################################################
#
# Find all sources
#

foreach (directory common sbml )

  set(dir ${directory})

  if ("${directory}" STREQUAL "sbml")
    set(dir ".")
  endif()


  file(GLOB temp
      ${dir}/*.cpp
      ${dir}/*.c
      ${dir}/*.h)

  # create source group for IDEs
  source_group(${directory} FILES ${temp})

  # add to libsbml sources
  set(LIBSBML_SOURCES ${LIBSBML_SOURCES} ${temp})

endforeach()

###############################################################################
#
# this is a directory level operation!
#
if (MSVC)
if (WITH_STATIC_RUNTIME)
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
endif(MSVC)

###############################################################################
#
# Build library
#

if (NOT LIBSBML_SKIP_SHARED_LIBRARY)

add_library (${LIBSBML_LIBRARY} SHARED ${LIBSBML_SOURCES} )

if (LIBSBML_SHARED_VERSION)
  set_target_properties(${LIBSBML_LIBRARY} PROPERTIES COMPILE_DEFINITIONS "LIBSBML_EXPORTS=1")
  set_target_properties(${LIBSBML_LIBRARY} PROPERTIES
                      SOVERSION ${LIBSBML_VERSION_MAJOR}
                      VERSION ${LIBSBML_VERSION_MAJOR}.${LIBSBML_VERSION_MINOR}.${LIBSBML_VERSION_PATCH})
endif()

<sbml>
target_link_libraries(${LIBREPLACE_LIBRARY} ${LIBSBML_LIBRARY} ${LIBNUML_LIBRARY} ${EXTRA_LIBS})
</sbml>

INSTALL(TARGETS ${LIBSBML_LIBRARY}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

endif()

add_library (${LIBSBML_LIBRARY}-static STATIC ${LIBSBML_SOURCES} )
if (WIN32 AND NOT CYGWIN)
  # don't decorate static library 
  set_target_properties(${LIBSBML_LIBRARY}-static PROPERTIES COMPILE_DEFINITIONS "LIBSBML_STATIC=1")
endif(WIN32 AND NOT CYGWIN)

<sbml>
target_link_libraries(${LIBREPLACE_LIBRARY}-static ${LIBSBML_LIBRARY} ${LIBNUML_LIBRARY} ${EXTRA_LIBS})
</sbml>

INSTALL(TARGETS ${LIBSBML_LIBRARY}-static
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
