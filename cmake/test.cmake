cmake_minimum_required(VERSION 3.0)

project(test)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/test/include
)

file(
    GLOB_RECURSE
	test_source
	${CMAKE_CURRENT_SOURCE_DIR}/test/source/*.c
)

add_executable(test ${test_source})

target_link_libraries(test PUBLIC gameboard)
target_link_libraries(test PUBLIC printer)
# target_link_libraries(test PUBLIC checker)
