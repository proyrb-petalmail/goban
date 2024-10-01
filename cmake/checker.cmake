cmake_minimum_required(VERSION 3.0)

project(checker)

file(
    GLOB_RECURSE
	checker_source
	${CMAKE_CURRENT_SOURCE_DIR}/source/${PROJECT_NAME}/*.c
)

add_library(
    checker
    SHARED
    ${checker_source}
)

target_include_directories(
    checker
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
)
