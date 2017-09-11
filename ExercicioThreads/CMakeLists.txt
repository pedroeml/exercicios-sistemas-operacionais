cmake_minimum_required(VERSION 3.7)
project(ExercicioThreads)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(ExercicioThreads ${SOURCE_FILES})

target_link_libraries(ExercicioThreads pthread)
