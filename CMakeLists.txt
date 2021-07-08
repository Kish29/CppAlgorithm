cmake_minimum_required(VERSION 3.19)
project(CppAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/data)
include_directories(include/timemeasure)

add_executable(
        CppAlgorithm
        #        threadsafe_stack2.cpp
        include/BasicSTL.h
        preface/Synchronize.cpp
        preface/Deadlock.cpp
        include/data/DataStructure.h
        include/timemeasure/TimeMeasure.h
        preface/threadsafe_stack.cpp
        preface/STLContainerBasic.cpp
        preface/STLSmartPointer.cpp
        preface/Cpp11Lambda.cpp
        preface/CppException.cpp
        preface/Fib.cpp
        preface/FullPermutation.cpp
        preface/CoinsDP.cpp
        preface/NQueens.cpp
        preface/BFSTemplate.cpp
        preface/SharePointer3.cpp
        preface/WeakPointer1.cpp
        preface/CppConcurrency.cpp
        preface/PointerType.cpp
        questions/Agl_01.cpp
        questions/Agl_02.cpp
)