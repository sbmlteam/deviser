#!/bin/bash

DIRECTORY=$(cd `dirname $0` && pwd)

SOURCE_DIR=$DIRECTORY/../../../deviser

DIST_DIR=$DIRECTORY/archive

if [ ! -d $DIST_DIR ] 
then
  mkdir $DIST_DIR
else 
  # remove old files from it
  rm -r $DIST_DIR/*
fi

cd $DIST_DIR
# create directory structure and copy files
mkdir deviser
cd deviser
cp ${SOURCE_DIR}/*.txt ${DIST_DIR}/deviser
cp ${SOURCE_DIR}/*.md ${DIST_DIR}/deviser
cp ${SOURCE_DIR}/*.html ${DIST_DIR}/deviser



mkdir docs
cp ${SOURCE_DIR}/docs/DEVISER_MANUAL.pdf ${DIST_DIR}/deviser/docs

mkdir samples
cp ${SOURCE_DIR}/samples/*.xml ${DIST_DIR}/deviser/samples
cp ${SOURCE_DIR}/samples/*.txt ${DIST_DIR}/deviser/samples

mkdir generator
cp ${SOURCE_DIR}/generator/*.py ${DIST_DIR}/deviser/generator

cd generator
mkdir base_files
cp ${SOURCE_DIR}/generator/base_files/*.py ${DIST_DIR}/deviser/generator/base_files

mkdir bindings_files
cp ${SOURCE_DIR}/generator/bindings_files/*.py ${DIST_DIR}/deviser/generator/bindings_files

cd bindings_files
mkdir templates
cd templates
mkdir csharp
cp ${SOURCE_DIR}/generator/bindings_files/templates/csharp/*.* ${DIST_DIR}/deviser/generator/bindings_files/templates/csharp
mkdir swig
cp ${SOURCE_DIR}/generator/bindings_files/templates/swig/*.* ${DIST_DIR}/deviser/generator/bindings_files/templates/swig
cd ..
cd ..

mkdir cmake_files
cp ${SOURCE_DIR}/generator/cmake_files/*.py ${DIST_DIR}/deviser/generator/cmake_files

cd cmake_files
mkdir templates
cd templates
mkdir bindings
cp ${SOURCE_DIR}/generator/cmake_files/templates/bindings/*.txt ${DIST_DIR}/deviser/generator/cmake_files/templates/bindings
mkdir code
cp ${SOURCE_DIR}/generator/cmake_files/templates/code/*.txt ${DIST_DIR}/deviser/generator/cmake_files/templates/code
mkdir src
cp ${SOURCE_DIR}/generator/cmake_files/templates/src/*.txt ${DIST_DIR}/deviser/generator/cmake_files/templates/src
mkdir top-level
cp ${SOURCE_DIR}/generator/cmake_files/templates/top-level/*.txt ${DIST_DIR}/deviser/generator/cmake_files/templates/top-level
cd ..
cd ..



mkdir code_files
cp ${SOURCE_DIR}/generator/code_files/*.py ${DIST_DIR}/deviser/generator/code_files

cd code_files
mkdir cpp_functions
cp ${SOURCE_DIR}/generator/code_files/cpp_functions/*.py ${DIST_DIR}/deviser/generator/code_files/cpp_functions
mkdir templates
cp ${SOURCE_DIR}/generator/code_files/templates/*.* ${DIST_DIR}/deviser/generator/code_files/templates
cd ..

mkdir parseXML
cp ${SOURCE_DIR}/generator/parseXML/*.py ${DIST_DIR}/deviser/generator/parseXML

mkdir spec_files
cp ${SOURCE_DIR}/generator/spec_files/*.py ${DIST_DIR}/deviser/generator/spec_files
cp ${SOURCE_DIR}/generator/spec_files/*.txt ${DIST_DIR}/deviser/generator/spec_files

mkdir util
cp ${SOURCE_DIR}/generator/util/*.py ${DIST_DIR}/deviser/generator/util

cd util
mkdir templates
cp ${SOURCE_DIR}/generator/util/templates/*.md ${DIST_DIR}/deviser/generator/util/templates
cd ..

mkdir validation
cp ${SOURCE_DIR}/generator/validation/*.py ${DIST_DIR}/deviser/generator/validation

mkdir tests
cp ${SOURCE_DIR}/generator/tests/*.py ${DIST_DIR}/deviser/generator/tests

cd tests

mkdir test_cmake_code
cp ${SOURCE_DIR}/generator/tests/test_cmake_code/*.py ${DIST_DIR}/deviser/generator/tests/test_cmake_code
cd test_cmake_code
mkdir test-cmake
cp ${SOURCE_DIR}/generator/tests/test_cmake_code/test-cmake/*.cmake ${DIST_DIR}/deviser/generator/tests/test_cmake_code/test-cmake
cp ${SOURCE_DIR}/generator/tests/test_cmake_code/test-cmake/*.cxx ${DIST_DIR}/deviser/generator/tests/test_cmake_code/test-cmake
cp ${SOURCE_DIR}/generator/tests/test_cmake_code/test-cmake/*.h ${DIST_DIR}/deviser/generator/tests/test_cmake_code/test-cmake
cd test-cmake
mkdir src
cp ${SOURCE_DIR}/generator/tests/test_cmake_code/test-cmake/src/*.cmake ${DIST_DIR}/deviser/generator/tests/test_cmake_code/test-cmake/src
cd ..
cd ..

mkdir test_binding_code
cp ${SOURCE_DIR}/generator/tests/test_binding_code/*.py ${DIST_DIR}/deviser/generator/tests/test_binding_code
cd test_binding_code
mkdir test-binding
cd test-binding
mkdir csharp
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/csharp/*.i ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/csharp
mkdir java
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/java/*.i ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/java
mkdir javascript
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/javascript/*.cpp ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/javascript
mkdir perl
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/perl/*.cpp ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/perl
mkdir php
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/php/*.i ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/php
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/php/*.cpp ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/php
mkdir python
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/python/*.cpp ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/python
mkdir r
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/r/*.cpp ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/r
mkdir ruby
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/ruby/*.cpp ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/ruby
mkdir swig
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/swig/*.i ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/swig
cp ${SOURCE_DIR}/generator/tests/test_binding_code/test-binding/swig/*.h ${DIST_DIR}/deviser/generator/tests/test_binding_code/test-binding/swig
cd ..
cd ..

mkdir test_cpp_code
cp ${SOURCE_DIR}/generator/tests/test_cpp_code/*.py ${DIST_DIR}/deviser/generator/tests/test_cpp_code
cd test_cpp_code
mkdir test-code
cp ${SOURCE_DIR}/generator/tests/test_cpp_code/test-code/*.h ${DIST_DIR}/deviser/generator/tests/test_cpp_code/test-code
cp ${SOURCE_DIR}/generator/tests/test_cpp_code/test-code/*.cpp ${DIST_DIR}/deviser/generator/tests/test_cpp_code/test-code
mkdir test-extension
cp ${SOURCE_DIR}/generator/tests/test_cpp_code/test-extension/*.h ${DIST_DIR}/deviser/generator/tests/test_cpp_code/test-extension
cp ${SOURCE_DIR}/generator/tests/test_cpp_code/test-extension/*.cpp ${DIST_DIR}/deviser/generator/tests/test_cpp_code/test-extension
cd ..

mkdir test_exit_codes
cp ${SOURCE_DIR}/generator/tests/test_exit_codes/*.py ${DIST_DIR}/deviser/generator/tests/test_exit_codes

mkdir test_tex_files
cp ${SOURCE_DIR}/generator/tests/test_tex_files/*.py ${DIST_DIR}/deviser/generator/tests/test_tex_files
cd test_tex_files
mkdir test-tex
cd test-tex
mkdir groups
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/groups/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/groups
mkdir qual
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/qual/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/qual
mkdir spatial
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/spatial/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/spatial
mkdir test_att
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/test_att/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/test_att
mkdir test_lists
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/test_lists/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/test_lists
mkdir test_sidrefs
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/test_sidrefs/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/test_sidrefs
mkdir unknown_type
cp ${SOURCE_DIR}/generator/tests/test_tex_files/test-tex/unknown_type/*.tex ${DIST_DIR}/deviser/generator/tests/test_tex_files/test-tex/unknown_type
cd ..
cd ..

mkdir test_xml_files
cp ${SOURCE_DIR}/generator/tests/test_xml_files/*.cpp ${DIST_DIR}/deviser/generator/tests/test_xml_files
cp ${SOURCE_DIR}/generator/tests/test_xml_files/*.h ${DIST_DIR}/deviser/generator/tests/test_xml_files
cp ${SOURCE_DIR}/generator/tests/test_xml_files/*.xml ${DIST_DIR}/deviser/generator/tests/test_xml_files
cp ${SOURCE_DIR}/generator/tests/test_xml_files/*.txt ${DIST_DIR}/deviser/generator/tests/test_xml_files

cd $DIRECTORY

tar -czvf deviser-1.0.0-src.tar.gz  ${DIST_DIR}/deviser
