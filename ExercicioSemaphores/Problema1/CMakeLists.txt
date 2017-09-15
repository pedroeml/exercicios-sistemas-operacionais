cmake_minimum_required(VERSION 3.7)
project(Problema1)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(Problema1 ${SOURCE_FILES})

target_link_libraries(Problema1 pthread)
