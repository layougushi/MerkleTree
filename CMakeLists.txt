cmake_minimum_required(VERSION 3.9)
project(MerkleTree)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

add_executable(MerkleTree
        main.cpp
        node.cpp
        node.h
        tree.cpp
        tree.h
        picosha2.h)
