cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.hpp)

add_executable(SDL2Test ${SOURCE_FILES})
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})

