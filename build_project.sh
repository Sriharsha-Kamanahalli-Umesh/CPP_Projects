#!/bin/bash

# Set the project directory
PROJECT_DIR=$(pwd)

# Create a build directory
BUILD_DIR="$PROJECT_DIR/build"

if [ -d $BUILD_DIR ] ; then
    rm -rf $BUILD_DIR
    echo "build folder found and deleted"
fi

mkdir -p $BUILD_DIR

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to generate build files
cmake ..

# Compile the project
make

