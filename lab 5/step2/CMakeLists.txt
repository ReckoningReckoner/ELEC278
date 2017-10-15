cmake_minimum_required(VERSION 3.6)
project(step2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    DLL.h
    hash.c)

add_executable(step2 ${SOURCE_FILES})