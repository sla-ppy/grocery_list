cmake_minimum_required(VERSION 3.23)
project(grocery_list)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses -lpanel")

add_executable(grocery_list src/main.cpp src/Item.cpp src/Item.h src/List.cpp src/List.h)
target_link_libraries(grocery_list ${CURSES_LIBRARIES})