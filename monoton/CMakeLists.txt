cmake_minimum_required(VERSION 3.3)
project(monoton)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES monoton.c)
add_executable(monoton ${SOURCE_FILES})