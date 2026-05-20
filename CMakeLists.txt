cmake_minimum_required(VERSION 3.16)

project(cppGame)

add_subdirectory(thirdparty/raylib-5.0)

add_executable(cppGame src/main.cpp)

target_link_libraries(cppGame PRIVATE raylib)

