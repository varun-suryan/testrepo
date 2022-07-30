cmake_minimum_required(VERSION 3.16.3)

project(hahaha)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(square)

target_link_libraries(${PROJECT_NAME} code)
