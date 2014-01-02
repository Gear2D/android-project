project(logo)
cmake_minimum_required(VERSION 2.8)

find_package(Gear2D REQUIRED)

set(CMAKE_BUILD_TYPE "Debug")

include_directories(${Gear2D_INCLUDE_DIR})

add_definitions(-std=c++11 -DLOGTRACE)

g2dcomponent(FAMILY logo TYPE logo SOURCES logo.cc)