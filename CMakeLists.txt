cmake_minimum_required(VERSION 3.23)
project(seed)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(SFML)
include_directories("SFML/include")

add_executable(seed src/main.cpp src/Item.cpp src/Item.h src/List.cpp src/List.h src/Menu.cpp src/Menu.h)

target_link_libraries(seed sfml-graphics sfml-system sfml-window)

# copy dll files into debug directory
add_custom_command(TARGET seed POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_BINARY_DIR}/SFML/lib"
        "$<TARGET_FILE_DIR:seed>")

add_custom_command(TARGET seed POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:seed>/assets")
