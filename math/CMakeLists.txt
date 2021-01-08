add_library(math
    components.cpp
    constexpr_math.cpp
    intersection_info.cpp
    normal3.cpp
    point3.cpp
    random_generator.cpp
    ray3.cpp
    vector3.cpp
)

target_link_libraries(math PRIVATE
    enable_cxx_17
    enable_warnings
)

add_executable(mathtest
    constexpr_math_test.cpp
    intersection_info_test.cpp
    normal3_test.cpp
    point3_test.cpp
    ray3_test.cpp
    vector3_test.cpp
)

target_link_libraries(mathtest PRIVATE
    enable_cxx_17
    enable_warnings
    math
    GTest::gmock_main # See https://github.com/google/googletest/issues/2157#issuecomment-674361850
)

add_executable(mathbench
    constexpr_math_benchmark.cpp
    point3_benchmark.cpp
    ray3_benchmark.cpp
    vector3_benchmark.cpp
    math_benchmark_main.cpp
)

target_link_libraries(mathbench PRIVATE
    enable_cxx_17
    enable_warnings
    math
    benchmark::benchmark
    benchmark::benchmark_main
)
