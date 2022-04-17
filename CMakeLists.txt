cmake_minimum_required(VERSION 3.23)
project(grocery_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(grocery_list src/main.cpp src/Item.cpp src/Item.h src/List.cpp src/List.h)