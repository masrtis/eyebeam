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

add_library(cxx_base_options INTERFACE)

target_compile_options(cxx_base_options INTERFACE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:> $<$<CXX_COMPILER_ID:MSVC>:/Incremental:NO>
)

target_link_libraries(cxx_base_options INTERFACE
    enable_cxx_17
    enable_warnings
)

add_subdirectory(math)
add_subdirectory(scene)
add_subdirectory(application)
