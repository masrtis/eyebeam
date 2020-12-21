add_library(math
    components.cpp
    constexpr_math.cpp
    point3.cpp
    random_generator.cpp
    vector3.cpp
)

add_executable(mathtest
    constexpr_math_test.cpp
    point3_test.cpp
    vector3_test.cpp
)

target_link_libraries(mathtest PRIVATE
    math
    GTest::gmock_main # See https://github.com/google/googletest/issues/2157#issuecomment-674361850
)

add_executable(mathbench
    constexpr_math_benchmark.cpp
    point3_benchmark.cpp
    vector3_benchmark.cpp
    math_benchmark_main.cpp
)

target_link_libraries(mathbench PRIVATE
    math
    benchmark::benchmark
    benchmark::benchmark_main
)
