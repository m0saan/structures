cmake_minimum_required(VERSION 3.17)
project(Data__Structures)

set(CMAKE_CXX_STANDARD 20)

include_directories(non_linear_data_structures)

add_executable(Data__Structures
        non_linear_data_structures/main.cpp
        non_linear_data_structures/Edge.h
        non_linear_data_structures/Edge.cpp
        non_linear_data_structures/Node.h
        non_linear_data_structures/Node.cpp)
