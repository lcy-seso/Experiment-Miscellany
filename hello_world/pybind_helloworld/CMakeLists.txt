cmake_minimum_required(VERSION 3.0)

project(pybind_test CXX C)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(PYBIND_SOURCE_DIR
    ${CMAKE_BINARY_DIR}/../../../build/third_party/pybind/src/extern_pybind/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(${PYBIND_SOURCE_DIR} build)
pybind11_add_module(pybind_test src/example.cpp)
