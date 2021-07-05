cmake_minimum_required(VERSION 3.19)
project(CppAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/data)
include_directories(include/timemeasure)

add_executable(
        CppAlgorithm
        include/BasicSTL.h
        include/data/DataStructure.h
        include/timemeasure/TimeMeasure.h
        preface/STLContainerBasic.cpp
        preface/STLIntelliPointer.cpp
        preface/Fib.cpp
        preface/FullPermutation.cpp
        preface/CoinsDP.cpp
        preface/NQueens.cpp
        preface/BFSTemplate.cpp
        questions/Agl_01.cpp
)