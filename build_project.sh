#!/bin/bash

# Set the project directory
PROJECT_DIR=$(pwd)

echo "path of pwd" $PROJECT_DIR

# Create a build directory
BUILD_DIR="$PROJECT_DIR/build"
mkdir -p $BUILD_DIR

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to generate build files
cmake ..

# Compile the project
make

