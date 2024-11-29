cmake_minimum_required(VERSION 3.27)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp
        task1.h
        task1.cpp
        task2.h
        task2.cpp
        task3.h
        task3.cpp)

target_compile_options(Project PRIVATE -fsanitize=address)
target_link_options(Project PRIVATE -fsanitize=address)