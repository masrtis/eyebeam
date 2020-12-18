cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)

project(eyebeam CXX)

find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

add_subdirectory(math)
add_subdirectory(application)
