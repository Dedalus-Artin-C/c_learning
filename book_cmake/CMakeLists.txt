cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#project name
PROJECT(first_cmake)

add_library(
  newlib STATIC src/filr2_coordin.cpp  
)#STATIC

add_library(newlib::polar ALIAS newlib)

target_include_directories(newlib
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(first_cmake
    src/file1_coordin.cpp
)


target_link_libraries(first_cmake newlib)#PRIVATE



