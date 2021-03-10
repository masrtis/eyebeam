add_library(math
    angle.cpp
    components.cpp
    constexpr_math.cpp
    intersection_info.cpp
    matrix4.cpp
    normal3.cpp
    point3.cpp
    quadratic_solver.cpp
    random_generator.cpp
    ray3.cpp
    transform.cpp
    vector3.cpp
)

target_link_libraries(math PRIVATE
    enable_cxx_17
    enable_warnings
)

target_include_directories(math PUBLIC
    .
)

add_executable(mathtest
    angle_test.cpp
    constexpr_math_test.cpp
    intersection_info_test.cpp
    matrix4_test.cpp
    normal3_test.cpp
    point3_test.cpp
    quadratic_solver_test.cpp
    ray3_test.cpp
    transform_test.cpp
    vector3_test.cpp
)

target_link_libraries(mathtest PRIVATE
    enable_cxx_17
    enable_warnings
    math
    GTest::gmock_main # See https://github.com/google/googletest/issues/2157#issuecomment-674361850
)

add_executable(mathbench
    math_benchmark_main.cpp
    constexpr_math_benchmark.cpp
    matrix4_benchmark.cpp
    point3_benchmark.cpp
    quadratic_solver_benchmark.cpp
    ray3_benchmark.cpp
    transform_benchmark.cpp
    vector3_benchmark.cpp
)

target_link_libraries(mathbench PRIVATE
    enable_cxx_17
    enable_warnings
    math
    benchmark::benchmark_main
    benchmark::benchmark
)
