cmake_minimum_required(VERSION 3.0)
project(c22-fpga)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)  

set(FPGA_PART xcu280-fsvh2892-2L-e)

if (DEFINED ENV{IPREPO_DIR})
   set(IPREPO_DIR $ENV{IPREPO_DIR})
elseif(NOT  IPREPO_DIR)
   set(IPREPO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/iprepo)
endif()

find_package(Vitis REQUIRED)
if (NOT VITIS_HLS_FOUND)
   message(FATAL_ERROR "Vitis HLS not found.")
endif()

add_subdirectory(src)
