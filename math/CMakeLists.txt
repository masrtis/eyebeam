add_library(math
    constexpr_math.cpp
    random_generator.cpp
    vector3.cpp
)

add_executable(mathtest
    constexpr_math_test.cpp
    vector3_test.cpp
)

target_link_libraries(mathtest PRIVATE
    math
    GTest::gmock_main # See https://github.com/google/googletest/issues/2157#issuecomment-674361850
)

add_executable(mathbench
    constexpr_math_benchmark.cpp
    vector3_benchmark.cpp
)

target_link_libraries(mathbench PRIVATE
    math
    benchmark::benchmark
    benchmark::benchmark_main
)
