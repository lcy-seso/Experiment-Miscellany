cmake_minimum_required(VERSION 3.0)

project(isl-examples CXX C)

set(ISL_INSTALL_DIR
    "${CMAKE_BINARY_DIR}/../../build/third_party/isl/src/extern_isl-install/")

message(STATUS ${ISL_INSTALL_DIR})

include_directories(${ISL_INSTALL_DIR}/include)
link_directories(${ISL_INSTALL_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(set1 set1.cpp)
target_link_libraries(set1 -lisl)

add_executable(aff1 aff1.cpp)
target_link_libraries(aff1 -lisl)

add_executable(map1 map1.cpp)
target_link_libraries(map1 -lisl)
