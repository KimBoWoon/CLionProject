cmake_minimum_required(VERSION 3.3)
project(CrossWord)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CrossWordMain.cpp)
add_executable(CrossWord ${SOURCE_FILES})