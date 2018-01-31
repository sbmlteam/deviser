#!/bin/bash

DIRECTORY=$(cd `dirname $0` && pwd)

SOURCE_DIR=$DIRECTORY/../../../deviser

DIST_DIR=$DIRECTORY/macbundle

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

mkdir samples
cp ${SOURCE_DIR}/samples/*.xml ${DIST_DIR}/deviser/samples

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
mkdir code_files
cp ${SOURCE_DIR}/generator/cmake_files/templates/code_files/*.txt ${DIST_DIR}/deviser/generator/cmake_files/templates/code_files
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


cd $DIRECTORY
