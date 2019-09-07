cmake_minimum_required(VERSION 3.7)

project(SDL2Test)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.hpp)

add_executable(SDL2Test ${SOURCE_FILES})
target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

