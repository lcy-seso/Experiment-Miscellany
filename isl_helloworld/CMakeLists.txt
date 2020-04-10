cmake_minimum_required(VERSION 3.0)

project(isl-example CXX C)

set(TARGET_NAME isl-example)

include_directories(${ISL_INSTALL_DIR}/include)
link_directories(${ISL_INSTALL_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${TARGET_NAME} main.c)
target_link_libraries(${TARGET_NAME} -lisl)
