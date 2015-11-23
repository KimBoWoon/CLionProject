cmake_minimum_required(VERSION 3.3)
project(Practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES PrimsAlgorithm.c)
add_executable(Practice ${SOURCE_FILES})