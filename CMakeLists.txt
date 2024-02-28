cmake_minimum_required(VERSION 3.19)
project(RInside_runner)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native")

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

# Define paths
set(R_FRAMEWORK_ROOT_DIR "/Library/Frameworks/R.framework")
set(R_VERSION "4.3-x86_64")
set(R_RESOURCES_DIR "${R_FRAMEWORK_ROOT_DIR}/Versions/${R_VERSION}/Resources")
set(R_LIBS_DIR "${R_RESOURCES_DIR}/library")

include_directories("${R_RESOURCES_DIR}/include")
include_directories("${R_LIBS_DIR}/Rcpp/include")
include_directories("${R_LIBS_DIR}/RInside/include")

add_executable(RInside_runner main.cpp)

target_link_libraries(RInside_runner "${R_LIBS_DIR}/RInside/lib/libRInside.dylib")
target_link_libraries(RInside_runner "${R_RESOURCES_DIR}/lib/LibR.dylib")
target_link_libraries(RInside_runner BLAS)