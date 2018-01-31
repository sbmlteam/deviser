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
mkdir deviser
cd deviser
mkdir samples
mkdir generator


cp ${SOURCE_DIR}/samples/*.xml ${DIST_DIR}/deviser/samples


cd $DIRECTORY
