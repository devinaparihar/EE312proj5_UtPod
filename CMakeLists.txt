cmake_minimum_required(VERSION 3.12)
project(proj5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj5
        song.cpp
        song.h
        UtPod.cpp
        UtPod.h
        UtPod_driver.cpp)
