cmake_minimum_required(VERSION 3.19)
project(CppAlgorithm)

set(CMAKE_CXX_STANDARD 14)

# boost library
set(BOOST_VERSION 1.76.0)
find_package(Boost ${BOOST_VERSION} COMPONENTS system filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

#set(Boost_include_dir /opt/homebrew/Cellar/boost/${BOOST_VERSION}/include)
#set(Boost_link_dir /opt/homebrew/Cellar/boost/${BOOST_VERSION}/lib)
#include_directories(${Boost_include_dir})


include_directories(include)
include_directories(include/data)
include_directories(include/timemeasure)

add_executable(
        CppAlgorithm
        #        threadsafe_stack2.cpp
        include/BasicSTL.h
        include/data/DataStructure.h
        include/timemeasure/TimeMeasure.h
        preface/Synchronize.cpp
        preface/ShareMutex.cpp
        preface/Deadlock.cpp
        preface/threadsafe_query_table.cpp
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
        frame/BSTemplate.h frame/DFSTemplate.h frame/BFSTemplate.h frame/SWTemplate.h frame/MSTemplate.h questions/Agl_03.cpp questions/Agl_04.cpp questions/Agl_05.cpp questions/Agl_06.cpp questions/Agl_07.cpp)

#target_link_libraries(${PROJECT_NAME} ${Boost_link_dir})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})