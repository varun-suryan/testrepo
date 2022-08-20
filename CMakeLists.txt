cmake_minimum_required(VERSION 3.16.3)

project(hahaha)

add_library(SHARED my_math my_math.cpp)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(square)

add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME} code glfw my_math)
