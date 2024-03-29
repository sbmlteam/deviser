find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(PythonInterp)

# specify that the same python library should be found 
# as the one the selected interpreter uses
set (Python_ADDITIONAL_VERSIONS ${PYTHON_VERSION_STRING})
find_package(PythonLibs)


####################################################################
#
# determine local dependencies, so as to re-swig if one of them changed
# 

file(GLOB SWIG_DEPENDENCIES 
  ${CMAKE_CURRENT_SOURCE_DIR}/*.i 
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h 
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.i
  ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.h
  )

#
# Remove SWIG wrappers if requested
#
if (LIBSBML_REMOVE_WRAPPERS)
  foreach(file 
    ${CMAKE_CURRENT_BINARY_DIR}/libsbml_wrap.cpp
  )
    if (EXISTS ${file})
      FILE(REMOVE ${file})
    endif()
  endforeach()
endif(LIBSBML_REMOVE_WRAPPERS)

if(WITH_LIBSBML)
    <verbatim>
    set(SWIG_EXTRA_FLAGS -DSWIGEXPORT 
    -DLIBSBML_CPP_NAMESPACE_BEGIN -DLIBSBML_CPP_NAMESPACE_END -DLIBSBML_CPP_NAMESPACE_QUALIFIER -DLIBSBML_CPP_NAMESPACE_USE
    -DLIBNUML_CPP_NAMESPACE_BEGIN -DLIBNUML_CPP_NAMESPACE_END -DLIBNUML_CPP_NAMESPACE_QUALIFIER -DLIBNUML_CPP_NAMESPACE_USE
    )
    </verbatim>
endif()
if(WITH_LIBLX)
    <verbatim>
    set(SWIG_EXTRA_FLAGS -DSWIGEXPORT 
    -DLIBLX_CPP_NAMESPACE_BEGIN -DLIBLX_CPP_NAMESPACE_END -DLIBLX_CPP_NAMESPACE_QUALIFIER -DLIBLX_CPP_NAMESPACE_USE
    -DLIBNUML_CPP_NAMESPACE_BEGIN -DLIBNUML_CPP_NAMESPACE_END -DLIBNUML_CPP_NAMESPACE_QUALIFIER -DLIBNUML_CPP_NAMESPACE_USE
    )
    </verbatim>
endif()

if(NOT UNIX)
  set(SWIG_EXTRA_FLAGS ${SWIG_EXTRA_FLAGS} -DSWIGWIN -DSWIG_CSHARP_NO_WSTRING_HELPER )
endif()


ADD_CUSTOM_COMMAND(  
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libsbml_wrap.cpp
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS  -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
      -I${CMAKE_CURRENT_SOURCE_DIR}/../../
      -I${CMAKE_CURRENT_BINARY_DIR}/../../
      -I${CMAKE_CURRENT_SOURCE_DIR}/../../sbml
      -I${CMAKE_CURRENT_SOURCE_DIR}
<library_dependencies/>
<verbatim>
         -I${LINKED_INCLUDE_DIR}/
</verbatim>
      -c++
      -python    
      ${SWIG_EXTRA_FLAGS}     
      ${SWIG_EXTRA_ARGS}     
      -o ${CMAKE_CURRENT_BINARY_DIR}/libsbml_wrap.cpp 
      ${CMAKE_CURRENT_SOURCE_DIR}/libsbml.i
      
      
  COMMAND "${CMAKE_COMMAND}"
  ARGS  -DCUR_BIN_DIRECTORY=\"${CMAKE_CURRENT_BINARY_DIR}\"
        -DVERSION=\"${LIBSBML_VERSION}\"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/add_version.cmake"
        
      
  DEPENDS local.i local.cpp local-contrib.i
  COMMENT "Swig Python source") 

add_custom_target(binding_python_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libsbml_wrap.cpp)
  
####################################################################
#
# Build native library
#

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../swig)
<verbatim>
include_directories(${LINKED_INCLUDE_DIR})
</verbatim>
<include_library_dependencies/>
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/../../)
add_definitions(-DLIBSBML_STATIC)
include_directories(${PYTHON_INCLUDE_DIRS})
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

if (MSVC)
  # the build fails when compiled with packages as the object file is too 
  # big adding the big flag makes it work!
  add_definitions(/bigobj)
endif(MSVC)

add_library(binding_python_lib SHARED libsbml_wrap.cpp)
add_dependencies( binding_python_lib binding_python_swig) 

set_target_properties (binding_python_lib PROPERTIES OUTPUT_NAME "_libsbml")
if (UNIX)
  set_target_properties (binding_python_lib PROPERTIES PREFIX "")
  set_target_properties (binding_python_lib PROPERTIES SUFFIX ".so")
else()    
  if (CYGWIN)
    set_target_properties (binding_python_lib PROPERTIES PREFIX "")
    set_target_properties (binding_python_lib PROPERTIES SUFFIX ".dll")
  else()
    set_target_properties (binding_python_lib PROPERTIES SUFFIX ".pyd")  
  endif()
endif()


if(APPLE OR UNIX)
  option (PYTHON_USE_DYNAMIC_LOOKUP
  "Do not actually link against the python library, instead use the undefined lookup mechanism, that ." OFF)
  mark_as_advanced(PYTHON_USE_DYNAMIC_LOOKUP)
endif(APPLE OR UNIX)

if (PYTHON_USE_DYNAMIC_LOOKUP)
  if (APPLE)
    set_target_properties (binding_python_lib PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
  endif()
  target_link_libraries(binding_python_lib ${LIBSBML_LIBRARY}-static)
else()
  target_link_libraries(binding_python_lib ${LIBSBML_LIBRARY}-static ${PYTHON_LIBRARIES})
endif()

# 
# Determine the python installation directory
#
set(PYTHON_PACKAGE_INSTALL_DIR)
if (UNIX OR CYGWIN) 
  execute_process(COMMAND "${PYTHON_EXECUTABLE}" -c "import sys;import platform; sys.stdout.write(platform.python_version()[:3])"
    OUTPUT_VARIABLE PYTHON_VERSION)
  set(PYTHON_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/python${PYTHON_VERSION}/site-packages)
else()
  set(PYTHON_PACKAGE_INSTALL_DIR ${MISC_PREFIX}bindings/python)
endif()

INSTALL(TARGETS binding_python_lib DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml )

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/libsbml.pth" "libsbml\n")
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbml.pth  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbml.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml )
