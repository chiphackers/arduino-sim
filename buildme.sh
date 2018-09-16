#!/bin/bash

DIR=`dirname "${BASH_SOURCE[0]}"`

mkdir $DIR/obj
cp $DIR/examples/* $DIR/obj/ -rf

echo "created object folder"

