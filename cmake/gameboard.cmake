cmake_minimum_required(VERSION 3.0)

project(gameboard)

file(
    GLOB_RECURSE
	gameboard_source
	${CMAKE_CURRENT_SOURCE_DIR}/source/${PROJECT_NAME}/*.c
)

add_library(
    gameboard
    SHARED
    ${gameboard_source}
)

target_include_directories(
    gameboard
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
)
