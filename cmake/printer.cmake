cmake_minimum_required(VERSION 3.0)

project(printer)

file(
    GLOB_RECURSE
	printer_source
	${CMAKE_CURRENT_SOURCE_DIR}/source/${PROJECT_NAME}/*.c
)

add_library(
    printer
    SHARED
    ${printer_source}
)

target_include_directories(
    printer
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameboard
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
)
