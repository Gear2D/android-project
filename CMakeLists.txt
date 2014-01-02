add_subdirectory(jni)
cmake_minimum_required(VERSION 2.8)

add_custom_target(android
                  COMMAND cd jni && ndk-build -j9
                  COMMAND ant debug
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})