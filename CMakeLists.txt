cmake_minimum_required(VERSION 3.20)
project(c_array C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_library(c_dynamic_array array.c array.h)
