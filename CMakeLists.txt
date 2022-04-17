cmake_minimum_required(VERSION 3.23)
project(grocery_list)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(sfml)
include_directories("sfml/include")

add_executable(grocery_list src/main.cpp src/Item.cpp src/Item.h src/List.cpp src/List.h)

target_link_libraries(grocery_list sfml-graphics sfml-system sfml-window)

# copy dll files into debug directory
add_custom_command(TARGET grocery_list POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_BINARY_DIR}/sfml/lib"
        $<TARGET_FILE_DIR:grocery_list>)