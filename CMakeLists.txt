cmake_minimum_required(VERSION 3.15)
project(sdl2_template)

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

add_executable(
        sdl2_template
        main.cpp
        Classes/Window.cpp
        Classes/Window.h
)

target_link_libraries(
        sdl2_template
        ${SDL2_LIBRARY}
        -lmingw32
        -lSDL2main
        -lSDL2
        -lSDL2_image
)