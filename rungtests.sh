#!/bin/bash

# Set the project directory
PROJECT_DIR=$(pwd)

# Create a build directory
BUILD_DIR="$PROJECT_DIR/build"

#Running test executable
echo "Running Gtests"

#"$BUILD_DIR/modules/exception/test/myexception_test"
"$BUILD_DIR/modules/gtest/gmock/test/atmappliaction"
#"$BUILD_DIR/modules/polymorphism/test/poly_test"
# "$BUILD_DIR/modules/queue/test/queue_test"
# "$BUILD_DIR/modules/SocialNetwork/test/social_network_test"
"$BUILD_DIR/modules/Sort/test/sort_test"
# "$BUILD_DIR/modules/stack/stack_with_array/test/stack_with_array_test"
# "$BUILD_DIR/modules/stack/stack_with_list/test/stack_with_list_test"
"$BUILD_DIR/modules/templates/test/template_test"


