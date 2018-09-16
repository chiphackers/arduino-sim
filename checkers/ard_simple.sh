#!/bin/bash

######### Input Check ###############
if [ -z $1 ]; then
    echo "[ERROR  ]: Invalid location"
    exit 1;
fi

######### Goto Answer ###############
PROB_DIR=$1
TEST_FILE=$2
CURR_DIR="`pwd`"
BUILD_DIR="$(dirname "$0")/../"

######### Copy user code simulator ##
if [ ! -f "$BUILD_DIR/sources/src/test.cpp" ]; then
    echo "[INFO   ]: Cleaning old source"
    rm ./sources/src/test.cpp
fi

cp $2 "$BUILD_DIR/sources/src/test.cpp"
sed -i '1s;^;#include "Arduino.h"\n;' $BUILD_DIR/sources/src/test.cpp

#####################################
cd $BUILD_DIR # We just changed current directory. Make sure to come back
#####################################

######### Sanity Work ###############
if [ -f compile.log ]; then
    rm compile.log
fi

######### Compile check #############
make clean
make > compile.log 2>&1
#cat compile.log
if [ "`cat compile.log`" != "Done." ]; then
    echo "[ERROR  ]: compilation failed"
    echo "----------[LOG]------------"
    cat compile.log | sed -e "s@`pwd`@@"
    echo "----------[END]------------"
    rm compile.log
    exit 1
fi

######### Sanity Work ###############
if [ -f compile.log ]; then
    rm compile.log
fi

#####################################
cd $CURR_DIR # We came back
#####################################

######### Start Testing #############
pwd
#echo $BUILD_DIR
#echo "this is prob $PROB_DIR"
sim_out=`$BUILD_DIR/build/arduino-sim $PROB_DIR $TEST_FILE`

if [ "$sim_out" != "`cat $PROB_DIR/SOLUTION`" ]; then
    echo "[ERROR  ]: Your design is not correct"
    echo $sim_out
	exit 1
else
    echo "$sim_out"
    echo "[SUCCESS]: Your solution works"
    exit 0
fi
