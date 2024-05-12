cmake_minimum_required(VERSION 3.1.5)
project(Assignment4)

set (SOURCES
    Assignment4.cpp
)

set (HEADERS
    vec3.h
    Pixel.h
    ImageData.h
    ReadImage.h
)

# Adding the subdirectories
add_subdirectory(fltk)
add_subdirectory(GUI)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/fltk fltk)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/GUI GUI)

add_executable(Assignment4 WIN32 Assignment4.cpp)

# Linking with FLTK library
target_link_libraries(Assignment4 PRIVATE fltk)

# Linking with GUI library
target_link_libraries(Assignment4 PRIVATE bookgui)

# So the cmd does not open together with the window
set_target_properties(Assignment4 PROPERTIES WIN32_EXECUTABLE FALSE) 

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")
