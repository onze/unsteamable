cmake_minimum_required(VERSION 2.8)

project(usmb)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug)
    ADD_DEFINITIONS(-DDEBUG=1)
ENDIF(NOT CMAKE_BUILD_TYPE)
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

ADD_DEFINITIONS("-std=c++0x")

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
message("EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")

set(CMAKE_CXX_FLAGS "-Wall")
set (CMAKE_CXX_FLAGS_DEBUG "")
set (CMAKE_CXX_FLAGS_RELEASE "-O2")

file(
    GLOB_RECURSE
    source_files
    Unsteamable/*
)

include_directories(
    Unsteamable/include
    /media/a0/cpp/1210/steel/Steel/include
    /usr/include/jsoncpp
    /usr/include/ois
    /media/a0/cpp/libs/ogre/OgreMain/include
    /media/a0/cpp/libs/ogre/include
    /media/a0/cpp/libs/librocket_generic-source-1.2.1/libRocket/Include
)

link_directories(
    /media/a0/cpp/1210/steel/build/lib/${CMAKE_BUILD_TYPE}
    /media/a0/cpp/libs/ogre/lib
    /usr/lib/
    /usr/lib/x86_64-linux-gnu/
    /media/a0/cpp/libs/librocket_generic-source-1.2.1/libRocket/Build
)

add_executable(usmb ${source_files})

target_link_libraries(usmb
    steel
    OgreMain
    jsoncpp
    OIS
)