cmake_minimum_required(VERSION 3.1.5)
project(GUI)

set(GUI_HEADER Graph.h GUI.h Point.h Simple_window.h Window.h std_lib_facilities.h)
set(GUI_SOURCES Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

add_library(bookgui STATIC ${GUI_HEADER} ${GUI_SOURCES})

target_include_directories(bookgui PUBLIC ${CMAKE_SOURCE_DIR}) # Include the current directory
target_include_directories(bookgui PUBLIC ${CMAKE_SOURCE_DIR}/../fltk) # Include fltk directory

target_link_libraries(bookgui PUBLIC fltk)
target_link_libraries(bookgui PUBLIC fltk fltk_images)
