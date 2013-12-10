project(logo)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/" "${CMAKE_SOURCE_DIR}")


find_package(Gear2D REQUIRED)

include_directories(${Gear2D_INCLUDE_DIR})

add_definitions(-std=c++11)

gear2d_component(logo logo logo.cc)