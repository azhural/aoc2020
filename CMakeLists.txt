cmake_minimum_required(VERSION 3.10)
project(aoc2020)
add_compile_options(-std=c++14)

include_directories(
  include
)

add_library(${PROJECT_NAME}_lib
  src/input/reader.cpp
)

file(GLOB PUZZLE_SOURCES src/puzzle/*.cpp)
foreach(source_file ${PUZZLE_SOURCES})
  get_filename_component(filename ${source_file} NAME_WE)
  add_executable(${filename} ${source_file})
  target_link_libraries(${filename} ${PROJECT_NAME}_lib)
endforeach(source_file ${PUZZLE_SOURCES})
