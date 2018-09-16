#!/bin/bash

DIR=`dirname "${BASH_SOURCE[0]}"`
if [ -d "$DIR/obj" ]; then
    rm $DIR/obj -rf
fi

mkdir $DIR/obj
cp $DIR/examples/* $DIR/obj/ -r

echo "created object folder"

