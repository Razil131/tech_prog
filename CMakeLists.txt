cmake_minimum_required(VERSION 3.10.0)
project(lab4 VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILE
    ./src/Necklace.cpp
    ./src/StoneFactory.cpp
    )

include_directories(${CMAKE_SOURCE_DIR}/include)

# add_executable(lab4 ${SOURCE_FILE})
add_library(lab4 SHARED ${SOURCE_FILE})

set_target_properties(lab4 PROPERTIES PREFIX "")

