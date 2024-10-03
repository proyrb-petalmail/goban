cmake_minimum_required(VERSION 3.0)

project(main)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(gameboard)
include(printer)
# include(checker)
include(test)
