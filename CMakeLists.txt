cmake_minimum_required(VERSION 3.16)

project(cppGame)

add_subdirectory(thirdparty/raylib-5.0)
add_subdirectory(thirdparty/imgui-docking)
add_subdirectory(thirdparty/rlImGui)

file(GLOB_RECURSE MY_SOURCES
CONFIGURE_DEPENDS
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(
cppGame
${MY_SOURCES}
)

target_link_libraries(
cppGame
PRIVATE
raylib
imgui
rlimgui
)


