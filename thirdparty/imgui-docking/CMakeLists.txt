cmake_minimum_required(VERSION 3.5)

add_library(imgui)

target_sources(imgui PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/imgui.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_demo.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_draw.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_tables.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_widgets.cpp"
)

target_include_directories(
imgui PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}"
)
