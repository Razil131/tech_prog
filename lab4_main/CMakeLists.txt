cmake_minimum_required(VERSION 3.10.0)
project(lab4_main VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lab4_main main.cpp)

target_include_directories(lab4_main PRIVATE
    ../include
    ./include
)

target_link_libraries(lab4_main
    ${CMAKE_CURRENT_SOURCE_DIR}/build/liblab4.dll.a
)