cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)

project(eyebeam CXX)

find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

add_library(enable_warnings INTERFACE)

target_compile_options(enable_warnings INTERFACE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall -Werror> $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

add_library(enable_cxx_17 INTERFACE)

target_compile_features(enable_cxx_17 INTERFACE cxx_std_17)

add_subdirectory(math)
add_subdirectory(application)
