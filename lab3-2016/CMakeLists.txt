cmake_minimum_required(VERSION 3.6)
project(lab3_2016)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bst.c
    bst.h
    print_t.h
    main.c)

add_executable(lab3_2016 ${SOURCE_FILES})
